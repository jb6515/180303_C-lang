#include <stdio.h>

#pragma warning(disable: 4996)

void menu(void);
void add_student(void);
void add_course(void);
void add_course_taken(void);
void view(void);

int main(void)
{
	char choice;
	while (1)
	{
		menu();
		choice = getch();
		fflush(stdin);
		switch (choice)
		{
		case'1':	add_student();			break;
		case'2':	add_course();			break;
		case'3':	add_course_taken();		break;
		case'4':	view();					break;
		case'5':	return;
		}


	}

	system("puase");
	return 0;
}


void menu(void)
{
	printf("�޴��� �����ϼ���\n");
	printf("1. �л� ���̺� �ۼ�\n");
	printf("2. ���� ���̺� �ۼ�\n");
	printf("3. ���� ���̺� �ۼ�\n");
	printf("4. �ۼ��� ������ �ҷ�����\n");
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
	}student[4];

	printf("�Է��� �л� ���� �Է��ϼ��� (�ִ� 5��)\n");
	scanf("%d", &j);
	while (getchar() != '\n');


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

	printf("�̸� �ּ� �а�");
	for (i = 0; i < j; i++)
	{
		printf("%s %s %s\n", student[i].stuname, student[i].address, student[i].major);
	}
}


void add_course(void)
{
	return 0;
}
void add_course_taken(void)
{
	return 0;
}
void view(void)
{
	return 0;
}