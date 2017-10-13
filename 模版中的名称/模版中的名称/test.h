/************************************************************************************

    ��testͷ�ļ������ã��ع�һ��ģ���е����ơ�
	author:Demon
	Time:2017/9/16

************************************************************************************/
#pragma once

//9.1 ���Ƶķ���

/*

  1.���һ������ʹ��������������::)���ߺγ�Ա������������� .��->)����ʾ����
   �������������򣬾ͳ���Щ����Ϊ�������ƣ�this->countΪһ���������ƣ�count���ǣ���

  2.���һ������������ģ���������ô����Ϊ���������ơ�����TΪһ��ģ�������std::vector<T>::iterator
   ����һ�����������ơ����ǣ����T��һ����֪(���� int����ôstd::vector<T>::iterator�Ͳ������������ơ�

*/

//9.2 ���ƵĲ���

/*
 
  // 9.2.1 Argument_Dependent_Lookup(ADL)

   1.���޵����Ʋ�������һ�����޵��������ڲ����еģ�����������һ���޶��Ĺ���
     ���������������������һ���࣬��ô���ҵķ�Χ���Դﵽ���Ļ��ࣻ���ǲ���
	 ����������Χ������

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
	    pd->i=3;//�����ҵ�B::i
		D::x=2; //���󣺲����ҵ���Χ�������::x
	  }

    2.�����޵����Ʋ��Ҿ͸պ��෴��������(���ڵ��⣩��������Χ���������в��ҡ�
	������ĳ�����ڲ�����ĳ�Ա���������У������Ȳ��Ҹ���ͻ����������Ȼ���
	  ������Χ��������򣩣��ò��Ҿ�����ͨ���ҡ�

	  extern int count;//(1)

	  int lookup_example(int count)//(2)
	  {
	    if(count<0)
		{
		 int count=1;//(3)
		 lookup_example(count);//�����޵�count���ã�3��
		}
		return count+::count; //��һ��count���ã�2�����ڶ���count���ã�1��
	  }

    3.���ڷ��������Ʋ��ң��µĲ��һ���ADL���֡������Ƿ����޵����Ʋ�����ʱ����������ڲ����Ĳ��ң�ADLֻ�����ڷ��������Ʋ��ң�

	4.������ͨ���ҿ����ҵ�����ô�Ͳ�����ADL���ҡ�

	5.������ƺ�����������У�һ�����߶����ʵ�α��ʽ����ôADL���������Щ��ʵ�ε� associated class(�����ࣩ��associated namespace(�������ֿռ䣩��
	  ������ô��Ϊ�����������ֱ����ص�����namespace��class.���磬���ĳһ������ָ��class X��ָ�룬��ô����associated class��associated namespace�����
	  X��X������class��namespace��

	6.���ڸ��������ͣ�������associated class��associated namespace����ɵļ�����׼ȷ���塣
	/*
	   1.���ڻ������ͣ��ü���Ϊ�ռ���

	   2.����ָ����������ͣ��ü��������������ͣ��������ָ����ԣ��������������;��ǡ�ָ����ָ����󡱵����ͣ���associated class ��associated namespace��

	   3.����ö�ٿ�ϧ��associated namespaceָ����ö���������ڵ�namespace���������Ա��associated classָ���������ڵ��ࡣ

	   4.����class���ͣ������������ͣ�,associated class��������class����������Χ�ࡣֱ�ӻ��࣬��ӻ��ࡣassociated namespace������ÿ��associated class����
	    ��namespace������������һ��ģ��ʵ�����壬��ô��������ģ������ʵ�α�������ͣ�����ģ���ģ��ʵ�����ڵ�class��namespace��

	   5.���ں������ͣ��ü��ϰ������в������ͺͷ������͵�associated class��associated namespace��

	   6.������ĳ�Աָ�����ͣ����˰�����Ա��ص�associated class��associated namespace���ü��ϻ�������X��ص�associated class��associated namespace��


	   �ر�ע�⣺ADL�������е�associated class��associated namespace�����β��ң��ͺ�������ֱ��ʹ����Щ���ֿռ�����޶�һ����Ψһ������ǣ�
	             ��������Ե�using-directives(usingָʾ������������

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
	using namespace X;//ADL����ʱ����Ե������
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


  // 9.2.2 ��Ԫ���ƵĲ���
     /*
	   1.ͨ�����ԣ���Ԫ��������Χ���������ǲ��ɼ��ġ�

	   2.�����Ԫ�������ڵ�������ADL�Ĺ����༯�ϣ���ô�������Χ���ǿ����ҵ�����Ԫ�����ġ�

	   template<typename T>
	   class C
	   {
	     
		 friend void f();
		 friend void f(C<T> const&);
		 
	   };
	   void g(C<int>*p)
	   {

	      f();   //û�й�����������ֿռ䣬û���κβ�������������ADL���ҡ���Ч�ĵ���
		  f(*p); //����
	   }

	 
	 */


  //9.2.3 ����ʽ������

