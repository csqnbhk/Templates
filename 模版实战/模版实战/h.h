/***********************************************************************************
��h.h�ļ����ã�����ģ��ʵս֪ʶ��
author��Demon
Time:2017/9/10

*************************************************************************************/

#pragma once
#include<iostream>
#include<string>
using namespace std;



//2.1.1 �����֯ģ�����,3��ʵ�ַ�����1.����ģ�� 2.��ʾʵ���� 3.����ģ��


//1.����ģ�ͣ���ģ��������Ͷ��嶼��������ģ���ͷ�ļ����棩

//  h.h
//template<typename T>
//T const&max(T const&a,T const&b)
//{
//return a>b?a:b;
//}



//2.��ʾʵ����

//h.h

//���ò���
template<typename T>
T const&max(T const&a, T const&b);

//�����ò���
//template<typename T>
//T const max1(T const a, T const b);


//3.����ģ��

//export 
//template<typename T>
//T const&max(T const&a, T const&b);