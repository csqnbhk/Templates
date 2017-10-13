#include"Class.h"
int main()
{
	//��ģ���ʹ��
	try
	{
		::Stack<int> int_object;
		::Stack<string> string_object;

		int_object.push(12);
		int_object.push(723);

		string_object.push("����");
		string_object.push("�Ϻ�");

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


	//ģ���ػ�
	cout << "ģ����ػ�" << endl;
	try
	{
		::Stack<std::string> str_object;
		str_object.push("����âЬ��ʤ��");
		str_object.push("һ��������ƽ��");

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
	
	С�᣺

	1.��ģ���Ǿ����������ʵ��ࣺ�����ʵ���У�������һ�����߶�����ͻ�û�б�ָ����

	2.Ϊ��ʹ����ģ�棬����Դ���ĳ������������Ϊģ�������Ȼ�������������ڸ�����
	��ʵ������ģ�档

	3.������ģ����ԣ�ֻ����Щ�����õĳ�Ա�����Żᱻʵ������

	4.�������ĳ���ض������ػ�ģ�档

	5.�������ĳ���ض����;ֲ��ػ���ģ�档

	6.�����Ϊ��ģ���������ȱʡֵ����Щֵ����������֮ǰ��ģ�������
	
	*/

	
}