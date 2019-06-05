//modificare.cpp
void modificare1()
{
	system("Cls");
	system("COLOR 09");
	int nn1;
	f1 = fopen("deposit1.dat","r+");
	while(1)
	{
	printf("Indicati numarul produsului :  ");
		scanf("%d",&nn1); fflush(stdin);
		if(nn1 == 0) {fclose(f1); break;}
		fseek(f1, (nn1 - 1)*sizeof(produs1), SEEK_SET);
		fread(&produs1, sizeof(produs1), 1, f1);
		printf("Pretul initial : %7.1f \n",produs1.pret);
		printf("Da-ti pretul corect  :  ");
		scanf("%f",&produs1.pret);
		printf("\n\n\nFisierul a fost modificat cu succes!!!\n\n\a");
	fseek(f1, (nn1 - 1)*sizeof(produs1), SEEK_SET);
	fwrite(&produs1,sizeof(produs1), 1, f1);
	}
	fclose(f1);
}
void modificare2()
{ system("Cls");
system("COLOR 09");
	int nn2;
	f2 = fopen("deposit2.dat","r+");
	while(1)
	{
	printf("Indicati numarul produsului :  ");
		scanf("%d",&nn2); fflush(stdin);
		if(nn2 == 0) {fclose(f); break;}
		fseek(f2, (nn2 - 1)*sizeof(produs1), SEEK_SET);
		fread(&produs1, sizeof(produs1), 1, f2);
		printf("\nPretul initial : %7.1f \n",produs1.pret);
		printf("Dati pretul corect  :  ");
		scanf("%f",&produs1.pret);
		printf("\n\n\nFisierul a fost modificat cu succes !!!\n\n\a\a");
	fseek(f2, (nn2 - 1)*sizeof(produs1), SEEK_SET);
	fwrite(&produs1,sizeof(produs1), 1, f2);
	}
	fclose(f2);
}
void modificare()
{
	char option;
	system("Cls");
	system("COLOR 09");
	printf("\n\n\n");
	printf("                    ีออออออออออออออออออออออออออออออออออออออออออออออออธ\n");
	printf("                    ณ     In care depozit doriti sa modificati?      ณ\n");
	printf("                    ฦออออออออออออออออออออออออออออออออออออออออออออออออต\n");
	printf("                    ณ                1.Deposit 1                     ณ\n");
	printf("                    รฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤฤด\n");
	printf("                    ณ                2.Deposit 2                     ณ\n");
	printf("                    ิออออออออออออออออออออออออออออออออออออออออออออออออพ\n\n");
	printf("\t\t");
    puts("    Pentru a reveni la meniul principal tastati <ENTER>\n");
	option = getch();
	switch(option)
	{
	case '1': modificare1(); break;
	case '2': modificare2(); break;
	}
	getch();
}


