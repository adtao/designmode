#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

class Mystring {
public:
	//���캯��
	Mystring(const char* str) {
		if (str != nullptr) {
			mydata = new char[strlen(str) + 1];
			strcpy(mydata, str);
		}
		else {
			mydata = new char[1];
			*mydata = '/0';
		}
	}
	//��������
	Mystring(const Mystring& s) {
		mydata = new char[strlen(s.mydata) + 1];
		strcpy(mydata, s.mydata);
	}
	//������ֵ����
	Mystring& operator=(const Mystring& s) {
		if (this == &s) {//��ַ��ͬ->�������Ҹ�ֵ
			return *this;
		}
		delete[] mydata;
		mydata = new char[strlen(s.mydata) + 1];
		strcpy(mydata, s.mydata);
		return *this;
	}
	~Mystring() {
		delete[] mydata;
		mydata = nullptr;
	}

private:
	char* mydata;
};

template<template T>
class mySharedPtr {
public:
	//���캯��
	mySharedPtr(T* p = NULL);//Ĭ�ϲ���
	//��������
	~mySharedPtr();
	
	//�������캯��
	mySharedPtr(const mySharedPtr<T>& other);
	//��ֵ��������
	mySharedPtr<T>& operator=(const mySharedPtr<T>& other);
private:
	T* m_ptr;
	unsigned int* m_count;
};

template<template T>
mySharedPtr<T>::mySharedPtr(T * p)
{
	m_ptr = p;
	m_count = unsigned int(0);
	++(*m_count);
	cout << "constructor1" << endl;

}
template<template T>
mySharedPtr<T>::~mySharedPtr() {
	--(*m_count);
	if ((*m_count) == 0) {
		delete[] m_ptr;
		m_ptr = NULL;
		delete[] m_count;
		m_count = NULL;
		cout << "destruction success" << endl;
	}
}

template<template T>
mySharedPtr<T>::mySharedPtr(const mySharedPtr<T>& other) {
	m_ptr = other.m_ptr;
	m_count = other.m_count;
	*m_count++;
	cout<<"construction 2"
}

template<template T>
mySharedPtr<T>& mySharedPtr<T>::operator=(const mySharedPtr<T>& other) {
	//��ֹ����ֵ������ǰ����--�����������ԴʱҪ��ǰ�����Ҳ����
	++(*other.m_count);
	--(*m_count);
	if (*m_count == 0) {
		delete m_ptr;
		m_ptr = NULL;
		delete m_count;
		m_count = NULL;
	}
	m_ptr = other.m_ptr;
	m_count = other.m_count;
	return *this;
}