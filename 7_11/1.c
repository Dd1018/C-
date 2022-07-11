#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>
#include<stddef.h>
int main()
{
	unsigned char puc[4];
	struct tagPIM
	{
		unsigned char ucPim1;
		unsigned char ucData0 : 1;
		unsigned char ucData1 : 2;
		unsigned char ucData2 : 3;
	}*pstPimData;
	pstPimData = (struct tagPIM*)puc;
	memset(puc, 0, 4);
	pstPimData->ucPim1 = 2;
	pstPimData->ucData0 = 3;
	pstPimData->ucData1 = 4;
	pstPimData->ucData2 = 5;
	printf("%02x %02x %02x %02x\n", puc[0], puc[1], puc[2], puc[3]);
	return 0;
}