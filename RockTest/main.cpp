#include "WateWave.h"

void main()
{
	//WateWave girl("bg.jpg");
	WateWave girl("bg2.jpg", 960, 705);
	girl.init();

	while (true)
	{
		girl.updateFrame();
		Sleep(1);
	}
}

// WateWave.h
#pragma once
#include <graphics.h>     
#include <stdio.h>
#include <iostream>

#define PIC_HEIGHT 600
#define PIC_WIDTH  800
#define INDEX(x,y) ((y) * width + (x))

class WateWave {
public:
	WateWave(const char *img, int w = PIC_WIDTH, int h = PIC_HEIGHT);
	void updateFrame();
	void init();
	~WateWave();

private:
	short *buf1; //当前时刻的波幅数组
	short *buf2; //下一时刻的波幅数组

	int width;
	int height;

	IMAGE src_img;      // 原位图		
	IMAGE dest_img;     // (PIC_WIDTH, PIC_HEIGHT);	// 处理后显示的位图
	DWORD *img_ptr1;	// 原图片片内存指针
	DWORD *img_ptr2;	// 处理后显示的位图内存指针

	void calcCentWave(); //计算当前时刻落水点的波幅
	void calcAllWave(); //计算所有点的波幅
	void calImage();

	// 鼠标模拟投石头
	// 参数说明：
	// (x, y): 鼠标坐标
	// stonesize: “石头”的大小,(石头的半径）
	// stoneweight: 投“石头”的力度
	// Ps: 如果产生错误，一般就是数组越界所致，请酌情调整“石头”的大小和“石头”的力度
	void putStone(int x, int y, int stonesize, int stoneweight);
};

#include "WateWave.h"

WateWave::WateWave(const char *img, int w, int h) {
	width = w;
	height = h;

	buf1 = new short[width * height];
	buf2 = new short[width * height];
	// 初始化波幅数组
	memset(buf1, 0, (width * height) * sizeof(short));
	memset(buf2, 0, (width * height) * sizeof(short));

	loadimage(&src_img, img);
	dest_img = IMAGE(width, height); //此时还是空图片

	// 获得内存指针
	img_ptr1 = GetImageBuffer(&src_img);
	img_ptr2 = GetImageBuffer(&dest_img);
}

void WateWave::calcCentWave() {
	if (MouseHit())
	{
		MOUSEMSG msg = GetMouseMsg();
		if (msg.uMsg == WM_MOUSEMOVE)
		{
			putStone(msg.x, msg.y, 3, 256);
		}
		else if (msg.uMsg == WM_LBUTTONDOWN)
		{
			putStone(msg.x, msg.y, 3, 2560);
		}
		FlushMouseMsgBuffer();
	}
}

void WateWave::updateFrame() {
	calcCentWave(); //计算中心区域（投石位置）的波幅
	calcAllWave(); //计算所有点的波幅
	calImage();
	putimage(0, 0, &dest_img); //显示计算后的图像
}


// 鼠标模拟投石头
// 参数说明：
// (x, y): 鼠标坐标
// stonesize: “石头”的大小,(石头的半径）
// stoneweight: 投“石头”的力度
// Ps: 如果产生错误，一般就是数组越界所致，请调整“石头”的大小和“石头”的力度
void WateWave::putStone(int x, int y, int stonesize, int stoneweight)
{
	// 突破边界不处理
	if ((x >= width - stonesize) ||
		(x < stonesize) ||
		(y >= height - stonesize) ||
		(y < stonesize))
		return;

	for (int posx = x - stonesize; posx<x + stonesize; posx++)
	{
		for (int posy = y - stonesize; posy<y + stonesize; posy++)
		{
			if ((posx - x)*(posx - x) + (posy - y)*(posy - y) < stonesize*stonesize)
			{
				//buf1[PIC_WIDTH*posy + posx] += stoneweight;
				buf1[INDEX(posx, posy)] += stoneweight;
			}
		}
	}
}


// 计算出下一个时刻所有点的波幅
void WateWave::calcAllWave()
{
	for (int i = width; i < height*(width - 1); i++)
	{
		// 公式：X0'= (X1+X2+X3+X4) / 2 - X0
		buf2[i] = ((buf1[i - width] + buf1[i + width] + buf1[i - 1] + buf1[i + 1]) >> 1) - buf2[i];

		// 波能衰减
		//buf2[i] -= buf2[i] >> 5;
		buf2[i] -= buf2[i] / 32;
	}

	short *ptmp = buf1;
	buf1 = buf2;
	buf2 = ptmp;
}

// 根据各点的波幅，计算各点的图像
void WateWave::calImage() {
	int i = 0;
	for (int y = 0; y < height; y++)
	{
		for (int x = 0; x < width; x++)
		{
			short data = 1024 - buf1[i];

			// 偏移
			int a = ((x - width / 2) * data / 1024) + width / 2;
			int b = ((y - height / 2) * data / 1024) + height / 2;

			// 边界处理
			if (a >= width) {
				a = width - 1;
			}
			else if (a < 0) {
				a = 0;
			}
			if (b >= height) {
				b = height - 1;
			}
			else if (b < 0) {
				b = 0;
			}

			// 处理偏移 
			//img_ptr2[i] = img_ptr1[a + (b * PIC_WIDTH)];
			img_ptr2[INDEX(x, y)] = img_ptr1[INDEX(a, b)];

			i++;
		}
	}
}

void WateWave::init() {
	initgraph(width, height);
}

WateWave::~WateWave() {
	closegraph();
	delete buf1;
	delete buf2;
}

