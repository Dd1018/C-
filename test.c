#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
//
//int main()
//{
//    double n = 0.00;
//    int m = 0;
//
//    while (~scanf("%lf %d", &n, &m))
//    {
//        double sum = 0.00;
//        for (int i = 0; i < m; i++)
//        {
//            sum += n;
//            n = sqrt(n);
//        }
//        printf("%.2lf\n", sum);
//    }
//
//    return 0;
//}
//int main()
//{
//	char c = 'A';
//	if ('0' <= c <= '9') printf("YES");
//	else printf("NO");
//	return 0;
//}
//#include<stdio.h>
//int main()
//{
//	int n = 1001;
//	int ans = 0;
//	for (int i = 1; i <= n; ++i)
//	{
//		ans ^= i % 3;
//	}
//	printf("%d", ans);
//	return 0;
//}
int fun(unsigned int x)
{
	int n = 0;
	while (x + 1)
	{
		n++;
		x = x | (x + 1);
	} return n;
}
int main()
{
	fun(2014);
	return 0;
}