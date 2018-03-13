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
	printf("메뉴를 선택하세요\n");
	printf("1. 학생 테이블 작성\n");
	printf("2. 과목 테이블 작성\n");
	printf("3. 수강 테이블 작성\n");
	printf("4. 작성한 데이터 불러오기\n");
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

	printf("입력할 학생 수를 입력하세요 (최대 5명)\n");
	scanf("%d", &j);
	while (getchar() != '\n');


	for (i = 0; i < j; i++)
	{
		printf("%d번째 학생 이름을 입력 : ", i + 1);
		scanf("%s", student[i].stuname);
		printf("%d번째 학생 주소를 입력 : ", i + 1);
		scanf("%s", student[i].address);
		printf("%d번째 학생 학과를 입력 : ", i + 1);
		scanf("%s", student[i].major);
		while (getchar() != '\n');
	}

	printf("이름 주소 학과");
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