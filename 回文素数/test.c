#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
long long func(long long t) {
    int a = t;
    while (a > 9) {
        a /= 10;
        t = (t * 10 + a % 10);
    }
    return t;
}
int isPrime(long long num)
{
    int tmp = sqrt(num);
    for (int i = 2; i <= tmp; i++)
        if (num % i == 0)
            return 0;
    return 1;
}
int main()
{
    long long t;
    scanf("%lld", &t);
    if (isPrime(func(t)))
    {
        printf("prime");
    }
    else {
        printf("noprime");
    }
    return 0;
}