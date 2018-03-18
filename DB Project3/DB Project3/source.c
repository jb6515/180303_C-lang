#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)
int size = 0; // ����ü ������ŭ ���Ͽ� ����ϱ� ���� ����, �������� ù �κп� �����
int size1 = 0;
int size2 = 0;
int size3 = 0;

typedef struct {
	char stuid[20];
	char stuname[20];
	char major[20];
	char address[40];
} str_s;
typedef struct {
	char cou_no[20];
	char cou_name[30];
	char professor[20];
} str_c;
typedef struct {
	char stuid[20];
	char cou_no[20];
	char grade[5];
} str_ct;

str_s* po_s;
str_c* po_c;
str_ct* po_ct;

po_s = NULL;
po_c = NULL;
po_ct = NULL;

void menu(void); // �޴��� �ҷ����� �Լ�
void add_student(void); // �л����̺��� �ۼ��ϴ� �Լ�
void add_course(void); // ���������̺��� �ۼ��ϴ� �Լ�
void add_course_taken(void); // �������̺��� �ۼ��ϴ� �Լ�
void view(void); // �ۼ��� ���̺���� �ҷ��ͼ� ������ִ� �Լ�
void file_save(void);
void file_load(void);

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

	free(po_s);
	free(po_c);
	free(po_ct);

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

	str_s student[5]; // ����ü �迭 ����

	system("cls"); // ȭ�� ����

	printf("�Է��� �л� ���� �Է��ϼ��� (�ִ� 5��)\n");
	scanf("%d", &size); // �������� ���� �Է¹���
	fflush(stdin);
	for (i = 0; i < size; i++)
	{
		printf("%d��° �л��� �й��� �Է� : ", i + 1);
		scanf("%s", student[i].stuid);
		printf("%d��° �л��� �̸��� �Է� : ", i + 1);
		scanf("%s", student[i].stuname);
		printf("%d��° �л��� �а��� �Է� : ", i + 1);
		scanf("%s", student[i].major);
		printf("%d��° �л��� �ּҸ� �Է� : ", i + 1);
		scanf("%s", student[i].address);
		fflush(stdin);
	}

	FILE *fp = fopen("lsd_student.dat", "wb");
	if (fp == NULL)
		return;
	fwrite(&size, sizeof(int), 1, fp); // �������� ���� ���� ù�κп� ���
	fwrite(student, sizeof(str_s), size, fp); // ������ ������ ���


	fclose(fp); // ���� �ݱ�

	system("pause");
}


