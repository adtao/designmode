#pragma once
#include<iostream>
#include<string>
using namespace std;

//虚产品类
class abstructSportsProduct {
public:
	abstructSportsProduct() {};
	virtual ~abstructSportsProduct() {};//虚析构
	virtual void printName() = 0;//纯虚函数定义
	virtual void play() {};

};
//具体产品类
class Basketball :public abstructSportsProduct {//公共继承
public:
	Basketball() {
		printName();
		play();
	};
	~Basketball() {};
	void printName() {
		cout << "momo get basketball" << endl;
	}
	void play() {
		cout << "momo is playing basketball" << endl;
	}
};
class Football :public abstructSportsProduct
{
public:
	Football() {
		printName();
		play();
	}
	// 具体实现方法
	void printName() {
		printf("momo get Football\n");
	}
	void play() {
		printf("momo is playing Football\n\n");
	}
};

// 具体产品类Volleyball
class Volleyball :public abstructSportsProduct
{
public:
	Volleyball() {
		printName();
		play();
	}
	// 具体实现方法
	void printName() {
		printf("momo get Volleyball\n");
	}
	void play() {
		printf("momo is playing Volleyball\n\n");
	}
};
//定义工厂类和工厂方法
class factory {
public:
	std::shared_ptr<abstructSportsProduct> getSportName(string name) {
		std::shared_ptr<abstructSportsProduct> pro;//共享指针 默认初始化的智能指针中保存着一个空指针
		if (name == "basketball") {
			pro = shared_ptr<abstructSportsProduct>(new Basketball);
		}
		else if (name == "football") {
			pro = shared_ptr<abstructSportsProduct>(new Football);
		}
		else if (name == "volleyball") {
			pro = shared_ptr<abstructSportsProduct>(new Volleyball);
		}
		return pro;
	}
};
