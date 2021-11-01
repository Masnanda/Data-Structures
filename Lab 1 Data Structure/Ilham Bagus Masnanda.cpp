#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>

void load_data();
void print_data();
void save_data();

int pilih,Sell,stok,total;
char code[6],ncode[6];

struct barang {
	char kode[6];
	char nama [10];
	int jumlah;
	int harga;
}barang[1000];

int main ()
{
	load_data();
	printf ("BRIGHT FLOWER SHOP CASHIER \n========================\n\n");
	print_data();
	printf ("\n\n 1. Sell\n 2. Add Stock\n 3. EXIT\n");
	do {
		 printf (" Input choice : ");
		 scanf ("%d",&pilih);
		}while (pilih<1 || pilih >3);
			switch (pilih){
				case 1:
					{
						printf("\nInput Flower Code [5 Chars] : ");
						scanf ("%s",&code);
						for (int i=0;i<4;i++)
						{
							if (strcmp(barang[i].kode,code)==0)
							{
								do {
									printf ("Input Quantity [1...%d]: ", barang[i].jumlah);
									scanf("%d",&Sell);
								}while (Sell<0);
								if (Sell < barang[i].jumlah)
								{
									total = Sell * barang[i].harga;
									printf ("Total Price is : %d x %d = Rp. %d",barang[i].harga,Sell,total);
									printf ("\n\n--- Thank You ---");
									barang[i].jumlah = barang[i].jumlah-Sell;
									save_data();
									return 0;
								}else
									printf ("Quantity Not Enough");
									return 0;
							}
							if (strcmp(barang[i].kode,code)!=0 && i==3)
							{
								printf ("\n--- The Flower Code doesn't exist ---");
							}
						}
					}break;
					case 2:
						{
							printf ("\nInput Flower Code [5 chars]: ");
								scanf("%s",&ncode);
								for (int i=0;i<4;i++)
								{
									if (strcmp(barang[i].kode,ncode)==0)
									{
										do
										{
											printf ("Input Quantity [1..10]: ");
											scanf ("%d",&stok);
										}while (stok<0 || stok>10);
											printf("\n\n--- Adding Stock Success ---");
											barang[i].jumlah = barang[i].jumlah + stok;
											save_data();
											return 0;
									}
									if (strcmp(barang[i].kode,ncode)!=0 && i==3)
										{
											printf ("\n--- The Flower Code doesn't exist ---");
										}
								}
						}break;
						case 3:
							{
							}break;
			}
	return 0;
}

int i=0;
void load_data()
{
	FILE *data;
	data=fopen ("stok.txt","r");
	while (fscanf(data,"%s %s %d %d",&barang[i].kode,&barang[i].nama,&barang[i].jumlah,&barang[i].harga)!=EOF){
	i++;
	}
	fclose(data);
}

void print_data()
{	
	printf ("\nNo  | Kode              | Nama            | Jumlah | Harga         |");
	printf ("\n====================================================================");
	for (int j=0;j<i;j++)
	{
		printf ("\n%-3d | %-17s | %-15s | %-7d | Rp. %-8d |",j+1,barang[j].kode,barang[j].nama,barang[j].jumlah,barang[j].harga);
	}
	printf ("\n====================================================================");
}

void save_data()
{
	FILE *data;
	data = fopen ("stok.txt","w");
	int i=0;
	do
	{
		fprintf (data,"%s %s %d %d",barang[i].kode,barang[i].nama,barang[i].jumlah,barang[i].harga);
		i++;
	}
	while (i<4);
		fclose (data);
}