/*

    1.���౾����������в����������ƣ��ͳƸ�����Ϊ����ʽ�����ơ�

	2.����ʽ��ģ�����ơ�
	template<template<typename> class TT>
	class X
	{
	   
	};

	template<typename T>
	class C
	{
	    C*a;          //��ȷ���൱�� C<T> *a;
		C<void> b;    //��ȷ
		X<C> c;       //���󣺺���û�и�ģ��ʵ���б��C��������ģ��
		X<::C> d;     //����<:��[����һ�ֱ��(��������Ҳ����ͨ�����룩
		X< ::C> e;    //��ȷ����<��::֮��Ŀո��Ǳ����

	}��



*/


//9.3 ����ģ��

/*
  
  //9.3.1 ��ģ���е������������


  //9.3.2 ��������������
          
		  1.ͨ��������������������Ʋ��������һ�����ͣ������ڸ�����ǰ���йؼ���typename��
		    �����������ƣ���������Ϲؼ���typename����ô�������滻��ʱ��Ͳ��ᱻ��������
			���ƣ��Ӷ�����Ҳ����Ч�ġ�

		  2.Ӧ��֪��typename�����÷���ǰ������ڱ�ʾģ�����Ͳ������÷���ͬ�������ﲻ��ʹ��
		    class���ȼ��滻typename��

		 3.�������������������ʾ�Ӧ������ǰ�����typename��
		 /*
		   1.���Ƴ�����һ��ģ���С�

		   2.���������޵ġ�

		   3.���Ʋ�������ָ������̳��б��У�Ҳ����λ�ڹ��캯���ĳ�Ա��ʼ���б��С�

		   4.����������ģ�������

		    ע�⣺ֻҪǰ��3��������������¾Ϳ���ʹ��typename��Ϊǰ׺��

		 */

  //9.3.3 ������ģ������
          
          /*
		  
		  1.Ҫʹ�ñ�����֪�������õ�������������һ��ģ�棬��ô��Ҫ�ڸ�����ǰ�����template�ؼ��֡�
		   ���򣬱�����������������һ��ģ�����ơ�
		 	  
		  */
  
  //9.3.4 using_declaration�е�����������

      /*
	    1.using-declaration�������λ�ã���������ֿռ䣩�������ơ��������������ֿռ�
		��ô�Ͳ����漰�����������⣬��Ϊ���������ֿռ䡣
		
		2.�������������Ƶ��������ޣ�ֻ�ܰѻ����е��������뵽�������������ͺ������������
		  ��������������һ����


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
		   using A::f��//������f,����f().�������м̳в���ʹ�øú���������ʹ��������Ϳ��ԡ�
		 };
	 
	  */
 
  //9.3.5 ADL����ʾģ��ʵ��
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
	     select<3>(xp);//����û��ADL.�������ڲ�֪<3>��һ��ģ�����������£����޷��ж�xp��һ��
		                 ��������ʵ�����ġ��ᱻ������ ��select<3)>(xp),�������塣
	   }
	
	*/





//9.4 ��������ģ��

/*

   //9.4.1 �������ͻ���

          һ���������ͻ�����ָ������֪��ģ��ʵ�ξͿ�����ȫȷ�����͵Ļ��ࡣҲ����˵��
		  �����������÷���������������ʾ��

		  template<typename X>
		  class Base
		  {
		     public:
			 int basefield;
			 typedef int T;
		  };

		  class D::public Base<Base<void> >//ʵ���ϲ���ģ��
		  {
		   public:
		   void f()
		   {
		    basefield=3;
		   }
		  };


		  template<typename T>
		  class D1:public Base<double>  //�������̳л���
		  {

		    public:
			void f()
			{
			  basefield=7;          //�������ʼ̳г�Ա

			}
			T strange;             //�ر�ע�⣬��T��Base<double>::T,����ģ�����
		  };
		  
		  �ر�ע�⣺����ģ���еķ������ͻ�����ԣ�����������������в���һ�����������ƣ�
		            ��ô�ͻ��Ȳ�������������͵Ļ��࣬Ȼ��Ų���ģ������б�


   //9.4.2  �����ͻ���
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



