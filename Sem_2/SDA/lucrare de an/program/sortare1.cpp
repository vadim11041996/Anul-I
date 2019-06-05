//sortare1.cpp
void sortare1()
{
system("cls");
system("color 9");
printf("Sortarea a fost facuta dupa denumire.");
pf = fopen("fisier1.txt","w+");

alimentar x[100],aux;
int i = -1;
while(!feof(pf)){
i++;
fseek(pf, (i)*sizeof(produs1),SEEK_SET);
fread(&produs1,sizeof(produs1),1,pf);
x[i] = produs1;
} n=i;
for(i = 0; i < n-1; i++){
    for(j = i+1; j < n; j++){
        if(strcmp(x[i].nume,x[j].nume)>0){
            aux = x[i];
            x[i] = x[j];
            x[j] = aux;
        }
    }
}
if((pa = fopen("sortare.txt","w+"))==NULL){
    printf("Nu se deschide!");
    exit(1);
}
fseek(pa, (0)*sizeof(produs1),SEEK_SET);
for(i = 0; i < n; i++){
    fwrite(&x[i],sizeof(produs1),1,pa);
}
for(i = 0; i < n;i++){
        printf("structura:");
printf("%s %s %s %f %s ",&x[i].categorie,&x[i].nume,x[i].cantitate,&x[i].pret,&x[i].tara);
}
fclose(pa);
fclose(pf);
getch();
}





