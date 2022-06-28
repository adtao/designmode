#pragma once
#include<iostream>
#include<string>
using namespace std;

//���Ʒ��
class abstructSportsProduct {
public:
	abstructSportsProduct() {};
	virtual ~abstructSportsProduct() {};//������
	virtual void printName() = 0;//���麯������
	virtual void play() {};

};
//�����Ʒ��
class Basketball :public abstructSportsProduct {//�����̳�
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
	// ����ʵ�ַ���
	void printName() {
		printf("momo get Football\n");
	}
	void play() {
		printf("momo is playing Football\n\n");
	}
};

// �����Ʒ��Volleyball
class Volleyball :public abstructSportsProduct
{
public:
	Volleyball() {
		printName();
		play();
	}
	// ����ʵ�ַ���
	void printName() {
		printf("momo get Volleyball\n");
	}
	void play() {
		printf("momo is playing Volleyball\n\n");
	}
};
//���幤����͹�������
class factory {
public:
	std::shared_ptr<abstructSportsProduct> getSportName(string name) {
		std::shared_ptr<abstructSportsProduct> pro;//����ָ�� Ĭ�ϳ�ʼ��������ָ���б�����һ����ָ��
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
