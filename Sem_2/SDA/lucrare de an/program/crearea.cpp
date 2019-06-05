//crearea.cpp
void crearea ()
{ system("Cls");
system("COLOR 09");
//fisier 1
printf("Indicati numarul de produse din depozitul 1 :  ");
	scanf("%d",&n);
	int nr=1;
	f1 = fopen("deposit1.txt","w");
	for(i = 0; i <  n; i++)
	{
     printf("\n\n\n");
     printf("     ีอออออออออออออออออออออออออออธ\n");
     printf("     ณ   Inregistrarea nr%d       ณ\n",nr);
     printf("     ิอออออออออออออออออออออออออออพ\n\n");
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
	nr++;
	}
	fclose(f1);
//fisier 2
	printf("\nA fost introdus cu succes in fisierul 1!!!\n\n\a\n\n");
    printf("Se indica numarul de produse din depozitul 2 :  ");
	scanf("%d",&n);
	int nr_2=1;
	f2 = fopen("deposit2.txt","w");
	for(i = 0; i <  n; i++)
	{
	    printf("\n\n\n");
     printf("     ีอออออออออออออออออออออออออออธ\n");
     printf("     ณ   Inregistrarea nr%d       ณ\n",nr_2);
     printf("     ิอออออออออออออออออออออออออออพ\n\n");
     printf("\t\t");
	 printf("\nDati categoria :  ");
	 scanf("%s",&produs1.categorie);fflush(stdin);
	 printf("\nDati numele produsului  :  ");
	 scanf("%s",&produs1.nume);fflush(stdin);
	 printf("\nDati cantitatea :  ");
	 scanf("%d",&produs1.cantitate);fflush(stdin);
	 printf("\nDati tara de provenienta :  ");
	 scanf("%s",&produs1.tara);fflush(stdin);
	 printf("\nDati pretul produsului  :  ");
	 scanf("%f",&produs1.pret);fflush(stdin);
	fwrite(&produs1, sizeof(produs1), 1, f2);
	nr_2++;
	}
	fclose(f2);
	printf("\nA fost introdus cu succes in fisierul 2!!!\n\n\a\a");
	getch();

}



