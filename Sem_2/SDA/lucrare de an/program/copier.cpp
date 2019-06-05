//copiere.cpp
int copiere()
{
f1 = fopen("deposit1.txt","r");
f2 = fopen("deposit2.txt","r");
f = fopen("fisier.txt","w");
fread(&produs1, sizeof(produs1), 1, f1);
while(!feof(f1))
{
	fwrite(&produit3, sizeof(produit3), 1, f);
    fread(&produs1, sizeof(produs1), 1, f1);
	}
fread(&produit2, sizeof(produit2), 1, f2);
while(!feof(f2))
{
	fwrite(&produit3, sizeof(produit3), 1, f);
    fread(&produit2, sizeof(produit2), 1, f2);
	}
fclose(f1);
fclose(f2);
fclose(f);
}
