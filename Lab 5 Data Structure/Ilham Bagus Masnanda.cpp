#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	char nama[20];
	char harga[10];
	char jumlah[3];
	struct node *next;
	struct node *prev;	
}*start, *end, *body;

void print(struct node *start);
void takeorder(int take);
void insert(char nama[], char harga[],char jumlah []);

int pilih;
int repeat;
int data;
int beli;


int main(){
	int val;
	repeat=0;
	char nama[20];
	char harga[10];
	char jumlah[3];
	do{
	system("cls");
	printf("BLUE MOTORCYCLE PARTS\n");
	printf("==========================\n");
	printf("1. View Order List\n");
	printf("2. Add New Order\n");
	printf("3. Take Order\n");
	printf("4. Exit\n");
	do {
		printf(">> Input choice :");
		scanf("%d",&pilih);
		}while (pilih<1 || pilih>4);
	switch(pilih){
	case 1:
		system("cls");
		printf("                --- ORDER LIST ---           \n \n");
		printf("+-----+-----------------------------+-------------------+------------+\n");
		printf("| No. |	Name                        |Quantity           | Unit Price |\n");
		printf("+-----+-----------------------------+-------------------+------------+\n");
		print(start);//=Null
		printf("+-----+-----------------------------+-------------------+------------+\n");
		getch();
		repeat=1;
		break;
	case 2:
		system("cls");
		do{
		printf("Input Name Of Motorcycle's Part [3....30] : ");
		fflush(stdin);
		scanf("%[^\n]s",&nama);
			}while(strlen(nama)<3 || strlen (nama)>30);
		do{
			printf ("Input Quantity of The Motorcycle's Part [1..20] : " );
			scanf ("%s",&jumlah);
			val=atoi(jumlah);
			}while(val <1 || val>20);
		do{
		printf("Input Price of the Motorcycle Part [IDR 10000...1000000] : ");
		scanf("%s",&harga);
			}while(strlen(harga)<5 || strlen (harga)>7);
		printf("\n\n---Add New Order Success---\n");
		insert(nama,harga,jumlah);
		data++;
		getch();
		repeat=1;
		break;
	case 3:
		system("cls");
		if (data==0){
			printf ("there is no data to be deleted");
			getch();
		}
		else
		{
		printf("                --- ORDER LIST ---           \n \n");
		printf("+-----+-----------------------------+-------------------+------------+\n");
		printf("| No. |	Name                        |Quantity           | Unit Price |\n");
		printf("+-----+-----------------------------+-------------------+------------+\n");
		print(start);//=Null
		printf("+-----+-----------------------------+-------------------+------------+\n");
			printf("\nInput order number : ");
			scanf("%d",&beli);
			takeorder(beli);
		}
		printf("\nOrder number %d successfully taken !", beli);
		getch();
		repeat=1;
		break;
	case 4:
		repeat=0;
		break;
	}
	}while(repeat==1);
return 0;
}

void print(struct node *start){
	int index;
	index = 1;
	struct node *n;
	n = start;
	while(n==start){
		printf ("|%-5d|%-29s|%-19s|%-12s|\n", index, n->nama, n->jumlah, n->harga);
		n = n->next;
		index++;
	}
}

void takeorder(int take)
{
	int i, u;
	u=1;
	struct node *ptr;
	struct node *temp;
	ptr=start;
	while (ptr->next!=start)
	{
		ptr=ptr->next;
		u++;
	}
	if (take==1){
		ptr=start;
		while (ptr->next!=start)
		{
			ptr=ptr->next;
		}
		temp=ptr->next;
		ptr->next=start->next;
		start=start->next;
		free(temp);
	}
	else if (take==u)
	{
		ptr=start;
		while (ptr->next->next!=start){
			ptr=ptr->next;
		}
		temp=ptr->next;
		ptr->next=temp->next;
		free(temp);
	}
	else
	{
		ptr=start;
		for (i=1;i<take-1;i++)
		{
			ptr=ptr->next;
		}
		temp=ptr->next;
		ptr->next=temp->next;
		free(temp);
	}
}

void insert(char nama[], char harga[],char jumlah []){
	struct node *ptr;
	body = (struct node*) malloc (sizeof(node));
	strcpy (body->harga,harga);
	strcpy (body->nama, nama);
	strcpy (body->jumlah, jumlah);
	
	if (start==NULL)
	{
		start=body;
		body->next=start;
	}
	else
	{
		ptr = start;
		while (ptr->next!=start)
		{
			ptr=ptr->next;
		}
		ptr->next=body;
		body->next=start;
	}
}
