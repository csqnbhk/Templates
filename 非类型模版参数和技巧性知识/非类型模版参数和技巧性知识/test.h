/*******************************************************************************

  该头文件test.h文件的作用：回顾一下非类型模版参数和技巧性编程
  author:Demon
  Time:2017/9/9

*******************************************************************************/
#include<iostream>
#include<string>
#include<queue>
using namespace std;

//1.非类型的类模版参数

template<typename T,int MAXSIZE=5>
class Stack
{
 public:
	 Stack();
	 void push(T const&);
	 void pop();
	 T  top()const;
	 void elems_info();
 private:
	 T elems[MAXSIZE];
	 int numElems;
};

template<typename T,int MAXSIZE>
Stack<T, MAXSIZE>::Stack():numElems(0)
{

}

template<typename T,int MAXSIZE>
void Stack<T, MAXSIZE>::push(T const&temp)
{
	if (this->numElems <MAXSIZE)
	{
		this->elems[this->numElems] = temp;
		this->numElems++;
		return;
	}
	else
	{
		cout << "elems数组已经满了" << endl;
		return;
	}
}

template<typename T,int MAXSIZE>
void Stack<T, MAXSIZE>::pop()
{
	if (this->numElems > 0)
	{
		this->numElems--;
	}
	else
	{
		cout << "当前elems为空的数组" << endl;
	}
}

template<typename T, int MAXSIZE>
T Stack<T, MAXSIZE>::top()const
{
	if (this->numElems > 0)
		return this->elems[this->numElems - 1];
	else
		cout << "当前elems为空的数组" << endl;
}


template<typename T, int MAXSIZE>
void Stack<T, MAXSIZE>::elems_info()
{
	cout << "elems数组元素如下" << endl;
	for (int i = 0;i < this->numElems;i++)
	{
		cout << "elems[" << i << "]=" << this->elems[i]<<"   ";
	}
	cout << endl;
}



//2.非类型的函数模版参数
template<typename T, int add>
T addvalue(T const&temp)
{
	return temp + add;
}


/**************************************************************************************************************
                     技巧编程基础知识
  
*************************************************************************************************************/

/*

 1.关键字 typename

    1模版内部的标识符可以是一个类型，如下例子

	template<typename T>
	class MyClass    
	{
	  typeneme T::SubType*ptr;//SubType是定义与类T内部的一种类型，因此，ptr是一个指向T：：SubType类型的指针
	  ...                     //如果不用typename,有T::SubType*ptr,就会认为T::是某个类的作用域，SubType是静态成员，SubType*ptr,认为是乘积
	};

	2.用于访问STL容器的迭代器
	template<typename T>
	void printcoll(T const&coll)
	{
	   typename T::const_iterator pos;        //重命名
	   typename T::const_iterator end(coll.end());

	   for(pos=coll.begin();pos!=end;pos++)
	   {
	     std::cout<<*pos<<"  ";
	   }

	   std::cout<<std::endl;
	}

*/

//使用this->
//template<typename T>
//class Base
//{
//public:
//	void exit1();
//};
//
//template<typename T>
//void Base<T>::exit1()
//{
//	cout << "Base exit() call" << endl;
//}
//void exit1()
//{
//	cout << "without call exit()" << endl;
//}
//
//template<typename T>
//class Derived:Base<T>
//{
// public:
//	 void foo()
//	 {
//		 ::exit1();//调用全局函数
//		 exit1();
//		 Base<T>::exit1();
//	 }
//};


//3.模版的模版参数（类的占位符）

//template<typename T,template<typename ELEM> class COUT=std::queue>
//class Stack
//{
//private:
//	CONT<T> elems;//相当于std::queue<T> elems;
//};
//模版的模版参数的精确匹配
//发现上面std::queue和模版的模版参数CONT并不匹配。因为没有考虑到 std::queue的缺省参数。
//正确定义如下
//template<typename T,template<typename ELEM，typename ALLOC=std::allocator<ELEM> > class COUT=std::queue>//可以省略ALLOC 不写，如果没有用到它的话
//class Stack
//{
//private:
//	CONT<T> elems;//相当于std::queue<T> elems;
//};



//4.使用字符串作为函数模版的实参

//1.引用类型参数
//template<typename T>
//T &const max(T &const a, T &const b)
//{
//	return a > b ? a : b;
//}
//
//
//int main()
//{
//
//	std::string s;
//	::max("apple", "peach");//OK,相同类型，都是char const[6];
//	::max("apple"，"tomato");//error,不同类型，char const[6],char const[7]
//  ::max("apple",s);        //error:不同类型
//}


//2.非引用类型参数
//template<typename T>
//T const max(T const a, T const b)
//{
//	return a > b ? a : b;
//}
//
//
//int main()
//{
//
//	std::string s;
//	::max("apple", "peach");//OK,相同类型，都是char const[6];
//	::max("apple"，"tomato");//OK,char const[6],char const[7],退化为相同的类型，char const*
//  ::max("apple",s);        //error:不同类型
//}

//对于非引用类型的参数，在参数推导过程中会出现数组到指针的退化，称为（arry_to_pointer)
#pragma once
