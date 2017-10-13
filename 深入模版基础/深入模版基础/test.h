/*****************************************************************************************

   该test文件的作用："回顾一下深入模版的一些基础."
   author:Demon
   Time:2017/9/16

******************************************************************************************/
#pragma once

//8.1 参数化声明
/*

  8.1.1 虚成员函数

        ：成员函数模版不能声明为虚函数。这是一种需要强制执行的限制，因为虚函数调用机制
		  的普遍实现都使用了一个固定表，每个虚函数都对应表的一个入口。然而，成员函数模版
		  的实例化个数，要等到整个程序都翻译完毕才能够确定，这就和表的大小（是固定的）发
		  生冲突。因此，如果将来要支持虚成员函数模版。将需要一种全新的C++编译器和链接器的
		  机制。

  8.1.2  模版的链接

         ：每个模版都必须有一个名字，而且在它所属的作用域下，该名字必须是唯一的，除非函数模
		   版可以被重载。特别是，类模版不能和另一个实体共享一个名称，这一点和class类型是不同
		   的。

		   int C;

		   class C;//正确:类名称和非类名称位于不同的名字空间（namespace）。


		   int X;
		   
		   template<typename T>
		   class X;  //错误：和变量X冲突。


		   struct S;
		   
		   template<typename T>
		   class S; //错误，和struct S 冲突。

		   小结：模版名字是具有链接的，但是它们不能具有C 链接。但是我们在大多数情况下所说的是标准的
		         链接，同时在存在非标准的链接，它们可以具有一个依赖于实现的含义（然而，我们还没有发
				 现有用于支持非标准模版名字链接的编译器的实现）。


				 extern "C++" template<typename T>
                 void normal();           //这是缺省情况，上面的链接规范可以不写


				 extern "C" template<typename T>
				 void invalid();          //错误的，模版不能具有C链接


				 extern "Xroma" template<typename T>
				 void  xroma_link();     //非标准的，但是某些编译器将来可能支持与Xroma语言的连接兼容性

		    注意： 模版通常具有外部链接。唯一的例外就是前面有 static 修饰符的名字空间作用域下的函数模版。

			     template<typename T>
				 void external();        //作为一个声明，引用位于其它的文件，具有相同的名称的实体；即引用位于
				                           其它文件的external（）函数模版，也称“前置声明”。

                 template<typename T>
				 static void external()  //与其它文件中具有相同名称的模版没有关系，即不是外部链接。


  8.1.3  基本模版
  /*
      如果模版声明得是一个普通声明，就称它的声明是一个基本模版。
	  这类模版的声明是指：没有在模版名称后面添加一对尖括号（和里面实参）的声明。

	  template<typename T>
	  class Box;             //正确：基本模版


	  template<typename T>
	  Class Box<T>;          //错误：不是基本模版

	  template<typename T>
	  void translate(T*);    //正确：基本模版


	  template<typename T>
	  void translate<T>(T*); //错误：不是基本模版

	  注意    ：当声明局部特化的时候，声明就是非基本模版。
	  特别注意：函数模版必须是基本模版。

 */

//8.2 模版参数
/*

  8.2.1  类型参数（使用最多）
         
	     :类型参数是通过关键字typename或者class引入的：它们两者几乎相同。关键字后面
		  必须是一个简单的标识符，后面用逗号来隔开下一个参数声明，等号（==）代表接下
          来的是缺省模版实参，一个封闭的尖括号（>)表示参数化句子结束。

  8.2.2  非类型参数

          ：非类型参数表示的是：在编译期或者链接期可以确定的常值。这些常值的类型，必须
		    是下面的一种。

			1.整型或者枚举类型。

			2.指针类型（包含普通对象的指针类型，函数指针类型，指向成员的指针类型)

			3.引用类型（指向对象或者指向函数的引用都是允许的）。

			注意1：所有其他的类型现今都不允许作为非类型参数使用（但是将来很可能会增加浮点数类型）。

			注意2：非类型参数的声明和变量的声明很相似，但是它们不能具有static，mutable等修饰符；
			       只能具有const，volatile限定符。但是如果这两个限定符是最外层的参数类型，编译器
				   就会忽略它们。

				   temlpate<int const length> //这里的const没有用，被编译器忽略掉了。
				   class Buffer;             
			
			注意3：非类型参数只能是右值，不能被取址，也不能被赋值。

  8.2.3 模版的模版参数

        ：模版的模版参数是代表“类的占位符”，它的声明和类模板的声明很类似。但是不能使用关键字 struct，union。

		template<template<typename X> class C>  //正确
		void f(C<int>*p);              

		template<template<typename X> struct C> //错误
		void f(C<int>*p);

		template<template<typename X> unionnC) //错误
        void f(C<int>*p);

		注意1：模版的模版参数可以具备缺省模版实参。显然，只有调用没有指定该参数的情况下，才会应用到该缺省模版实参。
		       template<template<typename T,typename A=MyAllocator> class Container>
			   class Adaptation
			   { 
			     Container<int> storage;//隐式等同于 Contatiner<int,MyAllocator> storgae;
				 ...
			   };
        注意2：对于模版的模版参数而言，它的参数名称只能被自身其它参数得声明使用。   
		        template<template<typename T,T*> class Buf>
				class Lexer
				{
				  static char storage[5];
				  Buf<char,&Lexer<Buf>::storage[0]> buf;  //正确，被自身其它参数使用
				};

				template<template<typename T> class List>
				class Node
				{
                  static T*storage;   //错误，不能被其它参数使用。
				};

              注意3：模版的模版参数的参数名称一般不会在后面被用到，因此，该参数也经常被省略
			         不写，即没有命名。

					 template<template<typename,typename=MyAllocator> class Container>
					 class Adaptation
					 {
					   Container<int> storage; //隐式等于 Container<int,MyAllocator> storgae;
					 };



  8.2.4  缺省模版参数
         
		     注意1：现今，只有类模板声明才能具有缺省的模版实参。
			 注意2：缺省实参不能依赖自身的参数，但是可以依赖前面的参数。

			 特别注意：与缺省的函数调用参数约束一样，对于任何一个模版参数，只有在之后的模版参数
			           都提供了缺省值的情况下，才能具有缺省模版实参。后面的缺省值通常是在同个模版
					   声明中提供的，但是也可以在前面的模版声明中提供的。

					   template<typename T1,typename T2,typename T3,typename T4=char>
					   class C;

					   template<typename T1,typename T2=int,typename T3,typename T4>;
					   class C;  //错误，T3还没有提供缺省实参，前面的不能提供


					   template<typename T1,typename T2,typename T3=int,typename T4>
					   class C;  //正确，前面模版提供T4缺省实参，故T3可以提供。其实就是类似下面

					   template<<typename T1,typename T2,typename T3=int,typename T4=char>
					   class C;

           注意3：缺省实参不能重复声明。
		      template<typename T=int>
			  class C;

			  template<typename T=int>
			  class C;//错误，重复声明缺省实参
     
*/


