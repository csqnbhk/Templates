#include"h.h"


//2.��ʾʵ����

//���ò���
template<typename T>
T const&max(T const&a, T const&b)
{
	return a>b ? a : b;
}

template
int const&max<int>(int const&, int const&);

template 
double const&max<double>(double const&, double const&);


////�����ò���
//template<typename T>
//T const max1(T const a, T const b)
//{
//	return a>b ? a : b;
//}
//
//template
//std::string const max1<std::string>(std::string const, std::string const);

//������Ҳ������ʾʵ����
//void call()
//{
//	::max<int>(6, 8);
//}


//3.����ģʽ��exportʹ�ã�//��ʱ��֧��
//export
//template<typename T>
//T const&max(T const&a, T const&b)
//{
//	return a>b ? a : b;
//}
