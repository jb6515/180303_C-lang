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
	printf("메뉴를 선택하세요\n");
	printf("1. 학생 테이블 작성\n");
	printf("2. 과목 테이블 작성\n");
	printf("3. 수강 테이블 작성\n");
	printf("4. 작성한 데이터 불러오기");
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
		printf("%d번째 학생 이름을 입력 : ", i + 1);
		scanf("%s", student[i].stuname);
		printf("%d번째 학생 주소를 입력 : ", i + 1);
		scanf("%s", student[i].address);
		printf("%d번째 학생 학과를 입력 : ", i + 1);
		scanf("%s", student[i].major);
		while (getchar() != '\n');
	}

	for (i = j; i < 1; i++)
	{
		printf("%s %s %s", student[i].stuname, student[i].address, student[i].major);
	}
}