/*****************************************************************************

  该test.h头文件的作用：回顾一下"模版实参的演绎"
  author:Demon
  Time:2017/9/16

******************************************************************************/
#pragma once
/*

  11.1 演绎的过程
   
       1.一定要记住，每个实参-参数对的分析都是独立的，因此，如果最后所得的结论发生矛盾，
	     那么演绎过程将失败。

		#include<iostream>
        template<typename T>
        void f(T){}

        template<typename T>
        void g(T&) {}

       double x[20];
       int const seven = 7;

       void test()
      { 

	    f(x);     //非引用参数，T为double*
	    g(x);     //引用参数，  T为double[20]
	    f(seven); //非引用参数，T为int
	    g(seven); //引用参数，  T为int const
	    f(7);     //非引用参数，T为int
	  //g(7);     //引用参数，T为int。无法将int转化为int&



  11.2 演绎的上下文

  11.3 特殊的演绎

  11.4 可接受的实参转型

  11.5 类模版参数
      
	  1.模版实参演绎只能应用于函数模版和成员函数模版，是不能应用于类模版的。

	  2.特别注意：对于类模版，不能根据实参来演绎类模版参数。

	   template<typename T>
	   class S
	   {
	      public:
		  S(T b):a(b)
		  {
		  }
		  private:
		  T a;
	   };
      S x(12);//错误：不能从构造函数的调用实参12来演绎类模版参数T
  11.6 缺省调用实参

       1.和普通函数一样，在函数模版中也可以指定缺省的调用实参。
	   template<typename T>
	   void f(T* a,T const &b=T())
	   {
	       *a=b;
	   }

	   2.缺省调用实参可以依赖于模版参数。但是，只有在没有提供显示实参的情况下，
	     才会实例化这种依赖型的缺省实参。
		 template<typename T>
		 void f(T* a,T const &b=T())
		 {
		    *a=b;
		 }
		 class S
		 {
		    public:
			S(int,int);
		 };
		 S s(0,0);
		 int main()
		 {
		    f(&s,S(7,42));
		 }

	   3.对于缺省实参而言，既不是依赖类型，也不能用于演绎的模版实参。这意味着
	     下面的C++程序无效。

		 template<typename T>
		 void f(T x=66)
		 {
		    
		 }
		 int main（）
		 {
		    f<int>();
			f();  //错误：不能根据缺省实参42来演绎T
		 }
  11.7 Barton-Nackman方法


*/
