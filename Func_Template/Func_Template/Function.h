/*****************************************************************************************************

  ��Function.h�ļ������ã����Լ򵥵ĺ���ģ�������
  author��Demon
  Time:2017/9/9
******************************************************************************************************/
#include<iostream>
using namespace std;


//1.����ģ��

template<typename T>
T const&max(T const &a,T const&b)
{
	return a > b ? a : b;
}


//2.���غ���ģ��
template<typename T>
T const const&max(T const&a, T const&b, T const&c)
{
	return (a > b ? a : b) > c ? (a > b ? a : b) : c;
}
#pragma once


