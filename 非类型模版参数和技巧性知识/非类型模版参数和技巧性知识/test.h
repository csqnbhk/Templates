/*******************************************************************************

  ��ͷ�ļ�test.h�ļ������ã��ع�һ�·�����ģ������ͼ����Ա��
  author:Demon
  Time:2017/9/9

*******************************************************************************/
#include<iostream>
#include<string>
#include<queue>
using namespace std;

//1.�����͵���ģ�����

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
		cout << "elems�����Ѿ�����" << endl;
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
		cout << "��ǰelemsΪ�յ�����" << endl;
	}
}

template<typename T, int MAXSIZE>
T Stack<T, MAXSIZE>::top()const
{
	if (this->numElems > 0)
		return this->elems[this->numElems - 1];
	else
		cout << "��ǰelemsΪ�յ�����" << endl;
}


template<typename T, int MAXSIZE>
void Stack<T, MAXSIZE>::elems_info()
{
	cout << "elems����Ԫ������" << endl;
	for (int i = 0;i < this->numElems;i++)
	{
		cout << "elems[" << i << "]=" << this->elems[i]<<"   ";
	}
	cout << endl;
}



//2.�����͵ĺ���ģ�����
template<typename T, int add>
T addvalue(T const&temp)
{
	return temp + add;
}


/**************************************************************************************************************
                     ���ɱ�̻���֪ʶ
  
*************************************************************************************************************/

/*

 1.�ؼ��� typename

    1ģ���ڲ��ı�ʶ��������һ�����ͣ���������

	template<typename T>
	class MyClass    
	{
	  typeneme T::SubType*ptr;//SubType�Ƕ�������T�ڲ���һ�����ͣ���ˣ�ptr��һ��ָ��T����SubType���͵�ָ��
	  ...                     //�������typename,��T::SubType*ptr,�ͻ���ΪT::��ĳ�����������SubType�Ǿ�̬��Ա��SubType*ptr,��Ϊ�ǳ˻�
	};

	2.���ڷ���STL�����ĵ�����
	template<typename T>
	void printcoll(T const&coll)
	{
	   typename T::const_iterator pos;        //������
	   typename T::const_iterator end(coll.end());

	   for(pos=coll.begin();pos!=end;pos++)
	   {
	     std::cout<<*pos<<"  ";
	   }

	   std::cout<<std::endl;
	}

*/

//ʹ��this->
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
//		 ::exit1();//����ȫ�ֺ���
//		 exit1();
//		 Base<T>::exit1();
//	 }
//};


//3.ģ���ģ����������ռλ����

//template<typename T,template<typename ELEM> class COUT=std::queue>
//class Stack
//{
//private:
//	CONT<T> elems;//�൱��std::queue<T> elems;
//};
//ģ���ģ������ľ�ȷƥ��
//��������std::queue��ģ���ģ�����CONT����ƥ�䡣��Ϊû�п��ǵ� std::queue��ȱʡ������
//��ȷ��������
//template<typename T,template<typename ELEM��typename ALLOC=std::allocator<ELEM> > class COUT=std::queue>//����ʡ��ALLOC ��д�����û���õ����Ļ�
//class Stack
//{
//private:
//	CONT<T> elems;//�൱��std::queue<T> elems;
//};



//4.ʹ���ַ�����Ϊ����ģ���ʵ��

//1.�������Ͳ���
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
//	::max("apple", "peach");//OK,��ͬ���ͣ�����char const[6];
//	::max("apple"��"tomato");//error,��ͬ���ͣ�char const[6],char const[7]
//  ::max("apple",s);        //error:��ͬ����
//}


//2.���������Ͳ���
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
//	::max("apple", "peach");//OK,��ͬ���ͣ�����char const[6];
//	::max("apple"��"tomato");//OK,char const[6],char const[7],�˻�Ϊ��ͬ�����ͣ�char const*
//  ::max("apple",s);        //error:��ͬ����
//}

//���ڷ��������͵Ĳ������ڲ����Ƶ������л�������鵽ָ����˻�����Ϊ��arry_to_pointer)
#pragma once
