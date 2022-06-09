#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>	
#define SIZE 100

FILE* fp;

//scanf�� ����ڰ� �Է��� �� �޴� �迭.
char name[SIZE]; //������ �̸�
char aut[SIZE]; //����
char com[SIZE]; //���ǻ�

char NAME[SIZE]; //search �Լ����� ���.

char bname[SIZE]; //����
char auth[SIZE]; //����
char publ[SIZE]; //���ǻ�

 
void read_file(); //���� �б�
void add(); //�߰�
void end(); //����
void print(); //���
void write(); //���� ���� 
void serach(); //���� �˻�


void add() 
{
	fp = fopen("book.txt", "a");

	printf("������ �̸�:");
	scanf("%s", name);
	strcpy(bname, name);

	printf("����:");
	scanf("%s", aut);
	strcpy(auth, aut);
	
	printf("���ǻ�:");
	scanf("%s", com);
	strcpy(publ, com);

	//���Ͽ� ����
	fprintf(fp, "����:%s\n����:%s\n���ǻ�:%s\n\n", bname, auth, publ);

	fclose(fp);

}
void read_file() //���� �б�
{
	if ((fp = fopen("book.txt", "r"))== NULL)
	{
		fprintf(stderr, "������ �� �� �����ϴ�.\n");
		exit(1); //������ ���� ������ �����Ŵ. ���� ����� 1 ��ȯ
	}
	else
	{
		printf("���� ���� ����!\n\n");
	}
}

void end() // ����
{
	 
	printf("���� ���� ���α׷��� �����մϴ�.\n");
	exit(0); //���� ���� �� 0 ��ȯ
}

void print() //���
{
	fp = fopen("book.txt", "r"); //�б���� ����

	char line[SIZE]; //���ڿ��� ������ �迭

	//fgets fp���� �� �� �Ǵ� sizeof(line)ũ�⸸ŭ�� �о line�� �־� ��ȯ.
	//�� �̻� �о�� �����Ͱ� ���� ������, �� �پ� �о�´�.
	while (fgets(line, sizeof(line), fp) != NULL)
	{
		printf("%s", line);
	}
	fclose(fp); //���� �ݱ�
}
void write() //���� ����
{
	if ((fp = fopen("book.txt", "w")) == NULL) //���� ���� �ؽ�Ʈ���� ����
	{
		fprintf(stderr, "������ �� �� �����ϴ�.\n");
		exit(1); //���� ���� ����
	}
	else
	{
		printf("���� ���� ����!(2)\n\n");
	}
}
void search() //���� �˻�
{
	fp = fopen("book.txt","r"); //������ �б���� �����ش�.

	printf("����:");
	scanf("%s", NAME); //����ڿ��Լ� å ������ �Է¹޴´�.

	if (strcmp(bname, NAME) == 0) //strcmp�� �̿�, bname ����� NAME ������ ������,
	{
		printf("���ǻ�� %s\n\n", publ); //���ǻ縦 ���.
	}
	else
		printf("�ش� ������ �������� �ʽ��ϴ�.\n"); //�߸��� �̸��� �Է½�.
	 
	fclose(fp);//���� �ݱ�
}
int main()
{
	
	int num; //������� �޴� ����

	printf("=======================\n");
	printf("SWU ���� ���� ���α׷�\n");

	while (1)
	{
		
		printf("=======================\n");
		printf("1. ���� �б�\n");
		printf("2. �߰�\n");
		printf("3. ���\n");
		printf("4. �˻�\n");
		printf("5. ���� ����\n");
		printf("6. ����\n");
		printf("=======================\n");
		printf("���� ���� �Է��Ͻÿ�:");
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