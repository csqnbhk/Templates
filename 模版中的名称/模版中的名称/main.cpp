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
//		basefield =21//按照书上，改为this->basefield=21没用，改为Base<T>::basefield=21也没用。
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
	C*a;          //正确，相当于 C<T> *a;
	C<void> b;    //正确
	//X<C> c;       //错误：后面没有跟模版实参列表的C不被看做模版
	X<::C> d;     //错误：<:是[的另一种标记（经过测试也可以通过编译）
	X< ::C> e;    //正确：在<和::之间的空格是必须的

};

int main()
{
	
	return 0;
}