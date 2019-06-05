//afisare.cpp
void fisier1()
{ system("Cls");
system("COLOR 9");
f1 = fopen("deposit1.txt","r+");
	printf("\n\n\n");
	printf("\t");
	puts("   Magazinul nostru ofera urmatoarele produse din depozitul 1 :\n\n");
    printf("           ีอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออธ\n");
    printf("           ณ Nr ณ Categorie ณ Nume       ณ Cantitateณ Tara     ณ Pret      ณ\n");
    printf("           ิอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออพ\n");
    i=1;
    fread(&produs1, sizeof(produs1),1, f1);
     while(!feof(f1))
    {printf("           ณ%4dณ%11sณ%12sณ %9dณ%10sณ   %7.1f ณ\n",i, produs1.categorie, produs1.nume, produs1.cantitate, produs1.tara, produs1.pret);
    printf("           ภฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤู\n");i++;
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
    printf("           ีอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออธ\n");
    printf("           ณ Nr ณ Categorie ณ Nume       ณ Cantitatev Tara     ณ Pret      ณ\n");
    printf("           ิอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออพ\n");
    i=1;
    fread(&produs1, sizeof(produs1), 1, f2);
     while(!feof(f2))
    {printf("           ณ%4dณ%11sณ%12sณ %9dณ%10sณ   %7.1f ณ\n",i, produs1.categorie, produs1.nume, produs1.cantitate, produs1.tara, produs1.pret);
    printf("           ภฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤู\n");i++;
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
    printf("           ีอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออธ\n");
    printf("           ณ Nr ณ Categorie ณ Nume       ณ Cantitateณ Tara     ณ Pret      ณ\n");
    printf("           ิอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออพ\n");
    i=1;
    fread(&produs1, sizeof(produs1),1, f1);
     while(!feof(f1))
    {printf("           ณ%4dณ%11sณ%12sณ %9dณ%10sณ   %7.1f ณ\n",i, produs1.categorie, produs1.nume, produs1.cantitate, produs1.tara, produs1.pret);
    printf("           ภฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤู\n");i++;
	fread(&produs1, sizeof(produs1),1, f1);
    }
		  fclose(f1);
       f2 = fopen("deposit2.txt","r+");

    fread(&produs1, sizeof(produs1), 1, f2);
     while(!feof(f2))
    {printf("           ณ%4dณ%11sณ%12sณ %9dณ%10sณ   %7.1f ณ\n",i, produs1.categorie, produs1.nume, produs1.cantitate, produs1.tara, produs1.pret);
    printf("           ภฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤู\n");i++;
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
     printf("                    ีออออออออออออออออออออออออออออออออออออออออออออออออธ\n");
     printf("                    ณ Din care depozit doriti sa vedeti produsele?   ณ\n");
     printf("                    ฦออออออออออออออออออออออออออออออออออออออออออออออออต\n");
     printf("                    ณ          1.Deposit 1                           ณ\n");
     printf("                    รฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤด\n");
     printf("                    ณ          2.Deposit 2                           ณ\n");
     printf("                    รฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤด\n");
     printf("                    ณ          3.Depozitul 1+depozitul 2             ณ\n");
     printf("                    ิออออออออออออออออออออออออออออออออออออออออออออออออพ\n\n");
     printf("\t\t");
     puts("      Pentru a reveni in meniul principal tastati  <ENTER>");
     option = getch();
     switch(option)
     {
                   case '1' : fisier1();  break;
                   case '2' : fisier2();  break;
                   case '3' : fisier();   break;
}}
