//adaugare.cpp
 void adaugarefis1()
{ int t=1;
    system("Cls");
system("COLOR 9");
printf("Dati numarul de produse  :   ");
	scanf("%d",&n);
	f1=fopen("deposit1.txt","a");
	for(i = 0; i <  n; i++)
	{  printf("\n\n\n");
     printf("     ีออออออออออออออออออออออธ\n");
     printf("     ณ   Adaugarea nr%d      ณ\n",t);
     printf("     ิออออออออออออออออออออออพ\n\n");
     printf("\t\t");
     printf("\nDati categoria :  ");
	 scanf("%s",&produs1.categorie);fflush(stdin);
	 printf("\nDati numele produsului :  ");
	 scanf("%s",&produs1.nume);fflush(stdin);
	 printf("\nDati cantitatea :  ");
	 scanf("%d",&produs1.cantitate);fflush(stdin);
	 printf("\nDati tara de provenienta :  ");
	 scanf("%s",&produs1.tara);fflush(stdin);
	 printf("\nDati pretul produsului :  ");
	 scanf("%f",&produs1.pret);fflush(stdin);
	fwrite(&produs1, sizeof(produs1), 1, f1);
	t++;
	}
	fclose(f1);
    system("Cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("\t\t");
	puts("       Adaugarea a fost cu succes!!!\n\a");
	printf("\t\t");
    puts("      Pentru a reveni la meniul principal tastati <ENTER>");
	getch();
}

void adaugarefis2()
{ int r=1;
system("Cls");
system("COLOR 12");
printf("     Dati numarul de produse :\n ");
	scanf("%d",&n);
	f2 = fopen("deposit2.txt","a");
	for(i = 0; i <  n; i++)
	{
	     printf("\n\n\n");
     printf("     ีอออออออออออออออออออออออธ\n");
     printf("     ณ   Adaugarea nr%d       ณ\n",r);
     printf("     ิอออออออออออออออออออออออพ\n\n");
     printf("\t\t");
     printf("Dati categoria :  ");
	 scanf("%s",&produs1.categorie);fflush(stdin);
	 printf("Dati numele produsului :  ");
	 scanf("%s",&produs1.nume);fflush(stdin);
	 printf("\nDati cantitatea :   ");
	 scanf("%d",&produs1.cantitate);fflush(stdin);
	 printf("\nDati tara e provenienta:  ");
	 scanf("%s",&produs1.tara);fflush(stdin);
	 printf("\nDati pretul produsului :  ");
	 scanf("%f",&produs1.pret);fflush(stdin);
	fwrite(&produs1, sizeof(produs1), 1, f2);
	r++;
	}
	fclose(f2);
	system("Cls");
    printf("\n\n\n\n\n\n\n\n");
    printf("\t\t");
	printf("    Adaugarea a fost cu succes !!!\n\a\a");
	printf("\t\t");
	puts("      Pentru a reveni la meniul principal tastati <ENTER>");
	getch();
}

void adaugare()
{
     char option;
     system("Cls");
     system("COLOR 9");
     printf("\n\n\n");
     printf("                    ีอออออออออออออออออออออออออออออออออออออออออออออออธ\n");
     printf("                    ณ   In care depozit doriti sa adaugati?         ณ\n");
     printf("                    ฦอออออออออออออออออออออออออออออออออออออออออออออออต\n");
     printf("                    ณ               1.Deposit 1                     ณ\n");
     printf("                    รฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤด\n");
     printf("                    ณ               2.Deposit 2                     ณ\n");
     printf("                    ิอออออออออออออออออออออออออออออออออออออออออออออออพ\n\n");
     printf("\t\t");
     puts("    Pentru a reveni la meniul principal tastati <ENTER>\n");
     option = getch();
     switch(option)
     {
                   case '1' : adaugarefis1(); break;
                   case '2' : adaugarefis2(); break;
                   }

}
