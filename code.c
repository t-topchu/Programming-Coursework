#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define DIM 100
int massive[DIM];

void put(int a)
{
	int i;
		for (i = 0; i < a; i++)
		{
			printf("\n%d - ������� : ", i + 1);
			scanf("%d", &massive[i]);
		}
}

void check(int a){
	int flag = 0;
	int i;
	int checkNumber;
	printf("���� �������� �������� �� ��������: ");
	scanf("%d", &checkNumber);
	for (i = 0; i<a; i++)
	{
		if (checkNumber == massive[i])
		{
			printf(" ---------------------------\n");
			printf("������� %d e � ������\n", massive[i]);
			printf("---------------------------\n");
			flag = 1;
		}
		//	else printf("������� %d �� ���� � ������", checkNumber);
	}
	if (flag == 0){
		printf("-------------------------------\n");
		printf("������� %d �� ���� � ������\n", checkNumber);
		printf("-------------------------------\n");
	}
}

void print(int a)
{
	int i;
	for (i = 0; i < a; i++) {
		printf("%d  ", massive[i]);
	}
}

void maximum(int a){
	int i = 0;
	int flag = 0;
	int max = massive[0];
	for (i = 0; i<a; i++)
	{	
		int j;
		int isPrime = 1;
		for (j = 2; j < massive[i]; j++){
			if (massive[i] % j == 0.0){
				isPrime = 0;
			}
		}
		if (isPrime && max < massive[i]){
			flag = 1;
			max = massive[i];
		}
	}
	if (flag == 1){
		printf("-----------------------------------\n");
		printf("���-�������� ������ ����� � %d .\n", max);
		printf("-----------------------------------\n");
	}
	if (flag == 0){
		printf("-----------------------------------\n");
		printf("���� ������ �����.\n");
		printf("-----------------------------------\n");
	}
}

void savingTofile(int a){
	FILE *fp;
	fp = fopen("test.txt", "w");
	fprintf(fp, "%d ", a);
	int i;
	for (i = 0; i < a; i++){
		fprintf(fp, "%d ", massive[i]);
	}
	fclose(fp);
}

void readingFromfile(int *a){
	FILE *fpm;
	fpm = fopen("test.txt", "r");
	fscanf(fpm, "%d", a);
	int i;
	for (i = 0; i < *a; i++){
		fscanf(fpm, "%d", &massive[i]);
	}
	fclose(fpm);
}

int menu(){

	int choice;
	printf("���� \n"
	"~~~~~~~~~~\n"
	"1. ��������� �� ������.\n"
	"2. �������� �� ������� �� ������� �� ��������.\n"
	"3. ����������� �� ������������ �� ������.\n"
	"4. �������� �� ���-�������� ������ ����� � ������.\n"
	"5. ��������� �� ����� �� ������� �� ����� �� ������ �� ���������� ����.\n"
	"6. ����� �� ������������ �� ������ � ������� �� ����� �� ������ �� ���������� ����.\n"
	"7. �����.\n \n");
	
	do{
		printf("�������� ����� �� �������� ����:  ");
		fflush(stdin);
		scanf("%d", &choice);
	} while (choice<1 || choice>7);

	return choice;
}

int main()
{
	int number = 0;
	setlocale(LC_ALL, "Bulgarian");
	printf("���������, ����� ����� � ����������.\n");
	printf("���� ��������� ������ RETURN �� ������������...\n");
	getchar();
	while (1){
		printf("\n------------------------------------- \n\n");
		switch (menu()){
		case 1:
			
				printf("���� �������� : ");
				scanf("%d", &number);
				if (number<1 || number>100){
					printf("��������� �����!\n");
					break;
				}
				else{
					put(number);
				}
				
				printf("\n \n");
			
			break;
		case 2:
			printf("��������: \n\n");
			check(number);
			printf("\n \n");
			break;
		case 3:
			printf("�������� �� ����������: \n ");
			print(number);
			printf("\n \n");
			break;
		case 4:
			maximum(number);
			printf("\n \n");
			break;
		case 5:
			printf("���������: \n ");
			readingFromfile(&number);
			printf("\n \n");
			break;
		case 6:
			printf("��������! \n ");
			savingTofile(number);
			printf("\n \n");
			break;
		case 7: exit(0);
		}
	}
}