//8.3 模版实参

/*
   
   8.3.1 函数模版实参
           
		1.对于函数模版实参，可以显示指定，或者借助模版的使用方式对它们进行实参推导。
		2.对于不参与推导的模版实参，最好把这些实参对应的参数放在模版参数列表的开始处，
		  从而可以显示指定这些参数，其它参数可以进行推导。
		
		注意：由于函数可以被重载，所以对于函数模版而言，显示提供所有的实参并不足以
		      标识每一个函数。

   8.3.2 类型实参
     
       1.模版的类型实参是一些用来指定模版类型参数的值。我们平时使用的大多数类型都可以
	     被用作模版的类型实参。两种情况例外：局部类和局部枚举(换句话说，指在函数定义
		 内部声明的类型类型）不能作为模版的实参类型。

	  2。未命名的class类型或者未命名的枚举类型不能作为模版的类型实参。（然而，通过typedef 声明
	     给出的未命名类和枚举是可以作为moan类型实参的）。

		特别注意：尽管有些类型可以作为模版实参，但前提是该类型替换模版参数之后获得的构造必须是有效的。

		template<typename T>
		void clear(T p)
		{
		    *p=0;
		}
		int main()
		{
		  int a;
		  clear(a); //错误，int类型不支持单目运算符 *
		}

   8.3.3 非类型实参
         
		 注意：
		 template<char  const*str>
		 class Message;

		 extern char const hello[]="hello word";//如果不使用关键字 extern,上面的 const数组就具有内部链接。（不能作为非类型实参）

		 Message<hello> hello_msg;

   8.3.4 模版的模版实参
     
	     注意：必须是一个类模板，它本身具有参数，该参数必须精确地匹配它“所替换的模版的模版参数”。

	   
   8.3.5 实参的等价性
       
	   1.对于类型实参，typedef名称并不会对等价性产生影响。

*/


//8.4 友元

/*

  8.4.1 友元函数
       （友元函数名称后面有尖括号，其实就是特化）
	    template<typename T1,typename T2>
		void combine(T1,T2);

		class Mixer
		{

		   friend void combine<>(int&,int&);//特化，T1=int&，T2=int&

		   friend void combine<char>(char*,int);//错误，不能匹配

		   friend void ccombine<>(long,long){...)//错误，不可这样子定义
		}






	  （友元函数名称后面没有尖括号）
	  1.如果名称不是受限的（就是说，没有包含“::”域运算符），那么该名称一定不能是一个模版实例。
	    如果在友元声明的地方，还看不到所匹配的非模版函数（即普通函数），那么这个友元声明是该函数
		的首次声明。于是，该声明可以是定义。

	  2.如果名称是受限的，那么该名称必须引用一个在此之前声明的函数或者函数模版。在匹配过程中，匹配
	   的函数要优先于匹配的函数模版。但是，这样的友元声明不能是定义。

  8.4.2 友元模版
     
	 1.和普通友元声明一样，只有在友元模版声明的是一个非受限的函数名称，并且后面没有紧跟尖括号的情况下，
	    该友元模版声明才可以成为定义。

	 2.友元模版声明只是基本模版和基本模版的成员。当进行这些声明之后，与该基本模版相对应的模版局部特化和
	   显示特化都会自动地看成友元。

*/