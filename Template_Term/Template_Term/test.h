/************************************************************************************************
        ��test.h�ļ������ã��ع�һ��ģ������֪ʶ��
		author��Demon
		Time:2017/9/10
*********************************************************************************************/
#pragma once

//1.��ģ�廹��ģ����
/*
   1.�����ͣ���c++�У��ࣨclass,struct)������(union)������Ϊ�����͡�
   2.�ࣺ�ùؼ���class����struct����������͡�

*/

//2.ʵ�������ػ�

/*
  1.��ʾ�ػ�
  template<typename T>
  class MyClass
  {
   ...

  };

  template<>
  class MyClass<std::string>
  {
  };

  2.�ֲ��ػ�
  template<typename T1,typename T2>
  class MyClass
  {
  };

  template<typename  T>
  class MyClass<int,T>            //�ֲ��ػ�T2
  {
  };

*/



//3.�����Ͷ���
/*

class C{}; //��C�Ķ��壨��������

void f(int p)//����f()�Ķ��壨��������
{
}

extern int a;//����a������

extern int b=1;//һ����ʼ����ʹ֮��Ϊv�Ķ���

int w;//ǰ��û��extern��ȫ�ֱ�����������ͬʱҲ�Ƕ���

*/

//4.һ������ԭ��
/*

 1.��ȫ�ֱ����뾲̬���ݳ�Աһ���������������У������������ͳ�Ա����ֻ�ܱ�����һ�Ρ�

 2.�����ͣ�class��struct��union�������������ͳ�Ա������ÿ�����뵥Ԫ�����ֻ�ܶ���һ�Ρ�������ڶ�����뵥Ԫ��
   �������еĶ��嶼��������ȵġ�

 3.һ�����뵥Ԫ��Ԥ����һ��Դ�ļ����õĽ����Ҳ����˵����������#includeָʾ�����Ȱ�����ͷ�ļ��������������ݡ�

 4.������ʵ�壺�������������߷�������Ա������ȫ�ֱ������߾�̬��Ա��������������ģ���������Щʵ�塣

*/

//5.ģ�������ģ��ʵ��


/*

   ע����仰������ģ��ʵ��ʹ֮��Ϊģ�������

   1.ģ�������λ��ģ���������߶����ڲ����ؼ���template�������оٵ����ơ�

   2��ģ��ʵ�Σ������滻ģ�������������


   һ��ԭ��ģ��ʵ�α�����һ�������ڱ�����ȷ����ģ��ʵ�����ֵ��


   template<typename T>
   class MyClass
   {

      public:
	  ArrayInClass<T,12>  connects;
   };

   ģ������Ǳ�����ʵ�壨��һ��TΪģ�����)�����Կ�����������ģ��ʵ�Σ��ڶ���TΪģ��ʵ�Σ���

*/