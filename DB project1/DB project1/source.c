#include <stdio.h>

#pragma warning(disable: 4996)
int menu(void)
{
	printf("�޴��� �����ϼ���");

}

void add_student(void)
{
	int i = 0;
	int j = 0;
	struct student_info
	{
		char stuname[10];
		char address[20];
		char major[10];
	}student[5];

	for (i = 0; i < j; i++)
	{
		printf("%d��° �л� �̸��� �Է� : ", i + 1);
		scanf("%s", student[i].stuname);
		printf("%d��° �л� �ּҸ� �Է� : ", i + 1);
		scanf("%s", student[i].address);
		printf("%d��° �л� �а��� �Է� : ", i + 1);
		scanf("%s", student[i].major);
		while (getchar() != '\n');
	}

	for (i = j; i < 1; i++)
	{
		printf("%s %s %s", student[i].stuname, student[i].address, student[i].major);
	}
}


int main(void)
{
	int i;






	getchar();
	return 0;
}
