#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <process.h>
#define d 10000;
#include <stdlib.h>

int a[100][100],F[100][100],n,i,j,x,total=0;
int H[100]={0};
int k=1,D[100];
void meniu();
void meniu2();
void meniuf();
void meniubk();
void i_lista(){
    int tmp;
	printf("Introduceti numarul de virfuri: ");
	scanf("%d",&n);
	printf("Introduceti Lista de adiacenta:\n");
    for(i=1;i<=n;i++){
	printf("%d   ",i);
	do{
	  scanf("%d",&tmp);
	  a[i][tmp]=1;}
	while((tmp!=0)||(tmp>n));
	a[i][tmp]=0;
    }
printf("\n");
}

void ponderile(){
    printf("Introduceti Ponderile :\n");
    for(i=1;i<=n;i++)
	for(j=1;j<=n;j++)
	    if(a[i][j]){
		printf("(%d-%d)     ",i,j);
		scanf("%d",&a[i][j]);
	    }
}

void d_min(){
    int test=1;
    for(i=2;i<=n;i++)
        H[i]=999;

    while(test==1){
	test=0;
	for(i=1;i<=n;i++)
	    for(j=1;j<=n;j++)
	       if(a[i][j]!=0)
		   if(H[j]-H[i]>a[i][j]){
                test=1;
		   H[j]=H[i]+a[i][j];}
		   else
		     if(H[j]-H[i]==a[i][j]) F[i][j]=1;
		     else F[i][j]=0;
    }

 if(H[n]!=999){
     printf("\nLungimea drumului minim este : %d\n",H[n]);
     printf("Drumurile sunt :\n");}
     else printf("Nu exista drum din 1 in %d.",n);
}

void d_max(){
    int test=1;
    for(i=2;i<=n;i++) H[i]=-999;

    while(test==1){
	test=0;
	for(i=1;i<=n;i++)
	    for(j=1;j<=n;j++)
	       if(a[i][j]!=0)
		   if(H[j]-H[i]<a[i][j]) {
                test=1;
           H[j]=H[i]+a[i][j];
           }
		   else
		     if (H[j]-H[i]==a[i][j]) {
                    F[i][j]=1;
             }
		     else F[i][j]=0;
    }

 if(H[n]!=-999){
     printf("\nLungimea drumului maxim este : %d\n",H[n]);
     printf("Drumurile sunt :\n");
     }
     else printf("Nu exista drum din 1 in %d.",n);
}

void afis(int x){
 int p;
  if(x==1) {D[0]=n;for(p=k-1;p>=0;p--)
    printf("%d ",D[p]);
  printf("\n");
  return;
  }
    for(p=1;p<=n;p++)
	if(F[p][x])
	    {D[k++]=p;
	     afis(p);
	      k--;}
getch();
meniubk();
}
void afis1(int x){
 int p;
  if(x==1) {
        D[0]=n;
  for(p=k-1;p>=0;p--)
    printf("%d ",D[p]);
  printf("\n");
  return;
  }
    for(p=1;p<=n;p++)
	if(F[p][x])
	    {D[k++]=p;
	     afis(p);
	      k--;}
getch();
meniuf();

}
void BK(){
 int tmp;
    printf("Introduceti numarul de virfuri: ");
    scanf("%d",&n);
    printf("Introdu Matricea Ponderilor:\n");
    for(i=1;i<=n;i++){
	printf("%d  ",i);
	for(j=1;j<=n;j++)
	    scanf("%d",&a[i][j]);
    }
}

void meniuf()
{
int key;
 printf(" \n [1] - Ford Minim \n [2] - Ford Maxim \n [3] - Inapoi \n");
 printf("\n\n\nOptiunea Selectata este : ");
    scanf("%d",&key);
 switch (key)
     {
      case 1: {
          i_lista();
           ponderile();
            d_min();
             if(H[n]!=999) {
                 afis1(n);
             }
             break;
             }
      case 2: {
          i_lista();
          ponderile();
           d_max();
            if(H[n]!=-999){
                    afis1(n);
            }
             break;
            }
      case 3:
           meniu2();
       getch();
      case 0: return;
     }
}
void meniubk()
{
int key;
 printf(" \n [1] - Bellman-Kalaba Minim \n [2] - Bellman-Kalaba Maxim \n [3] - Inapoi ");
 printf("\n\n\nOptiunea Selectata este : ");
    scanf("%d",&key);
 switch (key)
     {
      case 1: {
          i_lista();
      ponderile();
      d_min();
      if(H[n]!=999) {
            afis(n);
      }
      break;
      }
      case 2: {
          i_lista();
           ponderile();
            d_max();
            if(H[n]!=-999){
                    afis(n);
            }
            break;
            }
      case 3:
          meniu2();
           getch();
	 }
}
void meniu2(){
int key;
 printf(" \n [1] - Ford \n [2] - Bellman-Kalaba \n [0] - Exit \n");
 printf("\n\n\nOptiunea Selectata este : ");
    scanf("%d",&key);
 switch (key)
     {
      case 1: meniuf();
      case 2: meniubk();
      case 0: getch();
     }
 }
int main()
{
    system("Color 21");
meniu2();
}
