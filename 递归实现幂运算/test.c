#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
double fun(int a, int b)
{
	if (b == 0)
		return 1;
	else if (b > 0)
		return fun(a, b - 1) * a;
	else if (b < 0)
		return 1.0/fun(a, -b);
}
int main()
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%lf", fun(a, b));
	return 0;
}


//
//double Pow(int n, int k)
//{
//	if (k > 0)
//		return n * Pow(n, k - 1);
//	else if (k == 0)
//		return 1;
//	else
//		return 1.0 / Pow(n, -k);
//}
//
//int main()
//{
//	int n = 0;
//	int k = 0;
//	scanf("%d%d", &n, &k);
//	double ret = Pow(n, k);
//	
//	printf("%lf\n", ret);
//
//	return 0;
//}
