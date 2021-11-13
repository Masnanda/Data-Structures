#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct data
{
	int jumlah;
	char nama[30], warna[9], brand[12];
	struct data *next;
	struct data *prev;
} *head, *tail, *node;

void insert (char nama[], char warna[], char brand[], int jumlah);
void printdata(struct data *head);


int pilih,repeat,asset;

int main ()
{
	asset=0;
	repeat=1;
	do
	{
		system("cls");
		printf ("DATABASE ASSET\n");
		printf ("..............................\n\n");
		printf ("1. View Asset\n");
		printf ("2. Add New Asset\n");
		printf ("3. Exit\n\n");
		printf (">> Input choice: "); 
		scanf ("%d", &pilih);
		switch (pilih)
		{
			case 1:
			{
				system("cls");
				printf ("\t\t--- DATABASE ASSET ---\n");
				printf ("+-----+------------------------------+---------+------------+----------+\n");
				printf ("| No. | Name of Asset                | Color   | Brand      | Quantity |\n");
				printf ("+-----+------------------------------+---------+------------+----------+\n");
				printdata(head);
				printf ("+-----+------------------------------+---------+------------+----------+\n");
				getch();
				repeat=0;
				break;
			}
			case 2:
			{
				system("cls");
				char nama[30], warna[9], brand[12];
				int jumlah;
				do
				{
					printf ("\nInput Name of Asset[5..30]: "); 
					fflush (stdin);
					scanf ("%[^\n]", &nama);
				}while (strlen(nama)<5 || strlen(nama)>30);
				printf ("\nInput Color: ");
				scanf ("%s", &warna);
				printf ("\nInput Brand: ");
				fflush (stdin);
				scanf ("%[^\n]", &brand);
				do
				{
					printf ("\nInput Quantity [1...100]: ");
					scanf ("%d", &jumlah);
				}while (jumlah<1 || jumlah>100);
				insert (nama, warna, brand, jumlah);
				printf ("\n\n\n --- Add New Asset Success ---");
				asset++;
				getch();
				repeat=0;
				break;
			}
			case 3:
			{
				repeat=1;
				printf ("\n\n\t\tTHANKYOU !!!!!!");
				break;
			}
		}
	}while (repeat==0);
}

void insert (char nama[], char warna[], char brand[], int jumlah)
{
	struct data *ptr;
	node = (struct data*) malloc (sizeof(data));
	node->jumlah=jumlah;
	strcpy (node->nama, nama);
	strcpy (node->warna, warna);
	strcpy (node->brand, brand);
	
	if (head==NULL
	){
		node->next=NULL;
		node->prev=NULL;
		head=node;
	}
	else
	{
		ptr=head;
		while (ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next=node;
		node->prev=ptr;
		node->next=NULL;
	}
}

void printdata(struct data *head)
{
	int index;
	index=1;
	struct data *ptr;
	ptr = head;
	while (ptr!=NULL){
		printf ("|%3d. |%-30s|%-9s|%-12s|%10d|\n", index, ptr->nama, ptr->warna, ptr->brand, ptr->jumlah);
		ptr = ptr->next;
		index++;
	}
}

