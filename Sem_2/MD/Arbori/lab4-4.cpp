#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>
#define N 20
#define M 20
#define E 50

typedef struct nod{int v;
		   struct nod *next;
		   }NOD;
NOD *k,*h[E],*p;
void IntrListAdiac(int n);
void ListAdiac(int n);
void Adincime(int n);
void Latime(int n);


int main()
{


int d,n,m;
printf("\n Cite virfuri are graful ? ");
scanf("%d",&n);
printf("\n Cite arce sunt in graf ?");
scanf("%d",&m);
Meniu2:
while(1){
printf("\n \n \n");
  printf("\r               ษอออออออออออออออออออออออออออออออออออออออออออออป   \n");
  printf("\r               บ                                             บ");
  printf("\n\r               บ 1->Introducerea listei de adiacenta.        บ ");
  printf("\n\r               บ 2->Afisarea listei de adiacenta.            บ  ");
  printf("\n\r               บ 3->Parcurgerea grafului in adincime.        บ ");
  printf("\n\r               บ 4->Parcurgerea grafului in latime           บ" );
  printf("\n\r               บ 5->Exit.                                    บ");
  printf("\n\r               บ                                             บ \n") ;
  printf("\r               ศอออออออออออออออออออออออออออออออออออออออออออออผ   \n");
printf("\n\n\n\n\n Alegeti una dintre optiuni:");
scanf("%d",&d);
switch(d){
case 1:{IntrListAdiac(n);break;}
case 2:{ListAdiac(n);break;}
case 3:{Adincime(n);break;}
case 4:{Latime(n);break;}
case 5:{exit(0);break;}
default :goto Meniu2;
}}}

void IntrListAdiac(int n)
{
int i,j;
printf("Introduceti lista de adiacenta\n");
for(i=0;i<n;i++){
h[i]=(NOD*)malloc(sizeof(*h));
k=h[i];

printf("\nIntroduceti legaturile pentru nodul: <%d>  ",i+1);
printf("Valorile mai mici sau egale cu %d !!!\n",n);
while(1){
scanf("%d", &k->v);
if(k->v==0){
k->next=NULL;
break;
}
p=(NOD*)malloc(sizeof(*p));
k->next=p;
k=p;}}}
//********************************************************************
void ListAdiac(int n)
{
int i;
printf("\n\n Ati introdus urmatoarea lista de adiacenta:\n\n\n");
for (i=0;i<n;i++){
k=h[i];
printf("\n   %i-> ",i+1);
while(1){
printf("%d ",k->v);
if(k->v==0)break;
k=k->next;
}
printf("\n\n");
}
getch();
}
//**********************************************************************
void Adincime(int n)
{int i,f,u,m;
NOD *r,*g,*a,*t[E];
u=0;
for(i=0;i<n;i++)
t[i]=h[i];
g=(NOD*)malloc(sizeof(NOD));
printf("\n Din care nod doriti sa incepeti parcurgerea ?: ");
scanf("%d",&f);
g->v=f;
g->next=NULL;
a=g;
printf("x%d",f);
r=t[f-1];
while(g!=NULL)
{
if(r->v!=0){r=t[f-1];
if(r->v!=0){printf("\t x%d",r->v);u++;
t[f-1]=t[f-1]->next; f=r->v;
g=(NOD*)malloc(sizeof(NOD));
g->v=r->v;
g->next=a;
a=g;}}
else if(r->v==0){a=a->next;free(g);g=a;f=a->v;r=t[f-1];
}
}
getch();}
//*********************************************************************
void Latime(int n)
{
int i=0,r;
NOD *k,*t,*o,*l;
t=(NOD*)malloc(sizeof(NOD));
printf("Din care nod doriti sa incepeti parcurgerea ?: ");
scanf("%d",&r);
printf("%d",r);
t->v=r;
t->next=NULL;
k=t;
l=t;
while((t!=0)&&(k!=0))
{
if(i==0){o=h[r-1];i=1;
}
if(o->v!=0)
{
printf("\tx%d",o->v);
t=(NOD*)malloc(sizeof(NOD));
t->v=o->v;
t->next=NULL;
l->next=t;
l=t;
o=o->next;
}
else if(o->v==0) {o=k->next;free(k);k=o;
r=k->v;i=0;
}
}
getch();
}
