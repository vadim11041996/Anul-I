//afisare.cpp
void fisier1()
{ system("Cls");
system("COLOR 9");
f1 = fopen("deposit1.txt","r+");
	printf("\n\n\n");
	printf("\t");
	puts("   Magazinul nostru ofera urmatoarele produse din depozitul 1 :\n\n");
    printf("           嬪様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�\n");
    printf("           � Nr � Categorie � Nume       � Cantitate� Tara     � Pret      �\n");
    printf("           塒様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�\n");
    i=1;
    fread(&produs1, sizeof(produs1),1, f1);
     while(!feof(f1))
    {printf("           �%4d�%11s�%12s� %9d�%10s�   %7.1f �\n",i, produs1.categorie, produs1.nume, produs1.cantitate, produs1.tara, produs1.pret);
    printf("           青陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�\n");i++;
	fread(&produs1, sizeof(produs1),1, f1);
    }
		  fclose(f1);
	 printf("\t\t");
     puts("      Pentru a reveni in meniul principal tastati <ENTER>");
	getch();
}

    void fisier2()
    { system("Cls");
    system("COLOR 9");
f2 = fopen("deposit2.txt","r+");
	printf("\n\n\n");
	printf("\t");
    puts("   Magazinul nostru ofera urmatoarele produse din depozitul  2 :\n\n");
    printf("           嬪様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�\n");
    printf("           � Nr � Categorie � Nume       � Cantitatev Tara     � Pret      �\n");
    printf("           塒様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�\n");
    i=1;
    fread(&produs1, sizeof(produs1), 1, f2);
     while(!feof(f2))
    {printf("           �%4d�%11s�%12s� %9d�%10s�   %7.1f �\n",i, produs1.categorie, produs1.nume, produs1.cantitate, produs1.tara, produs1.pret);
    printf("           青陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�\n");i++;
	fread(&produs1, sizeof(produs1), 1, f2);
    }
		  fclose(f2);
		  printf("\t\t");
     puts("      Pentru a reveni in meniul principal tastati <ENTER>");
	getch();
}
void  fisier()
{  system("Cls");
system("COLOR 9");
f1 = fopen("deposit1.txt","r+");
	printf("\n\n\n");
	printf("\t");
	puts("   Magazinul nostru ofera urmatoarele produse din ambele depozite :\n\n");
    printf("           嬪様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�\n");
    printf("           � Nr � Categorie � Nume       � Cantitate� Tara     � Pret      �\n");
    printf("           塒様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様�\n");
    i=1;
    fread(&produs1, sizeof(produs1),1, f1);
     while(!feof(f1))
    {printf("           �%4d�%11s�%12s� %9d�%10s�   %7.1f �\n",i, produs1.categorie, produs1.nume, produs1.cantitate, produs1.tara, produs1.pret);
    printf("           青陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�\n");i++;
	fread(&produs1, sizeof(produs1),1, f1);
    }
		  fclose(f1);
       f2 = fopen("deposit2.txt","r+");

    fread(&produs1, sizeof(produs1), 1, f2);
     while(!feof(f2))
    {printf("           �%4d�%11s�%12s� %9d�%10s�   %7.1f �\n",i, produs1.categorie, produs1.nume, produs1.cantitate, produs1.tara, produs1.pret);
    printf("           青陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳�\n");i++;
	fread(&produs1, sizeof(produs1), 1, f2);
    }
		  fclose(f2);
		  printf("\t\t");
     puts("      Pentru a reveni in meniul principal tastati <ENTER>");

	getch();
}
int afisare()
{
     char option;
     system("Cls");
     system("COLOR 6");
     printf("\n\n\n");
     printf("                    嬪様様様様様様様様様様様様様様様様様様様様様様様邑\n");
     printf("                    � Din care depozit doriti sa vedeti produsele?   �\n");
     printf("                    突様様様様様様様様様様様様様様様様様様様様様様様裕\n");
     printf("                    �          1.Deposit 1                           �\n");
     printf("                    団陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳調\n");
     printf("                    �          2.Deposit 2                           �\n");
     printf("                    団陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳陳調\n");
     printf("                    �          3.Depozitul 1+depozitul 2             �\n");
     printf("                    塒様様様様様様様様様様様様様様様様様様様様様様様余\n\n");
     printf("\t\t");
     puts("      Pentru a reveni in meniul principal tastati  <ENTER>");
     option = getch();
     switch(option)
     {
                   case '1' : fisier1();  break;
                   case '2' : fisier2();  break;
                   case '3' : fisier();   break;
}}
