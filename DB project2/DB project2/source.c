#include <stdio.h>
#include <string.h>
#pragma warning(disable: 4996)
int size = 0; // 구조체 개수만큼 파일에 기록하기 위해 선언, 이진파일 첫 부분에 저장됨

struct student_info
{
	char stuid[20];
	char stuname[20];
	char major[20];
};
typedef struct student_info data_s;

struct course_info // 구조체 만들기
{
	char cou_no[20];
	char cou_name[20];
	char professor[20];
};
typedef struct course_info data_c; // 자료형 재정의

struct course_taken_info // 구조체 만들기
{
	char stuid[20];
	char cou_no[20];
	char grade[20];
};
typedef struct course_taken_info data_ct; // 자료형 재정의

void menu(void); // 메뉴를 불러오는 함수
void add_student(void); // 학생테이블을 작성하는 함수
void add_course(void); // 교과목테이블을 작성하는 함수
void add_course_taken(void); // 수강테이블을 작성하는 함수
void view(void); // 작성된 테이블들을 불러와서 출력해주는 함수

int main(void)
{
	char choice;
	while (1)
	{
		menu(); // 메뉴텍스트
		choice = getch(); // 메뉴를 입력받음
		fflush(stdin); // 버퍼 초기화
		switch (choice) //switch문을 사용하여 입력받은 숫자 처리
		{
		case'1':	add_student();			break;
		case'2':	add_course();			break;
		case'3':	add_course_taken();		break;
		case'4':	view();					break;
		case'5':	return;
		}


	}


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
	int i = 0; // for문 사용을 위해 선언

	data_s student[5]; // 구조체 배열 선언

	system("cls"); // 화면 비우기

	printf("입력할 학생 수를 입력하세요 (최대 5명)\n");
	scanf("%d", &size); // for문에서 크기만큼 입력받음 또한, 파일 저장시에 맨 앞에 기록해서 파일 로드시에 size만큼만 불러옴
	fflush(stdin);
	for (i = 0; i < size; i++)
	{
		printf("%d번째 학생의 학번을 입력 : ", i + 1);
		scanf("%s", student[i].stuid);
		printf("%d번째 학생의 이름을 입력 : ", i + 1);
		scanf("%s", student[i].stuname);
		printf("%d번째 학생의 학과를 입력 : ", i + 1);
		scanf("%s", student[i].major);
		fflush(stdin);
	}

	FILE *fp = fopen("lsd_student.dat", "wb");
	if (fp == NULL)
		return;
	fwrite(&size, sizeof(int), 1, fp);
	fwrite(student, sizeof(data_s), size, fp);


	fclose(fp);

	system("pause");
}


void add_course(void)
{
	int i = 0; // for문 사용을 위해 선언

	data_c course[5]; // 구조체 배열 선언

	system("cls"); // 화면 비우기

	printf("입력할 과목 수를 입력하세요 (최대 5개)\n");
	scanf("%d", &size); // for문에서 크기만큼 입력받음 또한, 파일 저장시에 맨 앞에 기록해서 파일 로드시에 size만큼만 불러옴
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
	fwrite(course, sizeof(data_c), size, fp);
	fclose(fp);

	system("pause");
}
void add_course_taken(void)
{
	int i = 0; // for문 사용을 위해 선언

	data_ct course_taken[5]; // 구조체 배열 선언

	system("cls"); // 화면 비우기

	printf("입력할 수강데이터의 수를 입력하세요 (최대 5개)\n");
	scanf("%d", &size); // for문에서 크기만큼 입력받음 또한, 파일 저장시에 맨 앞에 기록해서 파일 로드시에 size만큼만 불러옴
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
	fwrite(&size, sizeof(int), 1, fp);
	fwrite(course_taken, sizeof(data_ct), size, fp);
	fclose(fp);

	system("pause");

}
void view(void)
{
	int i = 0;
	int j = 0;
	int n = 0;
	int size1 = 0;
	int size2 = 0;
	int size3 = 0;


	data_s student[5];

	data_c course[5]; // 구조체 배열 선언

	data_ct course_taken[5]; // 구조체 배열 선언

	FILE *fp;

	fp = fopen("lsd_student.dat", "rb");
	if (fp == NULL)
		return;
	fread(&size1, sizeof(int), 1, fp);
	fread(&student, sizeof(data_s), size1, fp);

	fclose(fp);


	fp = fopen("lsd_course.dat", "rb");
	if (fp == NULL)
		return;
	fread(&size2, sizeof(int), 1, fp);
	fread(&course, sizeof(data_c), size2, fp);

	fclose(fp);

	fp = fopen("lsd_coursetaken.dat", "rb");
	if (fp == NULL)
		return;
	fread(&size3, sizeof(int), 1, fp);
	fread(&course_taken, sizeof(data_ct), size3, fp);

	fclose(fp);

	/*
	// 입력된 내용이 잘 로드되었는지 확인하는 구문
	for (i = 0; i < size1; i++)
	{
	printf("%s %s %s\n", student[i].stuid, student[i].stuname, student[i].major);
	}

	for (i = 0; i < size2; i++)
	{
	printf("%s %s %s\n", course[i].cou_no, course[i].cou_name, course[i].professor);
	}

	for (i = 0; i < size3; i++)
	{
	printf("%s %s %s\n", course_taken[i].stuid, course_taken[i].cou_no, course_taken[i].grade);
	}

	*/

	for (n = 0; n < size3; n++)
	{
		for (i = 0; i < size1; i++)
		{
			if (strcmp(course_taken[n].stuid, student[i].stuid) == 0)
			{
				printf("%s ", student[i].stuid);
				printf("%s ", student[i].stuname);
				printf("%s ", student[i].major);
			}
		}

		for (j = 0; j < size2; j++)
		{
			if (strcmp(course_taken[n].cou_no, course[j].cou_no) == 0)
			{
				printf("%s ", course[j].cou_name);
				printf("%s ", course[j].cou_no);
				printf("%s ", course[j].professor);
			}

		}

		printf("%s \n", course_taken[n].grade);
	}

}