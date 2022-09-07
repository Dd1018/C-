#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;
void test_string1()
{
	string str("hello world !");
	for (size_t i = 0; i < str.size(); )
	{
		if (str[i] == ' ')
		{
			str.erase(i, 1);
			str.insert(i, "%20");
			i +=3;
		}
		else
			++i;
	}
	cout << str << endl;
	string newstr;
	for (int i = 0; i < str.size(); i++)
	{
		if (str[i] != ' ')
		{
			newstr += str[i];
		}
		else
			newstr += "%20";
	}
	cout << newstr << endl;
}
void test_string2()
{
	string filename("test.cpp");
	FILE* fp = fopen(filename.c_str(), "r");
	cout << filename << endl;
	cout << filename.c_str() << endl;
	char ch = fgetc(fp);
	while (ch != EOF)
	{
		cout << ch;
		ch = fgetc(fp);
	}
}
void test_string3()
{
	string filename("test.cpp");
	FILE* fp = fopen(filename.c_str(), "r");
	cout << filename << endl;
	cout << filename.c_str() << endl;
	filename += '\0';
	filename += "string.cpp";
	cout << filename << endl;
	cout << filename.c_str() << endl;
}
void test_string4()
{
	string filename("test.cpp.zip");
	size_t pos = filename.rfind('.');
	if (pos != string::npos)
	{
		string suff = filename.substr(pos,filename.size()-pos);
		cout<< suff << endl;
	}
	
}
void test_string5()
{
	string ur1 = "https://cplusplus.com/reference/string/string/rfind/";
	size_t pos = ur1.find("://");
	string ur2 = ur1.substr(0, pos-1);
	cout << ur2 << endl;
	size_t pos1 = ur1.find('/', pos + 3);
	string ur3 = ur1.substr(pos + 3, pos1 - pos-3);
	cout << ur3 << endl;
	string ur4 = ur1.substr(pos1+1);
	cout << ur4 << endl;
}
void test_string6()
{
	char a[10];
	scanf("%s", &a);
	cout << a << endl;
}
void test_string7()
{
	int val;
	double dval;
	cin >> val >> dval;
	string str = to_string(val);
	cout << str<<endl;
	string str1 = to_string(dval);
	cout << str1 << endl;
	str = "999";
	str1 = "999.999";
	val = stoi(str);
	dval = stod(str1);
}
//int main()
//{
//	test_string7();
//	return 0;
//}
int main()

{

	string strText = "How are you?";

	string strSeparator = " ";

	string strResult;

	int size_pos = 0;

	int size_prev_pos = 0;

	while ((size_pos = strText.find_first_of(strSeparator, size_pos)) != string::npos)

	{

		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);

		cout << strResult << " ";

		size_prev_pos = ++size_pos;

	}

	if (size_prev_pos != strText.size())

	{

		strResult = strText.substr(size_prev_pos, size_pos - size_prev_pos);

		cout << strResult << " ";

	}

	cout << endl;

	return 0;

}