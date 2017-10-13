/**********************************************************************************


     该test.h头文件的作用：回顾一下模版的"实例化".
	 author:Demon
	 Time:2017/9/16

************************************************************************************/
#pragma once
/*

  10.1 On-Demand 实例化
      
	  1.on-demand 实例化有时也被称为隐式实例化或者自动实例化（C++编译器遇到模版特化的使用时，它会利用
	    所给的实参替换对应的模版参数，从而产生该模版的特化。这个过程是编译器自动进行的，不需要客户端的
		代码来引导。）

		template<typename T>
		class C;

		C<int> *p=0;      //正确，定义一个指针只要使用声明，并不需要C<int>的完整定义

		template<typename T>
		class C
		{
		  public:
		  void f();       //只是声明一下
		};
		void g(C<int>&c)  //定义一个引用只要使用声明
		{
		   c.f();         //此处需要C::f()的完整定义
		}


		注意：如果候选函数的参数是class类型，那么该类型所对应的类必须是可见的。

		     template<typename T>
			 class C
			 {
			    public：
				C(int);
			 };
			 void f(C<double> const&)//（1）
			 {
			   std::cout<<"f(C<double> const&) called"<<std::endl;
			 }
			 void f(int)
			 {
			   std::cout<<"f(int) called"<<std::endl;
			 }
			 int main()
			 {
			    f(42);
			 }
			 注意：
			 编译器依然实例化（1）处声明，来检查产生的实例能否成为该调用的一个
			 候选函数（之所以这么做，是因为在这个例子中，单参数的构造函数可以将
			 42隐式转型为C<double>类型的右值）。此时，再实例化C<double>的实例化
			 就会引起一个错误。

  10.2 延时实例化

  10.3  C++的实例化模型
       
	    10.3.1 两阶段查找
		      1.第一阶段发生在模版的解析。
			  2.第二阶段发生在模版的实例化。

		10.3.2 POI
		      
			  1.对于指向非类型特化的引用，C++把它的POI定义在“包含这个引用的定义
			   或者声明之后的最近名字空间域"中。

			 2.对于指向产生于模版的类实例的引用，它的POI只能定义在“包含这个实例
			  引用的定义或者声明之前的最近名字空间域"中。


		10.3.3 包含模型和分离模型

		10.3.4 跨翻译单元查找

		10.3.5 例子

  10.4 几种实现方案
        
		10.4.1 贪婪实例化

		10.4.2 询问实例化

		10.4.3 迭代实例化

  10.5 显示实例化
    
	  template<typename T>
	  void f(T) throw(T)
	  {

	  }
    
	 //下面就是显示实例化体
	 template void f<int>(int) throw(int);
	 template void f<float>(float) throw(float);
	 template void f<long>(float) throw(long);
	 template void f<char>(char) throw(char）；

*/