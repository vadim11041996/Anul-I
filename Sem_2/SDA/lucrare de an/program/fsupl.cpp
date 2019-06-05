//fsupl.cpp
void fsupl()
{system("Cls");
system("COLOR 4");
printf("\n\n\n\n\n\n\n\n");
printf("\t\t");
printf("Fisierul suplimentar a fost efectuat cu succes !!!");
			  f1 = fopen("deposit1.dat","r");
f2 = fopen("deposit2.dat","r");
f = fopen("fisier.dat","w");
fread(&produs1, sizeof(produs1), 1, f1);
while(!feof(f1))
{
	fwrite(&produs1, sizeof(produs1), 1, f);
    fread(&produs1, sizeof(produs1), 1, f1);
	}
fread(&produs1, sizeof(produs1), 1, f2);
while(!feof(f2))
{
	fwrite(&produs1, sizeof(produs1), 1, f);
    fread(&produs1, sizeof(produs1), 1, f2);
	}
fclose(f1);
fclose(f2);
fclose(f);
getch();
}
