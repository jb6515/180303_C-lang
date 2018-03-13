#include <stdio.h>

#pragma warning(disable: 4996)
int size = 0;
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

	system("pause");
	return 0;
}


void menu(void)
{
	printf("�޴��� �����ϼ���\n");
	printf("1. �л� ���̺� �ۼ�\n");
	printf("2. ���� ���̺� �ۼ�\n");
	printf("3. ���� ���̺� �ۼ�\n");
	printf("4. �ۼ��� ������ �ҷ�����\n");
	printf("5. ����\n");
}

void add_student(void)
{
	int i = 0;
	struct student_info
	{
		char stuname[10];
		char address[20];
		char major[10];
	};
	typedef struct student_info data;

	data student[4];

	system("cls");

	printf("�Է��� �л� ���� �Է��ϼ��� (�ִ� 5��)\n");
	scanf("%d", &size);
	fflush(stdin);


	for (i = 0; i < size; i++)
	{
		printf("%d��° �л� �̸��� �Է� : ", i + 1);
		scanf("%s", student[i].stuname);
		printf("%d��° �л� �ּҸ� �Է� : ", i + 1);
		scanf("%s", student[i].address);
		printf("%d��° �л� �а��� �Է� : ", i + 1);
		scanf("%s", student[i].major);
		fflush(stdin);
	}

	printf("�̸� �ּ� �а�\n");
	for (i = 0; i < size; i++)
	{
		printf("%s %s %s\n", student[i].stuname, student[i].address, student[i].major);
	}
	FILE *fp = fopen("lsd_student.dat", "wb");
	if (fp == NULL)
		return;
	fwrite(&size, sizeof(int), 1, fp);
	fwrite(&student, sizeof(data), size, fp);
	fclose(fp);

	system("pause");
}


void add_course(void)
{
	
}
void add_course_taken(void)
{
	
}
void view(void)
{
	int i = 0;
	struct student_info
	{
		char stuname[10];
		char address[20];
		char major[10];
	};
	typedef struct student_info data;

	data student[4];

	FILE *fp;

	fp = fopen("lsd_student.dat", "rb");
	if (fp == NULL)
		return;
	fread(&size, sizeof(int), 1, fp);
	fread(student, sizeof(data), size, fp);


	printf("�̸� �ּ� �а�\n");
	for (i = 0; i < size; i++)
	{
		printf("%s %s %s\n", student[i].stuname, student[i].address, student[i].major);
	}

}