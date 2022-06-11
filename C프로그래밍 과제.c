#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	
#define SIZE 100

FILE* fp;

//scanf로 사용자가 입력한 걸 받는 배열.
char name[SIZE]; //도서의 이름
char aut[SIZE]; //저자
char com[SIZE]; //출판사

char NAME[SIZE]; //search 함수에서 사용.

char bname[SIZE]; //제목
char auth[SIZE]; //저자
char publ[SIZE]; //출판사

 
void read_file(); //파일 읽기
void add(); //추가
void end(); //종료
void print(); //출력
void write(); //파일 쓰기 
void serach(); //도서 검색


void add() 
{
	fp = fopen("book.txt", "a");

	printf("도서의 이름:");
	scanf("%s", name);
	strcpy(bname, name);

	printf("저자:");
	scanf("%s", aut);
	strcpy(auth, aut);
	
	printf("출판사:");
	scanf("%s", com);
	strcpy(publ, com);

	//파일에 쓰기
	fprintf(fp, "제목:%s\n저자:%s\n출판사:%s\n\n", bname, auth, publ);

	fclose(fp);

}
void read_file() //파일 읽기
{
	if ((fp = fopen("book.txt", "r"))== NULL)
	{
		fprintf(stderr, "파일을 열 수 없습니다.\n");
		exit(1); //에러가 나도 강제로 종료시킴. 에러 종료시 1 반환
	}
	else
	{
		printf("파일 오픈 성공!\n\n");
	}
}

void end() // 종료
{
	 
	printf("도서 관리 프로그램을 종료합니다.\n");
	exit(0); //정상 종료 시 0 반환
}

void print() //출력
{
	fp = fopen("book.txt", "r"); //읽기모드로 열기

	char line[SIZE]; //문자열을 저장할 배열

	//fgets fp에서 한 줄 또는 sizeof(line)크기만큼을 읽어서 line에 넣어 반환.
	//더 이상 읽어올 데이터가 없을 때까지, 한 줄씩 읽어온다.
	while (fgets(line, sizeof(line), fp) != NULL)
	{
		printf("%s", line);
	}
	fclose(fp); //파일 닫기
}
void write() //파일 쓰기
{
	if ((fp = fopen("book.txt", "w")) == NULL) //쓰기 모드로 텍스트파일 열기
	{
		fprintf(stderr, "파일을 열 수 없습니다.\n");
		exit(1); //에러 강제 종료
	}
	else
	{
		printf("파일 오픈 성공!(2)\n\n");
	}
}
void search() //도서 검색
{
	fp = fopen("book.txt","r"); //파일을 읽기모드로 열어준다.

	printf("제목:");
	scanf("%s", NAME); //사용자에게서 책 제목을 입력받는다.

	if (strcmp(bname, NAME) == 0) //strcmp를 이용, bname 제목과 NAME 제목이 같으면,
	{
		printf("출판사는 %s\n\n", publ); //출판사를 출력.
	}
	else
		printf("해당 도서는 존재하지 않습니다.\n"); //잘못된 이름을 입력시.
	 
	fclose(fp);//파일 닫기
}
int main()
{
	
	int num; //사용자의 메뉴 선택

	printf("=======================\n");
	printf("SWU 도서 관리 프로그램\n");

	while (1)
	{
		
		printf("=======================\n");
		printf("1. 파일 읽기\n");
		printf("2. 추가\n");
		printf("3. 출력\n");
		printf("4. 검색\n");
		printf("5. 파일 쓰기\n");
		printf("6. 종료\n");
		printf("=======================\n");
		printf("정수 값을 입력하시오:");
		scanf("%d", &num);
		printf("\n");

		switch (num) {
		case 1:
			read_file(); 
			break;
		case 2:
			add();
			break;
		case 3:
			print();
			break;
		case 4:
			search();
			break;
		case 5:
			write();
			break;
		case 6:
			end();
			break;

		}


	}


	return 0;
}
