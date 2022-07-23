#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int cmp(int* e1, int* e2)
{
    return *e2 - *e1;
}
int findMaxConsecutiveOnes(int* nums, int numsSize) {
    int i = 0;
    int count = 0;
    int j = 0;
    int* p = (int*)malloc(numsSize * sizeof(int));
    for (i = 0; i < numsSize; i++)
    {
        if (nums[i] == 1)
        {
            count++;
        }
        else
        {
            p[j++] = count;
            count = 0;
        }
    }
    p[j++] = count;
    qsort(p, j, sizeof(int), cmp);
    int z = p[0];
    return z;
}
int main()
{
    int i = 1;
    sizeof(i++);
    printf("%d\n", i);
    return 0;
}