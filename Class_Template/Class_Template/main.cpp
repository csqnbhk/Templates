#include"Class.h"
int main()
{
	//类模版的使用
	try
	{
		::Stack<int> int_object;
		::Stack<string> string_object;

		int_object.push(12);
		int_object.push(723);

		string_object.push("北京");
		string_object.push("上海");

		cout << "object.size()=" << int_object.size() << endl;
		cout << "object.top()=" << int_object.top() << endl;

		cout << "string_object.size()=" << string_object.size() << endl;
		cout << "string_object.top()=" << string_object.top() << endl;
	}
	catch (std::exception const&ex)
	{
		std::cerr << "Exception:" << ex.what() <<endl;
		return EXIT_FAILURE;
	}


	//模版特化
	cout << "模版的特化" << endl;
	try
	{
		::Stack<std::string> str_object;
		str_object.push("竹杖芒鞋轻胜马");
		str_object.push("一蓑烟雨任平生");

		cout << "str_object.top()=" << str_object.top() << endl;
		str_object.pop();
		str_object.pop();
		str_object.top();
	}
	catch (std::exception const&ex)
	{
		std::cerr << "Exception:" << ex.what() << endl;
		return EXIT_FAILURE;
	}


	/*
	
	小结：

	1.类模板是具有如下性质的类：在类的实现中，可以有一个或者多个类型还没有被指定。

	2.为了使用类模版，你可以传入某个具体类型作为模版参数；然后编译器将会基于该类型
	来实例化类模版。

	3.对于类模板而言，只有那些被调用的成员函数才会被实例化。

	4.你可以用某种特定类型特化模版。

	5.你可以用某种特定类型局部特化类模版。

	6.你可以为类模版参数定义缺省值，这些值还可以引用之前的模版参数。
	
	*/

	
}