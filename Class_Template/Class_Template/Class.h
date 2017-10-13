/************************************************************************

  该头文件Class.h作用：简单回顾一下类模版的使用
  author：Demon
  Time:2017/9/9
************************************************************************/
#include<iostream>
#include<vector>
#include<stdexcept>
#include<string>
using namespace std;
template<class T>//类模版的声明，typename可以用class替代
class Stack
{

public:
	~Stack()throw();//这样子声明是说明，这个函数不抛出异常
	void push(T const&);
	void pop();
	T top() const;
	//内联函数，对于类模版的任何成员函数，都可以把它实现为内联函数
	bool empty() const
	{
		return this->elems.empty();
	}
    int size();

private:
	std::vector<T> elems;
};

//类模版成员函数的实现
template<typename T>
void Stack<T>::push(T const&push_elem)
{
	this->elems.push_back(push_elem);

}

template<typename T>
void Stack<T>::pop() 

{
	if (!this->empty())
	{
		this->elems.pop_back();
	}
	else
	{
		throw std::out_of_range("Stack()::pop():empty stack");
	}
}


template<typename T>
T Stack<T>::top()const
{
	if (!this->empty())
	{
		return this->elems.back();
	}
	else
	{
		throw std::out_of_range("Stack()::top():empty stack");
	}
}

template<typename T>
int Stack<T>::size()
{
	return this->elems.size();
}

template<typename T>
Stack<T>::~Stack()throw()
{
	
}
/*******************************************************************************************************************************/
//1.类模板的特化,(进行类模版的特化时，每个成员函数必须重新定义为普通函数，原来模版函数中的每个T也相应地进行特化的类型取代。
template<>
class Stack<std::string>
{
public:

	void push(std::string const&);
	void pop();
	int size();
	std::string top()const;
	bool empty()const
	{
		return this->elems.empty();
	}


private:

	std::vector<std::string> elems;
};

void Stack<std::string>::push(std::string const&push_string)
{
	this->elems.push_back(push_string);
}

void Stack<std::string>::pop()
{
	if (!this->empty())
	{
		this->elems.pop_back();
		return;
	}
	else
	{
		throw std::out_of_range("Stack<std::string>,pop():empty");
	}
}
int Stack<std::string>:: size()
{
	return this->elems.size();

}
std::string Stack<std::string>::top()const
{
	if (!this->empty())
	{
		return this->elems.back();
	}
	else
	{
		throw std::out_of_range("Stack<std::string>,top():empty");
	}
}

/****************************************************************************************************************************************/

//////2.类模板的局部特化
/*
 1.两个模版参数具有相同的类型
 template<typenaem T>
 class MyClass<T,T>
 {
 };

 2.第二个参数为指定类型，例如 int类型
  template<typename T>
  class MyClass<T,int>
  {
  };

 3.两个参数都是指针类型
 template<typename T1,typename T2>
 Class MyClass<T1*,T2*>
 {
 };
 */

///////3.缺省模版实参
/*

 对于类模版，可以为模版参数定义缺省值；这些值就是缺省的模版实参；而且，他们还可以引用之前的模版参数。

 例如
 template<typename T,typename Cont=std::vector<T>>//T引用之前的模版参数
 class Stack
 {
    public:

	void push(T const&);
	private:
	Connt elems;//相等于 std::vector<T> elems;

 };

 //类成员函数就成这样子定义
 template<typename T,typename Count>    //每个成员函数的定义都必须具有这两个参数
 void Stack<T,Count>::push(T const&temp)
 {
    
 }

*/





#pragma once

