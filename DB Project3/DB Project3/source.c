#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)
int size = 0; // 구조체 개수만큼 파일에 기록하기 위해 선언, 이진파일 첫 부분에 저장됨
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

void menu(void); // 메뉴를 불러오는 함수
void add_student(void); // 학생테이블을 작성하는 함수
void add_course(void); // 교과목테이블을 작성하는 함수
void add_course_taken(void); // 수강테이블을 작성하는 함수
void view(void); // 작성된 테이블들을 불러와서 출력해주는 함수
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
	printf("메뉴를 선택하세요\n");
	printf("1. 학생 테이블 작성\n");
	printf("2. 과목 테이블 작성\n");
	printf("3. 수강 테이블 작성\n");
	printf("4. 작성한 데이터 불러오기\n");
	printf("5. 종료\n");
}

void add_student(void)
{
	int i = 0;

	str_s student[5]; // 구조체 배열 선언

	system("cls"); // 화면 비우기

	printf("입력할 학생 수를 입력하세요 (최대 5명)\n");
	scanf("%d", &size); // 데이터의 수를 입력받음
	fflush(stdin);
	for (i = 0; i < size; i++)
	{
		printf("%d번째 학생의 학번을 입력 : ", i + 1);
		scanf("%s", student[i].stuid);
		printf("%d번째 학생의 이름을 입력 : ", i + 1);
		scanf("%s", student[i].stuname);
		printf("%d번째 학생의 학과를 입력 : ", i + 1);
		scanf("%s", student[i].major);
		printf("%d번째 학생의 주소를 입력 : ", i + 1);
		scanf("%s", student[i].address);
		fflush(stdin);
	}

	FILE *fp = fopen("lsd_student.dat", "wb");
	if (fp == NULL)
		return;
	fwrite(&size, sizeof(int), 1, fp); // 데이터의 수를 파일 첫부분에 기록
	fwrite(student, sizeof(str_s), size, fp); // 데이터 내용을 기록


	fclose(fp); // 파일 닫기

	system("pause");
}


void add_course(void)
{
	int i = 0;

	str_c course[5]; // 구조체 배열 선언

	system("cls"); // 화면 비우기

	printf("입력할 과목 수를 입력하세요 (최대 5개)\n");
	scanf("%d", &size);
	fflush(stdin);


	for (i = 0; i < size; i++)
	{
		printf("%d번째 과목의 교과목번호를 입력 : ", i + 1);
		scanf("%s", course[i].cou_no);
		printf("%d번째 과목의 이름을 입력 : ", i + 1);
		scanf("%s", course[i].cou_name);
		printf("%d번째 과목의 교수를 입력 : ", i + 1);
		scanf("%s", course[i].professor);
		fflush(stdin);
	}

	printf("이름 주소 학과\n");
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

	printf("입력할 수강데이터의 수를 입력하세요 (최대 5개)\n");
	scanf("%d", &size);
	fflush(stdin);

	for (i = 0; i < size; i++)
	{
		printf("%d번째 수강데이터의 학번을 입력 : ", i + 1);
		scanf("%s", course_taken[i].stuid);
		printf("%d번째 수강데이터의 교과목번호를 입력 : ", i + 1);
		scanf("%s", course_taken[i].cou_no);
		printf("%d번째 수강데이터의 학점을 입력 : ", i + 1);
		scanf("%s", course_taken[i].grade);
		fflush(stdin);
	}

	printf("학번 교과목번호 학점\n");
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

	// 각각의 테이블의 크기를 불러올 변수 3개 선언
	int size1 = 0;
	int size2 = 0;
	int size3 = 0;

	// 3가지 테이블 구조체 선언
	str_s student[5];
	str_c course[5];
	str_ct course_taken[5];

	
	system("cls");

	for (n = 0; n < size3; n++)
	{
		for (i = 0; i < size1; i++)
		{
			if (strcmp(course_taken[n].stuid, student[i].stuid) == 0) // 학번이 같은 정보를 찾으면
			{
				// 학생 정보를 출력
				printf("%s ", student[i].stuname);
			}
		}

		for (j = 0; j < size2; j++)
		{
			if (strcmp(course_taken[n].cou_no, course[j].cou_no) == 0) // 교과목번호가 같은 정보를 찾으면
			{
				// 교과목 정보를 출력
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
		printf("파일을 저장하는데 문제가 있습니다.");
		return;
	}
	fwrite(&size1, sizeof(int), 1, fp);
	po_s = (str_s*)malloc(sizeof(str_s)*size1);
	fwrite(po_s, sizeof(str_s), size1, fp);
	fclose(fp);

	fp = fopen("lsd_course.dat", "rb");
	if (fp == NULL)
	{
		printf("파일을 저장하는데 문제가 있습니다.");
		return;
	}
	fwrite(&size2, sizeof(int), 1, fp);
	fwrite(po_c, sizeof(str_c), size2, fp);
	fclose(fp);

	fp = fopen("lsd_coursetaken.dat", "rb");
	if (fp == NULL)
	{
		printf("파일을 저장하는데 문제가 있습니다.");
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
		printf("학생테이블이 없습니다. 새로 작성해주세요.\n");
	fread(&size1, sizeof(int), 1, fp);
	po_s = (str_s*)malloc(sizeof(str_s)*size1);
	fread(po_s, sizeof(str_s), size1, fp);
	fclose(fp);

	fp = fopen("lsd_course.dat", "rb");
	if (fp == NULL)
		printf("과목테이블이 없습니다. 새로 작성해주세요.\n");
	fread(&size2, sizeof(int), 1, fp);
	fread(po_c, sizeof(str_c), size2, fp);
	fclose(fp);

	fp = fopen("lsd_coursetaken.dat", "rb");
	if (fp == NULL)
		printf("수강테이블이 없습니다. 새로 작성해주세요.\n");
	fread(&size3, sizeof(int), 1, fp);
	fread(po_ct, sizeof(str_ct), size3, fp);
	fclose(fp);

}