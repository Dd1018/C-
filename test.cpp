#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
class Widget
{
public:
	Widget()
	{
		cout << "	Widget()" << endl;
	}
	Widget(const Widget& d)
	{
		cout << "Widget(const Widget& d)" << endl;
	}
	~Widget()
	{
		cout << "~Widget()" << endl;
	}
};
Widget f(Widget u)

{
	cout << "--------------------" << endl;
	Widget v(u);

	Widget w = v;
	cout << "--------------------" << endl;
	return w;

}
int main()
{

	Widget x;
	cout << endl;
	Widget y = f(f(x));

	return 0;
}