#include <stdio.h>

#pragma warning(disable: 4996)

void menu(void);
void add_student(void);


int main(void)
{
	int choice;

	switch (choice)
	{
	case'1':	add_student(); break;
	case'2':	add
	}




	getchar();
	return 0;
}


void menu(void)
{
	printf("�޴��� �����ϼ���\n");
	printf("1. �л� ���̺� �ۼ�\n");
	printf("2. ���� ���̺� �ۼ�\n");
	printf("3. ���� ���̺� �ۼ�\n");
	printf("4. �ۼ��� ������ �ҷ�����");
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