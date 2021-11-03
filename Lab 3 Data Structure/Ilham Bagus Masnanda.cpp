#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

struct node{
	//Struck Node
	char nama[20];
	int umur;
	char sakit[20];
	struct node *next;
};
//Node Start di bawah untuk membuka data
struct node *start=NULL;
int count=0;

//Struct untuk Display
struct node *display(struct node *start){
	int i=1;
	struct node *ptr;
	ptr = start;
	printf("                --- General Clinic ---           \n \n");
	printf("+-----+-----------------------------+-------+--------------------------+\n");
	printf("| No. |	Costumer Name               | Age   |      Disease             |\n");
	printf("+-----+-----------------------------+-------+--------------------------+\n");
	while(ptr != NULL){
	printf("|%3d. | %-28s| %-6d|  %-19s     |\n",i,ptr->nama,ptr->umur,ptr->sakit);
	ptr = ptr -> next;
	
	i++;
	}
	printf("+-----+-----------------------------+-------+--------------------------+\n");
}

//struct Membuat jika Data masih Null
struct node *create(struct node *start){
	struct node *new_node, *ptr;
 	char patient[20];
	int jumlah;
 	char  Disease[20];

		printf("Input Patient's name: ");
		fflush(stdin);
		scanf("%s", &patient);
			do{
			printf("Input Age of Patients [1..100]: ");
			fflush(stdin);
			scanf("%d",&jumlah);
				}while(jumlah<1||jumlah>100);
		printf("Input Disease [5..100]: ");
		fflush(stdin);
		scanf("%s",&Disease);
		//alokasi data awal
	new_node = (struct node*)malloc(sizeof(struct node));
	strcpy(new_node->nama,patient); //strcpy nama
	new_node->umur = jumlah;// masukan jumlah ke dalam new_node
	strcpy(new_node->sakit,Disease); //strcpy makanan
	if(start == NULL)
	{
		new_node -> next = NULL;
		start = new_node;
	}
	else
	{
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next = new_node;
		new_node->next=NULL;
	}
	
}

struct node *insert_end(struct node *start)
{
	struct node *new_node, *ptr;
 	char patient[20];
	int jumlah;
 	char Disease[20];

		printf("Input Costumer name: ");
		fflush(stdin);
		scanf("%s", &patient);
			do{
			printf("Input Age : ");
			fflush(stdin);
			scanf("%d",&jumlah);
				}while(jumlah<1||jumlah>100);
		printf("Input Disease : ");
		fflush(stdin);
		scanf("%s",&Disease);
		//alokasi data awal
	new_node = (struct node*)malloc(sizeof(struct node));
	strcpy(new_node->nama,patient); //strcpy nama
	new_node->umur= jumlah;// masukan jumlah ke dalam new_node
	strcpy(new_node->sakit,Disease); //strcpy makanan
	if(start == NULL){
		new_node -> next = NULL;
		start = new_node;
	}else
	{
		ptr=start;
		while(ptr->next!=NULL)
		{
			ptr=ptr->next;
		}
		ptr->next = new_node;
		new_node->next=NULL;
	}
}

struct node *delete_beg(struct node *start){
	//Node Perpindahan Head ke Node lain
	struct node *ptr;
	ptr = start;
	start = start -> next;//Head next ke node lain
	free(ptr);//Bebaskan Ptr
	return start;
}


int main(){
	int repeat=0;
	int choice;
	do{
		//Pengulangan Jika Variabel Repeat = 1
	system("cls");
	printf("----GENERAL CLINIC-----\n");
	printf("++++++++++++++++++++++\n\n");
	printf("1. List of Patient\n");
	printf("2. Add Patient\n");
	printf("3. Call Patient\n");
	printf("4. Exit\n\n");
	
	do{
		printf(">> Input your choice : ");
		scanf("%d",&choice);
	}while( choice < 1 || choice > 4 );
		system("cls");
		switch(choice){
			case 1:{
				system("cls");
				printf ("\t	--- General Clinic ---\n\n");
				//Panggil Struct Display dan di masukin (data)
				display(start);
				getch();
				repeat=1;
				break;
			}
			case 2:{
				system("cls");
				printf ("\t --- PATIENT DATA ---\n\n");
				if(start==NULL) //Jika Data = Null
				{
					//Membuat Node Data Costumer dgn memanggil Struct Create
					start=create(start);
				}
				else
				{
					insert_end(start);
				}
				count++;
				printf ("\n\n--- Add New Patients Success ---");
				repeat=1;
				getch();
				break;
			}
			case 3:{
				system("cls");
				//Jika Data = 0
				if(count==0){
					printf("\n\t\t there are no Patient available.");
					getch();
				}
				else
				{
					//menyediakan Node baru untuk di hapus
					struct node*n;
					n=start;
					start=delete_beg(start);
					printf("\n\t\tthe Patient being Examined. ");
					count--;
					//menghilangkan data
					getch();
				}repeat=1;
				break;
			}
			case 4:{
				return 0;
				repeat=0;
				break;
			}
		}
	}while(repeat==1);
}
