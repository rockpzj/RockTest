#include <stdio.h>
#include <iostream>
#include <Windows.h>
using namespace std;

class Single {
public:
	Single(void) {
		age = 0;
		name = "无名";
		yanZhi = 0;
	}

	Single(int age, string name, int yanZhi, int salary) {
		this->age= age;
		this->name = name;
		this->yanZhi = yanZhi;
		this->salary = salary;
	}

	int getAge() const {
		return age;
	}

	string getName() const {
		return name; 
	}

	int getYanZhi()  const {
		return yanZhi;
	}

	int getSalary()  const { return salary; }

	bool operator==(const Single &s) {
		return this->require(s) && s.require(*this);
	};
	virtual bool require(const Single &s) const =0;
private:
	int age;
	string name;
	int yanZhi;
	int salary;
};

class Girl : public Single {
public:
	Girl(){}
	Girl(int age, string name, int yanZhi, int salary):Single(age, name, yanZhi, salary){}
	virtual bool require(const Single &s) const;	
};

bool Girl::require(const Single &s) const {
	if (s.getSalary() >= getSalary() * 1.5) {
		return true;
	}
	return false;
}


class Boy: public Single {
public:
	Boy(){}
	Boy(int age, string name, int yanZhi, int salary, int house=0, int car=0)
		:Single(age, name, yanZhi, salary){
			this->house = house;
			this->car = car;
	}
	
	bool hasHouse() { return house > 0; }
	bool hasCar() { return car > 0; }
	bool require(const Single &s) const;
private:
	int salary;
	int house;
	int car;
};

bool Boy::require(const Single &s) const {
	if (s.getYanZhi() >= getYanZhi()) {
		return true;
	}
	return false;
}

int main(void) {
	Girl g1(30, "小芳", 80, 5000);
	Girl g2(32, "小红", 70, 6000);
	Boy b1(35, "小明", 79, 10000);
	Boy b2(32, "小明", 90, 7000);

	if (g1 == b1) {
		cout << "YES";
	} else {
		cout << "No";
	}

	system("pause");
	return 0;
}