void add_course(void)
{
	int i = 0;

	str_c course[5]; // ����ü �迭 ����

	system("cls"); // ȭ�� ����

	printf("�Է��� ���� ���� �Է��ϼ��� (�ִ� 5��)\n");
	scanf("%d", &size);
	fflush(stdin);


	for (i = 0; i < size; i++)
	{
		printf("%d��° ������ �������ȣ�� �Է� : ", i + 1);
		scanf("%s", course[i].cou_no);
		printf("%d��° ������ �̸��� �Է� : ", i + 1);
		scanf("%s", course[i].cou_name);
		printf("%d��° ������ ������ �Է� : ", i + 1);
		scanf("%s", course[i].professor);
		fflush(stdin);
	}

	printf("�̸� �ּ� �а�\n");
	for (i = 0; i < size; i++)
	{
		printf("%s %s %s\n", course[i].cou_no, course[i].cou_name, course[i].professor);
	}
	FILE *fp = fopen("lsd_course.dat", "wb");
	if (fp == NULL)
		return;
	fwrite(&size, sizeof(int), 1, fp);
	fwrite(course, sizeof(str_c), size, fp);
	fclose(fp);

	system("pause");
}
void add_course_taken(void)
{
	int i = 0;

	str_ct course_taken[5];

	system("cls");

	printf("�Է��� ������������ ���� �Է��ϼ��� (�ִ� 5��)\n");
	scanf("%d", &size);
	fflush(stdin);

	for (i = 0; i < size; i++)
	{
		printf("%d��° ������������ �й��� �Է� : ", i + 1);
		scanf("%s", course_taken[i].stuid);
		printf("%d��° ������������ �������ȣ�� �Է� : ", i + 1);
		scanf("%s", course_taken[i].cou_no);
		printf("%d��° ������������ ������ �Է� : ", i + 1);
		scanf("%s", course_taken[i].grade);
		fflush(stdin);
	}

	printf("�й� �������ȣ ����\n");
	for (i = 0; i < size; i++)
	{
		printf("%s %s %s\n", course_taken[i].stuid, course_taken[i].cou_no, course_taken[i].grade);
	}
	FILE *fp = fopen("lsd_coursetaken.dat", "wb");
	if (fp == NULL)
		return;
	fwrite(&size, sizeof(int), 1, fp); // 
	fwrite(course_taken, sizeof(str_ct), size, fp);
	fclose(fp);

	system("pause");

}
void view(void)
{
	int i = 0;
	int j = 0;
	int n = 0;

	// ������ ���̺��� ũ�⸦ �ҷ��� ���� 3�� ����
	int size1 = 0;
	int size2 = 0;
	int size3 = 0;

	// 3���� ���̺� ����ü ����
	str_s student[5];
	str_c course[5];
	str_ct course_taken[5];

	
	system("cls");

	for (n = 0; n < size3; n++)
	{
		for (i = 0; i < size1; i++)
		{
			if (strcmp(course_taken[n].stuid, student[i].stuid) == 0) // �й��� ���� ������ ã����
			{
				// �л� ������ ���
				printf("%s ", student[i].stuname);
			}
		}

		for (j = 0; j < size2; j++)
		{
			if (strcmp(course_taken[n].cou_no, course[j].cou_no) == 0) // �������ȣ�� ���� ������ ã����
			{
				// ������ ������ ���
				printf("%s ", course[j].cou_name);
			}

		}

		printf("%s \n", course_taken[n].grade);
	}

}

void file_save(void)
{
	FILE *fp;

	fp = fopen("lsd_student.dat", "rb");
	if (fp == NULL)
	{
		printf("������ �����ϴµ� ������ �ֽ��ϴ�.");
		return;
	}
	fwrite(&size1, sizeof(int), 1, fp);
	po_s = (str_s*)malloc(sizeof(str_s)*size1);
	fwrite(po_s, sizeof(str_s), size1, fp);
	fclose(fp);

	fp = fopen("lsd_course.dat", "rb");
	if (fp == NULL)
	{
		printf("������ �����ϴµ� ������ �ֽ��ϴ�.");
		return;
	}
	fwrite(&size2, sizeof(int), 1, fp);
	fwrite(po_c, sizeof(str_c), size2, fp);
	fclose(fp);

	fp = fopen("lsd_coursetaken.dat", "rb");
	if (fp == NULL)
	{
		printf("������ �����ϴµ� ������ �ֽ��ϴ�.");
		return;
	}
	fwrite(&size3, sizeof(int), 1, fp);
	fwrite(po_ct, sizeof(str_ct), size3, fp);
	fclose(fp);
}

void file_load(void)
{
	
	FILE *fp;

	fp = fopen("lsd_student.dat", "rb");
	if (fp == NULL)
		printf("�л����̺��� �����ϴ�. ���� �ۼ����ּ���.\n");
	fread(&size1, sizeof(int), 1, fp);
	po_s = (str_s*)malloc(sizeof(str_s)*size1);
	fread(po_s, sizeof(str_s), size1, fp);
	fclose(fp);

	fp = fopen("lsd_course.dat", "rb");
	if (fp == NULL)
		printf("�������̺��� �����ϴ�. ���� �ۼ����ּ���.\n");
	fread(&size2, sizeof(int), 1, fp);
	fread(po_c, sizeof(str_c), size2, fp);
	fclose(fp);

	fp = fopen("lsd_coursetaken.dat", "rb");
	if (fp == NULL)
		printf("�������̺��� �����ϴ�. ���� �ۼ����ּ���.\n");
	fread(&size3, sizeof(int), 1, fp);
	fread(po_ct, sizeof(str_ct), size3, fp);
	fclose(fp);

}