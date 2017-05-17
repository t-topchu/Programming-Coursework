#include <stdio.h>
#include <stdlib.h>
#include<string.h>

void vuvejdane();
void proverka();
void otpechatvane();
void specfun();
void filezarejdane();
void filezapisvane();

int ARR[100];
int size;

int menu() {




	int cmd;

	printf("Molya izberete komanda ot menuto:\n 1:Popylvane na masiva\n2:Proverka za nalichie na element po stoinost\n3:Otpechatvane na masiva na ekrana\n4:Izvejdane chislata, chiito kvadraten koren e cqlo chislo na ekrana\n5:Zarejdane na masiv ot posochen ot vas fail\n6:Zapisvane na sydyrjanieto na masiva v posochen ot vas fail\n7:Izhod");
	do {
		printf("\n \nIzberete: ");
		fflush(stdin);
		scanf("%d", &cmd);
	} while (cmd < 0 || cmd > 7);
	return cmd;
}

int main() {

	while (1) {
		system("cls");

		switch (menu())
		{

		case 1:
			vuvejdane();
			break;

		case 2:

			proverka(size);
			break;

		case 3:
			otpechatvane(size);
			break;

		case 4:

			specfun(size);
			break;

		case 5:
			filezarejdane(&size);
			break;

		case 6:
			filezapisvane(size);
			break;
		case 7:
			return 0;
		}
		system("pause");
	}
}
void vuvejdane()
{
	int a;

	printf("Vyvedete broqt na chislata(maksimalen broi-100)\n");
	scanf("%d", &size);
	if (size > 100) {

		printf("Broqt na elementite trqbwa da ne e po-golqm ot 100\n");
		return;
	}

	printf("Vyvedete elementite:\n");

	for (a = 0; a < size; a++) {
		printf("Vyvedete %d element:\n", a + 1);
		scanf("%d", &ARR[a]);
	}

}



void proverka(int size)
{

	int el;
	printf("Molya vyvedete stoinostta na elementa, za chieto nalichie iskate da proverite\n");
	scanf("%d", &el);
	int i;
	for (i = 0; i < size; i++) {



		if (ARR[i] == el) {
			printf("Tozi element syshtestvuva v masiva\n");
			return;
		}

	}
	printf("Tozi element ne syshtestvuva v masiva\n");

}
void otpechatvane(int size)
{
	int i;
	if (!ARR) {
		return;
	}
	for (i = 0; i < size; i++)
	{
		printf("%d, ", ARR[i]);
	}
}



void specfun(int size)
{
	int a;
	int *h;
	int i;
	for (a = 0; a < size; a++)
	{
		h = ARR;
		for (i = 0; i < *(h + a); i++)
		{
			if ((i ^ 2) == *(h + a))
			{
				printf("%d ", *(h + a));
			}

		}


	}





}
void filezapisvane(int size) {
	FILE *fp;
	fp = fopen("file.txt", "w");
	fprintf(fp, "%d ", size);
	int i;
	for (i = 0; i < size; i++) {
		fprintf(fp, "%d ", ARR[i]);
	}
	fclose(fp);
}

void filezarejdane(int *size) {
		FILE *fpr;
		fpr = fopen("file.txt", "r");
		fscanf(fpr, "%d", size);
		int i;
		for (i = 0; i < *size; i++){
			fscanf(fpr, "%d", &ARR[i]);
		}
		fclose(fpr);
	}