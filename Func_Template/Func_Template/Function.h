/*****************************************************************************************************

  该Function.h文件的作用：测试简单的函数模版的特性
  author：Demon
  Time:2017/9/9
******************************************************************************************************/
#include<iostream>
using namespace std;


//1.定义模版

template<typename T>
T const&max(T const &a,T const&b)
{
	return a > b ? a : b;
}


//2.重载函数模版
template<typename T>
T const const&max(T const&a, T const&b, T const&c)
{
	return (a > b ? a : b) > c ? (a > b ? a : b) : c;
}
#pragma once


