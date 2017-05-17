#include <stdio.h>

void fillArray();             //����������� ��������� ����� �� ��������
void checkArray();
void printArray();
void function();
void loadFromFile();
void printToFile();

int array[100];//����������� ����� ��� 100 �������� ���� �������� ����������
int br = 100;//����������� ���� �� ���������� � ������

int main()//������ �������
{

	while (1){//��������� ����� ����� �� ������� ������ �� ������� �� ����������
		printf("-------------------------------\n"
			"1 - Fill the array.\n"
			"2 - Check for element by value.\n"
			"3 - Print the array.\n"
			"4 - Print the element with the smallest sum of its digits\n"
			"5 - Load the array from file.\n"
			"6 - Save the array to a file.\n"
			"7 - Exit\n\n"
			"\nPick a choice: ");
		int n;//���������� ����� ������� ������ �� ������� ����� � ������ �����������
		scanf("%d", &n);//��������� � ��������� ���������� ����� � ����� �����������
		printf("\n");//���������� ��� ���

		switch (n){//������ switch �������� ����� ��������� ���� ������� n � 1, 2, 3... � �.�. � ������ ���� ����� �, �� ����� ���������� �������
		case 1: fillArray();
			break;
		case 2: checkArray();
			break;
		case 3: printArray();
			break;
		case 4: function();
			break;
		case 5: loadFromFile();
			break;
		case 6: printToFile();
			break;
		case 7: return 0;
		}
	}
}

void fillArray(){
	printf("Number of elements: ");
	scanf("%d", &br);//��������� � ��������� ���� �� ����������, ����� ������ �� �������
	printf("Elements: ");
	int i;
	for (i = 0; i < br; i++){//br �� ���� ���� ��������� � ��������� �������������� �����������, ����� � ����� �����������
		scanf("%d", &array[i]);
	}
	printf("\n");//���������� ��� ���
}

void checkArray(){
	printf("Number for check: ");
	int n;
	scanf("%d", &n);//��������� � ��������� ������� ����� ������ �� ��������
	int i;
	for (i = 0; i < br; i++){//��������� ������
		if (array[i] == n){//��� ������� �������� ����� �� ������� n ����������, �� � ������� � �� ������� � �������� � return;
			printf("Available.\n\n");
			return;
		}
	}
	printf("Unavailable.\n\n");//���� ���� ��� �������� ������ � �� ��� �������� ��������, ����� � ����� �� n => ���� ������ ��������, �.�. �� � ������� � �� ����������
}

void printArray(){
	int i;
	for (i = 0; i < br; i++){//��������� ������
		printf("%d ", array[i]);//���������� ����� ���� ��������
	}
	printf("\n\n");//���������� 2 ���� ����
}

void function(){
	int i;
	int min;//� ���� ���������� �� ��������� ����������� ����
	int minIndex;// � ���� ���������� �� ��������� ������� �� ����������� ���� �� �� ����� �� �� �������� � ���������� ������
	for (i = 0; i < br; i++){//��������� ������
		char digits[10];//����� �� ������� ������ �� ��������� ����� ���� ����� �� ������� �� masiv[i]
		int j;
		for (j = 0; j < 10; j++){//�������� ������ digits
			digits[j] = 0;
		}
		sprintf(digits, "%1d", array[i]);//��������� ������� � ������ digits
		int suma = 0;//���������� � ����� �� ��������� �����a�� ����
		for (j = 0; digits[j] != 0;){
			suma += digits[j] - '0';//�������� ������ �����
			j++;
		}
		if (i == 0){
			min = suma;//min ������ ���������� �� ����� �� ������ �������
			minIndex = i;
		}

		if (min>suma){//��� ������ � ��-����� �� ����������� �� ����
			min = suma;//����������� ���� ������ ���������� �� �������� ����
			minIndex = i;//��������� ������� �� ����������� ����
		}
	}
	printf("The number with the smallest sum of its digits  %d\n\n", array[minIndex]);//���������� ���������

}

void loadFromFile(){
	printf("File name: ");
	char name[50];//����� �� �������, ����� �� ������� ����� �� �����
	int i;
	for (i = 0; i < 50; i++){//��������� ������ name � �� ��������, �� �� �� ������ ������
		name[i] = 0;
	}
	scanf("%s", name);//��������� � ��������� ����� �� �����
	FILE *fp;//������ �� ����

	if (!(fp = fopen(name, "r"))){ //��� ����� �� ���������� ��������� ��������� � �������� ��������� | fopen ������ ����� � "r" �����, �� �� ����� �� ����
		fclose(fp);//��������� ����� ��� �� ����������
		printf("The file does not exist.\n\n");//���������� �� �� ����������
		return;//������� �� � ��������
	}//��� ���������� ����� ���� ������������ �������

	fscanf(fp, "%d", &br);//��������� ����� � ������� ������� �������� ����� ������� ����� � ����� ������ ��� ����
	for (i = 0; i < br; i++){//���� ����� ��������� �� ������ ��������� ������� ���� ���� � �� ��������� � ����� �����
		fscanf(fp, "%d", &array[i]);
	}
	printf("\n");//���������� ��� ���
	fclose(fp);//������������ ��������� ����� ������
}

void printToFile(){
	printf("File name: ");
	char name[50]; //����������� ����� �� �������, ����� �� ������� ����� �� �����
	int i;
	for (i = 0; i < 50; i++){//�������� ������ name
		name[i] = 0;
	}
	scanf("%s", name);//��������� � ��������� ����� �� ����� �������� �� �����������
	FILE *fp;//��������� ����

	fp = fopen(name, "w");//�������� ����� � ��� name � � "w" ��������� �� �� ����� � ����

	fprintf(fp, "%d ", br);//��������� br ���� ����� �������� �� �� ����� ����� ������� �� ������� � ����� ������� �� ����� ���� ������� ������ �� ����
	for (i = 0; i < br; i++){//��������� ������
		fprintf(fp, "%d ", array[i]);//��������� �� ��� �����
	}
	printf("\n");//���������� ��� ���
	fclose(fp);//��������� �����
}
