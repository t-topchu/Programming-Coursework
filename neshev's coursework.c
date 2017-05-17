#include <stdio.h>

void fillArray();             //декларираме функциите които ще ползваме
void checkArray();
void printArray();
void function();
void loadFromFile();
void printToFile();

int array[100];//декларираме масив със 100 елемента като глобална променлива
int br = 100;//декларираме броя на елементите в масива

int main()//главна функция
{

	while (1){//създаваме цикъл който се повтаря докато не излезем от програмата
		printf("-------------------------------\n"
			"1 - Fill the array.\n"
			"2 - Check for element by value.\n"
			"3 - Print the array.\n"
			"4 - Print the element with the smallest sum of its digits\n"
			"5 - Load the array from file.\n"
			"6 - Save the array to a file.\n"
			"7 - Exit\n\n"
			"\nPick a choice: ");
		int n;//променлива която съдържа номера на числото което е избрал потребителя
		scanf("%d", &n);//сканираме и записваме стойността която е въвел потребителя
		printf("\n");//принтираме нов ред

		switch (n){//правим switch проверка която проверява дали числото n е 1, 2, 3... и т.н. и според това какво е, се викат различните функции
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
	scanf("%d", &br);//сканираме и записваме броя на елементите, които искаме да запишем
	printf("Elements: ");
	int i;
	for (i = 0; i < br; i++){//br на брой пъти сканираме и записваме последователно стойностите, които е въвел потребителя
		scanf("%d", &array[i]);
	}
	printf("\n");//принтираме нов ред
}

void checkArray(){
	printf("Number for check: ");
	int n;
	scanf("%d", &n);//сканираме и записваме числото което искаме да проверим
	int i;
	for (i = 0; i < br; i++){//обхождаме масива
		if (array[i] == n){//ако срешнем стойност равна на числото n принтираме, че е налично и се връшаме в началото с return;
			printf("Available.\n\n");
			return;
		}
	}
	printf("Unavailable.\n\n");//след като сме обходили масива и не сме намерили стойност, която е равна на n => няма такава стойност, т.е. не е налична и го принтираме
}

void printArray(){
	int i;
	for (i = 0; i < br; i++){//обхождаме масива
		printf("%d ", array[i]);//принтираме всяка една стойност
	}
	printf("\n\n");//принтираме 2 нови реда
}

void function(){
	int i;
	int min;//в тази променлива ще запазваме манималната сума
	int minIndex;// в тази променлива ще запазваме индекса на минималната сума за да можем да го извикаме и принтираме накрая
	for (i = 0; i < br; i++){//обхождаме масива
		char digits[10];//масив от символи където ще запазваме всяка една цифра от числото от masiv[i]
		int j;
		for (j = 0; j < 10; j++){//нулираме масива digits
			digits[j] = 0;
		}
		sprintf(digits, "%1d", array[i]);//запазваме цифрите в масива digits
		int suma = 0;//променлива в която ще запазваме текущaта сума
		for (j = 0; digits[j] != 0;){
			suma += digits[j] - '0';//събираме всички цифри
			j++;
		}
		if (i == 0){
			min = suma;//min приема стойността на сбора на първия елемент
			minIndex = i;
		}

		if (min>suma){//ако сумата е по-малка от минималната за сега
			min = suma;//минималната сума приема стойността на текущата сума
			minIndex = i;//запазваме индекса на минималната сума
		}
	}
	printf("The number with the smallest sum of its digits  %d\n\n", array[minIndex]);//принтираме резултата

}

void loadFromFile(){
	printf("File name: ");
	char name[50];//масив от символи, който ще съдържа името на файла
	int i;
	for (i = 0; i < 50; i++){//обхождаме масива name и го нулираме, за да не стават грешки
		name[i] = 0;
	}
	scanf("%s", name);//сканираме и записваме името на файла
	FILE *fp;//правим си файл

	if (!(fp = fopen(name, "r"))){ //ако файла не съществува принтирай съобщение и приключи функцията | fopen отваря файла а "r" значи, че ще четем от него
		fclose(fp);//затваряме файла ако не съществува
		printf("The file does not exist.\n\n");//принтираме че не съществува
		return;//връщаме се в началото
	}//ако съществува такъв файл продължаваме нататък

	fscanf(fp, "%d", &br);//сканираме файла и взимаме първата стойност която показва колко е дълъг масива във него
	for (i = 0; i < br; i++){//като имаме дължината на масива сканираме толкова брой пъти и ги записваме в нашия масив
		fscanf(fp, "%d", &array[i]);
	}
	printf("\n");//принтираме нов ред
	fclose(fp);//задължително затваряме файла накрая
}

void printToFile(){
	printf("File name: ");
	char name[50]; //декларираме масив от символи, който ще съдържа името на файла
	int i;
	for (i = 0; i < 50; i++){//нулираме масива name
		name[i] = 0;
	}
	scanf("%s", name);//сланираме и записваме името на файла въведено от потребителя
	FILE *fp;//създаваме файл

	fp = fopen(name, "w");//отваряме файла с име name и с "w" показваме че ше пишем в него

	fprintf(fp, "%d ", br);//записваме br като първа стойност за да знаем колко символа ще запишем и колко символа да четем като изберем четене от файл
	for (i = 0; i < br; i++){//обхождаме масива
		fprintf(fp, "%d ", array[i]);//записваме го във файла
	}
	printf("\n");//принтираме нов ред
	fclose(fp);//затваряме файла
}
