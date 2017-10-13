/***********************************************************************************
该h.h文件作用：测试模版实战知识点
author：Demon
Time:2017/9/10

*************************************************************************************/

#pragma once
#include<iostream>
#include<string>
using namespace std;



//2.1.1 如何组织模版代码,3种实现方法。1.包含模型 2.显示实例化 3.分离模型


//1.包含模型（把模版的声明和定义都包含声明模版的头文件里面）

//  h.h
//template<typename T>
//T const&max(T const&a,T const&b)
//{
//return a>b?a:b;
//}



//2.显示实例化

//h.h

//引用参数
template<typename T>
T const&max(T const&a, T const&b);

//非引用参数
//template<typename T>
//T const max1(T const a, T const b);


//3.分离模版

//export 
//template<typename T>
//T const&max(T const&a, T const&b);