#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct node{
	char merk[20];
	char tipe[10];
	char warna[20];
	char stock[3];
	struct node *next;
}*start, *body;


void pop(struct node *start);//Delete
void push(char merk[], char tipe[], char warna[], char stock[]);//Input
void print(struct node *start);//Print Display

int pilih;//menu
int repeat;//ulang
int data;//data


int main(){
	repeat=0;
	int val; //atoi val = atoi(stock)
		char merk[20];
		char tipe[10];
		char warna[20];
		char stock[3];
	do{
	system("cls");
	printf("CAR ADMINISTRATOR\n");
	printf("==========================\n\n");
	printf("1. Car List\n");
	printf("2. Add <PUSH> New Car\n");
	printf("3. Delete <POP> Recently Added Car\n");
	printf("4. Exit\n\n");
	do {
		printf(">> Input choice :");
		scanf("%d",&pilih);
		}while (pilih<1 || pilih>4);
	switch(pilih){
	case 1:
		system("cls");
		printf(" \t\t               --- INFORMATION LIST ---           \n \n");
		printf("+-----+-----------------------------+------------+---------------------+------------------+\n");
		printf("| No. |	Merk                        |  Type      |   Color             | Stock            |\n");
		printf("+-----+-----------------------------+------------+---------------------+------------------+\n");
		print(start);
		printf("+-----+-----------------------------+------------+---------------------+------------------+\n");
		getch();
		repeat=1;
		break;
	case 2:
		system("cls");
		do{
		printf("Input Merk of The New Car [3....20] : ");
		fflush(stdin);
		scanf("%[^\n]s",&merk);//Kijang Inova
			}while(strlen(merk)<3 || strlen (merk)>20);
		do{
		printf("Input The Type of The New Car [sedan/sport/minivan] :");
		scanf("%s",&tipe);
			}while (strcmp(tipe,"sedan")!=0 &&strcmp(tipe, "sport")!=0 && strcmp (tipe, "minivan")!=0);
		do{
			printf("Input Color of The New Car [red/black/white/grey]: ");
			fflush(stdin);
			scanf("%s",&warna);
		}while (strcmp(warna,"red")!=0 &&strcmp(warna, "black")!=0 && strcmp (warna, "white")!=0 && strcmp (warna, "grey"));
		do{
			printf("Input Stock of The New Car [1...20] : ");
			scanf("%s",&stock);
			val=atoi(stock);
		}while(val <1 || val>20);
		printf("\n\n\n --- Add New Car Success ---");
		push(merk,tipe,warna,stock);
		data++;
		getch();
		repeat=1;
		break;
	case 3:
		if (data==0)
		{
			printf ("\n\n--- There Is No Data To Be Deleted ---");
			getch();
		}
		else
		{
			struct node*n;
			n=start;
			start=start->next;
			printf("\n\n--- The Information Being Delete is : %s %s <%s> --- ",n->warna, n->merk, n->tipe );
			getch();
			data--;
		}
		repeat=1;
		break;
	case 4:
		repeat=0;
		break;
	}
	}while(repeat==1);
return 0;	
}

void push(char merk[], char tipe[], char warna[], char stock[])
{
	struct node *n;
	body = (struct node*) malloc(sizeof(node));//alokasi data
	strcpy(body->merk, merk);
	strcpy(body->warna, warna);
	strcpy(body->stock, stock);
	strcpy(body->tipe, tipe);
	
	if (start == NULL)
	{
		body->next=NULL;
		start=body;
	}
	else 
	{
		body->next = start;
		start=body;
	}
}

void pop(struct node *start){
	struct node *n;
	n = start;
	start = start->next;
	free(n);
}

void print(struct node *start){
	int index;
	index = 1;
	struct node *n;
	n = start;
	while (n!=NULL){
		printf ("|%-5d|  %-27s| %-11s|  %-18s | %-16s |\n", index, n->merk, n->tipe, n->warna, n->stock);
		n = n->next;
		index++;
	}
}

