#define _CRT_SECURE_NO_WARNINGS
#include"contact.h"
void menu()
{
	printf("**************************************\n");
	printf("**     1. add         2. del        **\n");
	printf("**     3. search      4.modify      **\n");
	printf("**     5. show        6.sort        **\n");
	printf("**     0. exit                      **\n");
	printf("**************************************\n");
}
int main()
{

	int input;
	struct Con infor;
	Itni(&infor);
	do
	{
		menu();
		printf("ÇëÑ¡Ôñ>:");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			Add(&infor);
			break;
		case 2:
			Del(&infor);
			break;
		case 3:
			Search(&infor);
			break;
		case 4:
			Modify(&infor);
			break;
		case 5:
			Show(&infor);
			break;
		case 6:
			Sort(&infor);
			break;
		case 0:
			Save(&infor);
			Destory(&infor);
			printf("ÍË³ö\n");
			break;
		}
	} while (input);
	return 0;
}