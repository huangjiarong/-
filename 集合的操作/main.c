#include "set.h"
#include <stdio.h>

void Menu (void)
{

	printf ("1. Get the Union of two sets.\n");
	printf ("2. Get the Intersection of two sets.\n");
	printf ("3. Get the Symmetric difference of two sets.\n");
	printf ("4. Quit.\n");
}

void Get_two_set (Set s1, Set s2)
{
	printf ("The first set is : ");
	Display (s1);
	printf ("\n");
	printf ("The second set is : ");
	Display (s2);
	printf ("\n");
}

int main (void)
{
	Set s1, s2;
	Initialize (&s1);
	Initialize (&s2);

	printf ("Please input the first set :");
	int tmp;
	while (scanf("%d", &tmp) != EOF)
	{
		Insert (s1, tmp);
	}
	printf ("\n");

	printf ("Please input the second set :");
	while (scanf("%d", &tmp) != EOF) //从键盘模拟EOF结束输入
	{
		Insert (s2, tmp);
	}
	printf ("\n");
	Get_two_set (s1, s2);

	char choice;
	for (;;)
	{
		Menu ();
	    printf ("Please input your choice : ");
		choice = getchar ();
		getchar (); //读取回车键产生的换行符
		switch (choice)
		{
			case '1':
				Get_two_set (s1, s2);
				printf ("The union of two set is : ");
				Display (Union(s1, s2));
				printf ("\n\n");
				break;
			case '2':
				Get_two_set (s1, s2);
				printf ("The intersection of two set is : ");
				Display (Intersection(s1, s2));
				printf ("\n\n");
				break;
			case '3':
				Get_two_set (s1, s2);
				printf ("The symmetrice difference of two set is : ");
				Display (Symmetric_diff(s1, s2));
				printf ("\n\n");
				break;
			case '4':
				printf ("Exit!!!\n");
				return 0;
			default :
				printf ("Please input 1 to 4 !!!\n\n");
				break;
		}
	}
}
