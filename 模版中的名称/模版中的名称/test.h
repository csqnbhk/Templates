/************************************************************************************

    该test头文件的作用：回顾一下模版中的名称。
	author:Demon
	Time:2017/9/16

************************************************************************************/
#pragma once

//9.1 名称的分类

/*

  1.如果一个名称使用域解析运算符（::)或者何成员访问运算符（即 .或->)来显示表明
   它所属的作用域，就称这些名称为受限名称（this->count为一个受限名称，count不是）。

  2.如果一个名称依赖于模版参数，那么称它为依赖型名称。例如T为一个模版参数，std::vector<T>::iterator
   就是一个依赖型名称。但是，如果T是一个已知(例如 int，那么std::vector<T>::iterator就不是依赖型名称。

*/

//9.2 名称的查找

/*
 
  // 9.2.1 Argument_Dependent_Lookup(ADL)

   1.受限的名称查找是在一个受限的作用域内部进行的，该作用域由一个限定的构造
     所决定。如果该作用域是一个类，那么查找的范围可以达到它的基类；但是不会
	 考虑它得外围作用域。

	  int x;
	   
	  class B
	  {
	    public:
	    int i; 
	  };

	  class D:public B
	  {

	  };
	  void f(D*pd)
	  {
	    pd->i=3;//可以找到B::i
		D::x=2; //错误：不能找到外围作用域的::x
	  }

    2.非受限的名称查找就刚好相反，它可以(由内到外）在所有外围类中逐层进行查找。
	（但在某个类内部定义的成员函数定义中，它会先查找该类和基类的作用域，然后才
	  查找外围类的作用域），该查找就是普通查找。

	  extern int count;//(1)

	  int lookup_example(int count)//(2)
	  {
	    if(count<0)
		{
		 int count=1;//(3)
		 lookup_example(count);//非受限的count引用（3）
		}
		return count+::count; //第一个count引用（2），第二个count引用（1）
	  }

    3.对于非受限名称查找，新的查找机制ADL出现。（就是非受限的名称查找有时候可以依赖于参数的查找，ADL只能用于非受限名称查找）

	4.假如普通查找可以找到，那么就不会用ADL查找。

	5.如果名称后面的括号里有（一个或者多个）实参表达式，那么ADL将会查找这些是实参的 associated class(关联类）和associated namespace(关联名字空间）。
	  可以这么认为，与给定类型直接相关的所有namespace和class.例如，如果某一类型是指向class X的指针，那么它的associated class和associated namespace会包含
	  X和X所属得class和namespace。

	6.对于给定的类型，对于由associated class和associated namespace所组成的集合是准确定义。
	/*
	   1.对于基本类型，该集合为空集。

	   2.对于指针和数组类型，该集合是所引用类型（例如对于指针而言，它的所引用类型就是“指针所指向对象”的类型）的associated class 和associated namespace。

	   3.对于枚举可惜，associated namespace指的是枚举声明所在的namespace。对于类成员，associated class指的是它所在的类。

	   4.对于class类型（包含联合类型）,associated class包括：该class本身，它的外围类。直接基类，间接基类。associated namespace集合是每个associated class所在
	    的namespace。如果这个类是一个模版实例化体，那么还包含：模版类型实参本身的类型，声明模版的模版实参所在的class和namespace。

	   5.对于函数类型，该集合包括所有参数类型和返回类型的associated class和associated namespace。

	   6.对于类的成员指针类型，除了包括成员相关的associated class和associated namespace，该集合还包含与X相关的associated class和associated namespace。


	   特别注意：ADL会在所有的associated class和associated namespace中依次查找，就好像依次直接使用这些名字空间进行限定一样。唯一例外的是：
	             “它会忽略掉using-directives(using指示符）”。例如

 #include<iostream>
namespace X
{
	template<typename T>
	void f(T)
	{
		std::cout << "X::f(T) called" << std::endl;
	}
};



namespace N
{
	using namespace X;//ADL查找时候忽略掉该语句
	enum E { e1 };
	void f(E)
	{
		std::cout << "N::f(N::E) called" << std::endl;
	}
};
void f(int)
{
	std::cout << "::f(int) called" << std::endl;
}
int main()
{
	::f(N::e1);
	f(N::e1);
}

	*/


  // 9.2.2 友元名称的插入
     /*
	   1.通常而言，友元声明在外围类作用域是不可见的。

	   2.如果友元函数所在的类属于ADL的关联类集合，那么在这个外围类是可以找到该友元声明的。

	   template<typename T>
	   class C
	   {
	     
		 friend void f();
		 friend void f(C<T> const&);
		 
	   };
	   void g(C<int>*p)
	   {

	      f();   //没有关联类或者名字空间，没有任何参数，不能利用ADL查找。无效的调用
		  f(*p); //可以
	   }

	 
	 */


  //9.2.3 插入式类名称

