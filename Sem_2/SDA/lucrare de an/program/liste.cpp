#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
FILE *pf;
struct alimentar{
	char categorie[20];
	char nume[20];
	 int cantitate;
	 float pret;
	 char tara[20];
	}produs1, produs11;
typedef struct nod{
    struct alimentar_produs1;
    struct  nod *link;
}NOD;

int main(){
int n,i,m,j;
NOD *p,*u,*q,*p2,*u2,*q2;
system("cls");
if((pf=fopen("test1.txt","a+"))== NULL){
    printf("Eroare!!!");
}   else {
printf("Nr de noduri a listei  1 : ");
 scanf("%d",&n);
p=(NOD*)malloc(sizeof(NOD));
printf("nod 1 = ");
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
	 fwrite(&produs1, sizeof(produs1), 1, pf);
p->link=NULL;
u=p;
for(i=2;i<=n;i++)
{    q=(NOD*)malloc(sizeof(NOD));
    printf("nod %d = ",i);
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
	 fwrite(&produs1, sizeof(produs1), 1, pf);
    q->link=NULL;
    u->link=q;
    u=q;
}}
fclose(pf);
system("cls");
if((pf=fopen("test1.txt","a+"))== NULL){
    printf("Eroare!!!");
}  else{
printf("Nr de noduri a listei  2 : ");
scanf("%d",&m);
p2=(NOD*)malloc(sizeof(NOD));
printf("nod 1 = ");
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
	 fwrite(&produs1, sizeof(produs1), 1, pf);
p2->link=NULL;
u2=p2;
for(i=2;i<=m;i++)
{    q2=(NOD*)malloc(sizeof(NOD));
    printf("nod %d = ",i);
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
	 fwrite(&produs1, sizeof(produs1), 1, pf);
    q2->link=NULL;
    u2->link=q2;
    u2=q2;
}}
fclose(pf);
system("Cls");
pf = fopen("test1.txt","r+");
	printf("\n\n\n\t");
	puts("   Magazinul nostru ofera urmatoarele produse   :\n\n");
    printf("           -----------------------------------------------------------------\n");
    printf("           | Nr | Categorie | Nume       | Cantitate| Tara     | Pret      |\n");
    printf("           -----------------------------------------------------------------\n");
    i=1;
    fread(&produs1, sizeof(produs1),1, pf);
     while(!feof(pf))
    {printf("           |%4d|%11s|%12s| %9d|%10s|   %7.1f |\n",i, produs1.categorie, produs1.nume, produs1.cantitate, produs1.tara, produs1.pret);
    printf("           -----------------------------------------------------------------\n");i++;
	fread(&produs1, sizeof(produs1),1, pf);
    }
    fclose(pf);
getch();
}
