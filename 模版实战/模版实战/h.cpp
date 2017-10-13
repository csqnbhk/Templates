#include"h.h"


//2.显示实例化

//引用参数
template<typename T>
T const&max(T const&a, T const&b)
{
	return a>b ? a : b;
}

template
int const&max<int>(int const&, int const&);

template 
double const&max<double>(double const&, double const&);


////非引用参数
//template<typename T>
//T const max1(T const a, T const b)
//{
//	return a>b ? a : b;
//}
//
//template
//std::string const max1<std::string>(std::string const, std::string const);

//这样子也可以显示实例化
//void call()
//{
//	::max<int>(6, 8);
//}


//3.分离模式（export使用）//暂时不支持
//export
//template<typename T>
//T const&max(T const&a, T const&b)
//{
//	return a>b ? a : b;
//}
