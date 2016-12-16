#include <stdio.h>
#include <stdlib.h>
#include "list.h"

void Write_to_file (FILE *fp, DataType data);
void Read_frm_file (FILE *fp, List L);
void Menu (void);
void Input (List L, DataType *data);
int main (void)
{
	List list;
	Initialize (&list);
	DataType data;

	FILE *fp1;
	fp1 = fopen ("data.dat", "a+");
	Read_frm_file (fp1, list);

	char choice;
	FILE *fp;
	fp = fopen ("data.dat", "a+");
	for (;;)
	{
		Menu();
		printf ("Please enter your choice: ");
		choice = getchar ();
		getchar ();

		switch (choice)
		{
			case '1':
				Input (list, &data);
				Write_to_file (fp, data);
				break;
			case '2':
				Display (list);
				break;
			case '3':
				Statistics (list);
				break;
			case '4':
				printf ("Quit!!!\n");
				fclose (fp);
				return 0;
			default:
				printf ("Please enter 1 to 4!!!!\n");
				continue;
		}
	}

}

void Write_to_file (FILE *fp, DataType data)
{
	fprintf (fp, "%5d  %15s  %15s  %3d  %5.1f  %15s  %15s  %15s\n", data.num, data.name, data.from, data.count, data.price, data.date_of_product, data.date_of_purchase, data.people);
}

void Read_frm_file (FILE *fp, List L)
{
	DataType data;

	while (!feof(fp))
	{
	    fscanf (fp, "%d%s%s%d%f%s%s%s", &data.num, &data.name, &data.from, &data.count, &data.price, &data.date_of_product, &data.date_of_purchase, &data.people);
	    Insert (L, data);
	}
	Delete (L);
	
	fclose (fp);
}

void Menu (void)
{
	printf ("1. Input the imformation of the production.\n");
	printf ("2. Output all the productions.\n");
	printf ("3. Statistics and Analyze.\n");
	printf ("4. Quit.\n");
}

void Input (List L, DataType *data)
{
	printf ("input the number and the name: ");
	scanf ("%d%s", &data->num, &data->name);
	getchar ();
	printf ("input the factory that the production from: ");
	scanf ("%s", &data->from);
	getchar ();
	printf ("input the count of the production and the price of one production: ");
	scanf ("%d%f", &data->count, &data->price);
	getchar ();
	printf ("input the date of the product and the date of purchase: ");
	scanf ("%s%s", &data->date_of_product, &data->date_of_purchase);
	getchar ();
	printf ("input the people that the production had followed: ");
	scanf ("%s", &data->people);
	getchar ();
	Insert (L, *data);
}
