#include<iostream>
template<typename T>
void f(T) throw(T)
{
	std::cout << "f() called" << std::endl;
}

//下面就是显示实例化体
template  void f<int>(int) throw(int);
template  void f<float>(float) throw(float);
template void f<long>(long) throw(long);
template void f<char>(char) throw(char);

int main()
{
	
	f(23);
	f<int>(24);
	
	return 0;
}

