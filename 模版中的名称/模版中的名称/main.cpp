#include<iostream>
//template<typename T>
//class Base
//{
//public:
//	int basefield;
//	typedef int T;
//};
//template<typename T>
//class DD :public Base<T>
//{
//public:	
//	void f()
//	{
//		basefield= 0;
//	}
//
//};
//template<>
//class Base<bool>
//{
//public:
//	enum
//	{
//		basefield =21//�������ϣ���Ϊthis->basefield=21û�ã���ΪBase<T>::basefield=21Ҳû�á�
//	};
//};
//void g(DD<bool>&d)
//{
//	d.f();
//}


template<template<typename> class TT>
class X
{

};

template<typename T>
class C
{
	C*a;          //��ȷ���൱�� C<T> *a;
	C<void> b;    //��ȷ
	//X<C> c;       //���󣺺���û�и�ģ��ʵ���б��C��������ģ��
	X<::C> d;     //����<:��[����һ�ֱ�ǣ���������Ҳ����ͨ�����룩
	X< ::C> e;    //��ȷ����<��::֮��Ŀո��Ǳ����

};

int main()
{
	
	return 0;
}