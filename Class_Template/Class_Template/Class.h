/************************************************************************

  ��ͷ�ļ�Class.h���ã��򵥻ع�һ����ģ���ʹ��
  author��Demon
  Time:2017/9/9
************************************************************************/
#include<iostream>
#include<vector>
#include<stdexcept>
#include<string>
using namespace std;
template<class T>//��ģ���������typename������class���
class Stack
{

public:
	~Stack()throw();//������������˵��������������׳��쳣
	void push(T const&);
	void pop();
	T top() const;
	//����������������ģ����κγ�Ա�����������԰���ʵ��Ϊ��������
	bool empty() const
	{
		return this->elems.empty();
	}
    int size();

private:
	std::vector<T> elems;
};

//��ģ���Ա������ʵ��
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
//1.��ģ����ػ�,(������ģ����ػ�ʱ��ÿ����Ա�����������¶���Ϊ��ͨ������ԭ��ģ�溯���е�ÿ��TҲ��Ӧ�ؽ����ػ�������ȡ����
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

//////2.��ģ��ľֲ��ػ�
/*
 1.����ģ�����������ͬ������
 template<typenaem T>
 class MyClass<T,T>
 {
 };

 2.�ڶ�������Ϊָ�����ͣ����� int����
  template<typename T>
  class MyClass<T,int>
  {
  };

 3.������������ָ������
 template<typename T1,typename T2>
 Class MyClass<T1*,T2*>
 {
 };
 */

///////3.ȱʡģ��ʵ��
/*

 ������ģ�棬����Ϊģ���������ȱʡֵ����Щֵ����ȱʡ��ģ��ʵ�Σ����ң����ǻ���������֮ǰ��ģ�������

 ����
 template<typename T,typename Cont=std::vector<T>>//T����֮ǰ��ģ�����
 class Stack
 {
    public:

	void push(T const&);
	private:
	Connt elems;//����� std::vector<T> elems;

 };

 //���Ա�����ͳ������Ӷ���
 template<typename T,typename Count>    //ÿ����Ա�����Ķ��嶼�����������������
 void Stack<T,Count>::push(T const&temp)
 {
    
 }

*/





#pragma once

