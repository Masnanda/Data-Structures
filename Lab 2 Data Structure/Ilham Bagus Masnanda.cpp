#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

void print(struct Node *p);

struct Node {
	int data;
	char CD[6];
	struct Node *next;
};
p
int main ()
{
	int choice;
	struct Node* head= NULL; //Di mulai dari empty list
	head=(struct Node*)malloc(sizeof(struct Node));//head=Alokasi data untuk data baru
	head->next=NULL;//head next = kosong
	head->data=0;//head data = kosong
	int repeat=1;//variabel pengulangan
	int count=0;//variabel untuk menambah atau mengurangi stack
	//pengulangan untuk program
	do {
	system ("cls");
	printf ("Jackie CD Stock\n___________\n\n");
 	printf (" CD Stock <STACK>\n");
 	print(head);//print head stack
 	printf ("\nOption : \n1. Stock of CD\n2. Sell a CD\n3. Exit\n\n");
 	printf (">> Input choice : ");
 		scanf ("%d",&choice);
 		//switch untuk ke case(menu) yang di sediakan
 		switch (choice)
 		{
 			case 1: {
 				if(count==0) //Kondisi Jika Pertama Kali memasukan data
				{
					char jenis[5];
					int benar=0;
				do{
					printf("\nInput CD type [rock/jazz/blues] : ");
					//user memasukan Jenis CD type yang di mau
					scanf("%s",jenis);
					if(strcmp("rock",jenis)==0||strcmp("jazz",jenis)==0||strcmp("blues",jenis)==0){
						benar=1;//Jika Strcmp benar maka Benar=1, Jadi akan keluar dari pengualangan Input jenis CD			
						}
					}while(benar==0);
					int jumlah;//Variabel yang di sediakan untuk Jumlah Kaset yang akan di input
					benar=0;//Variabel benar di set 0 lagi, untuk Input Jumlah CD
						do{
							printf("Input the number of songs on the CD [5...12] : ");
							scanf("%d",&jumlah);
							if(jumlah>4 && jumlah<13){
								benar=1;
							}
						}while(benar==0);
						//ada Tiga Kondisi, Tergantung dgn Inputan User di Input CD untuk mengisi Jenis di dalam Linked list 
							if(strcmp("rock",jenis)==0){
								strcpy(head->CD,"rock");
							}
							if(strcmp("jazz",jenis)==0){
								strcpy(head->CD,"jazz");
							}
							if(strcmp("blues",jenis)==0){
								strcpy(head->CD,"blues");
							}
							//Head di setting Head next data=jumlah;
							head->data=jumlah;
							//data(count) akan bertambah
							count++;
							printf("\n\t\t\tAdd CD Success");
							getch();
					}
						else
						{ // Jika data di atas 0 atau di bawah 10
						if(count>0 && count<10){
							//menyediakan Stack baru dgn Pointer Isi yang di set Kosong
							struct Node* isi= NULL;
							//Pointer Isi ini = Alokasi data baru yang di sediakan di awal program main
							isi=(struct Node*)malloc(sizeof(struct Node));
							//Dgn set Isi next = head
							isi->next=head;
							//head= isi
							head=isi;
							char jenis[5];
							int benar=0;
								do{
									printf("\nInput CD type [rock/jazz/blues] : ");
									scanf("%s",jenis);
									if(strcmp("rock",jenis)==0||strcmp("jazz",jenis)==0||strcmp("blues",jenis)==0){
										benar=1;			
										}
									}while(benar=0);
									int jumlah;
									benar=0;
										do{
											printf("\nInput the number of songs on the CD [5...12] :  ");
											scanf("%d",&jumlah);
											if(jumlah>4 && jumlah<13){
												benar=1;
											}
										}while(benar==0);
											if(strcmp("rock",jenis)==0){
												strcpy(head->CD,"rock");
											}
											if(strcmp("jazz",jenis)==0){
												strcpy(head->CD,"jazz");
											}
											if(strcmp("blues",jenis)==0){
												strcpy(head->CD,"blues");
											}
											head->data=jumlah;
											count++;
											printf("\n\t\t\tAdd CD Success");
											getch();
										}
											else	
												{
												printf("Stack Full");
												getch();
												}
											}
				break;
			 }
			 case 2: {
				/*struct Node *toDelete;
				if(count == 0)
    			{
        		printf("List is already empty.");
        		getch();
    			}
   	 			else
   			 	{
        			toDelete = head;
        			head = head->next;

        			printf("\nData deleted = %d\n", toDelete->data);

        			/* Clears the memory occupied by first node/
        			free(toDelete);

        			printf("SUCCESSFULLY DELETED FIRST NODE FROM LIST\n");
        			getch();*/
        		if(count==0)
				{
					//Jika data Nol(kosong)
					printf("--- The CD Storage is Empty ---");
					getch();
				}
				else
				{
					//Jika ada data maka head(Top) di setting Head Next
					head=head->next;
					printf("--- Sell CD Success ---");
					//data di kurangi dari top
					count--;
					getch();
				}
    		}
				break;
			case 3 : 
			{
			repeat=0;
			system("cls");
			printf ("Thank you for using this program");
			break;
			}
		}

	}while(repeat==1);
 	return 0;
}

//Modul/Function yang berguna untuk mengeprint Head Stack
void print(struct Node *Ptr)
{
	//Jika Ptr tidak Null dan Ptr Lebih dari 0
	if(Ptr!=NULL && Ptr->data>0){
		printf("[ %-6s CD : level %-3d ] --> [top]\n",Ptr->CD,Ptr->data);
		Ptr=Ptr->next;
	}
	while(Ptr != NULL){
		if(Ptr->data==0)
		{
			Ptr=Ptr->next;
		}
		else
		{
			printf("[ %-6s CD : level %-3d ]\n", Ptr->CD, Ptr->data);
			Ptr=Ptr->next;
		}
	}
}