/*

    1.在类本身的作用域中插入该类的名称，就称该名称为插入式类名称。

	2.插入式类模板名称。
	template<template<typename> class TT>
	class X
	{
	   
	};

	template<typename T>
	class C
	{
	    C*a;          //正确，相当于 C<T> *a;
		C<void> b;    //正确
		X<C> c;       //错误：后面没有跟模版实参列表的C不被看做模版
		X<::C> d;     //错误：<:是[的另一种标记(经过测试也可以通过编译）
		X< ::C> e;    //正确：在<和::之间的空格是必须的

	}；



*/


//9.3 解析模版

/*
  
  //9.3.1 非模版中的上下文相关性


  //9.3.2 依赖型类型名称
          
		  1.通常情况下依赖型受限名称并不会代表一个类型，除非在该名称前面有关键字typename。
		    对于类型名称，如果不加上关键字typename，那么在类型替换的时候就不会被看成类型
			名称，从而程序也是无效的。

		  2.应该知道typename这种用法和前面的用于表示模版类型参数的用法不同；在这里不能使用
		    class来等价替换typename。

		 3.当类型名称有以下性质就应该在其前面加上typename。
		 /*
		   1.名称出现在一个模版中。

		   2.名称是受限的。

		   3.名称不是用于指定基类继承列表中，也不是位于构造函数的成员初始化列表中。

		   4.名称依赖于模版参数。

		    注意：只要前面3个条件满足情况下就可以使用typename作为前缀。

		 */

  //9.3.3 依赖型模版名称
          
          /*
		  
		  1.要使得编译器知道所引用的依赖型名称是一个模版，那么就要在该名称前面加上template关键字。
		   否则，编译器将假设它不是一个模版名称。
		 	  
		  */
  
  //9.3.4 using_declaration中的依赖型名称

      /*
	    1.using-declaration会从两个位置（即类和名字空间）引入名称。如果引入的是名字空间
		那么就不会涉及到上下文问题，因为不存在名字空间。
		
		2.从类中引入名称的能力有限：只能把基类中的名称引入到派生类中来。就好像该名称是在
		  派生类中声明的一样。


		 class A
		 {
		    public:
			void f(){
			  std::cout<<"A::f() called"<<std::endl;
			}
		 };
	     
		 class B :private A
		 {
		   public:
		   using A::f；//这里是f,不是f().本来是有继承不能使用该函数，但是使用这个语句就可以。
		 };
	 
	  */
 
  //9.3.5 ADL和显示模版实参
    /*
	
	    namespace N
		{
		   class X
		   {
		     
		   };
			template<int i>
			void select(X*);
		};
	   void g(N::X*xp)
	   {
	     select<3>(xp);//错误，没有ADL.编译器在不知<3>是一个模版参数的情况下，是无法判断xp是一个
		                 函数调用实参来的。会被解析成 （select<3)>(xp),毫无意义。
	   }
	
	*/





//9.4 派生和类模板

/*

   //9.4.1 非依赖型基类

          一个非依赖型基类是指：无须知道模版实参就可以完全确定类型的基类。也就是说：
		  基类名称是用非依赖型名称来表示。

		  template<typename X>
		  class Base
		  {
		     public:
			 int basefield;
			 typedef int T;
		  };

		  class D::public Base<Base<void> >//实际上不是模版
		  {
		   public:
		   void f()
		   {
		    basefield=3;
		   }
		  };


		  template<typename T>
		  class D1:public Base<double>  //非依赖继承基类
		  {

		    public:
			void f()
			{
			  basefield=7;          //正常访问继承成员

			}
			T strange;             //特别注意，该T是Base<double>::T,不是模版参数
		  };
		  
		  特别注意：对于模版中的非依赖型基类而言，如果在它的派生类中查找一个非受限名称，
		            那么就会先查找这个非依赖型的基类，然后才查找模版参数列表。


   //9.4.2  依赖型基类
         template<typename X>
		  class Base
		  {
		     public:
			 int basefield;
			 typedef int T;
		  };

		template<typename T>
		class DD:public Base<T>
		{
		   public:
		   void f()
		   {
		     basefield=8;
		   }

		};
		template<>
		class Base<bool>
		{
		  public:
		   enum
		   { 
		    basefield=21
		   };
		};
		void g(DD<bool>&d)
		{
		 d.f();
		}

*/



