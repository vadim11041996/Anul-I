#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 30000
//===================================================================
	 // Declararea structurilor si variabilelor globale
struct List{
	int v;
	int w;
	struct List *next;
         };
struct Graph{
	int h;
	int p;
	struct List *first;
	struct List *last;
         }*G;
int N,V;
//-------------------------------------------------------------------
		       /* Initializarea functiilor */
void F();
void BK();
void Fm();
void main2();
void Menu();
void Prezt();
void ListAd();
void ElebList();
void DrumFord(int);
//-------------------------------------------------------------------
		          /* Corpul principal */
int main()
{ Prezt();
   Menu();
}
//-------------------------------------------------------------------
	                /* Algoritmul drum minim Ford */
void F()
{ int i,f=1;
  struct List *c;
  if(G==NULL) return;
  for(i=0;i<N;i++)
  { G[i].p=-1;
     G[i].h=MAX;
  }
  printf("\n\t");
  printf("Dati virful initial: ");
  scanf("%d",&V);
  G[--V].h=0;
  while(f)
  { f=0;
     for(i=0;i<N;i++)
     { c=G[i].first;
         while(c!=G[i].last)
         { if(G[c->v].h>G[i].h+c->w)
            { G[c->v].h=G[i].h+c->w;
              G[c->v].p=i;
	f=1;
            }
            c=c->next;
         }
      }
   }
   for(i=0;i<N;i++)
   { printf("\n  Drum min din %d in %d este",V+1,i+1);
      if(G[i].h==MAX) {
            printf(" nu exista.");}
       else
       { DrumFord(i);
         printf(" : Are lungimea %d.\r",G[i].h);

       }
   }
}
//-------------------------------------------------------------------
                   /* Algoritmul drum minim Belman-Kalaba */
void BK()
{ int *t,i,j,k,f=1;
   struct List *c;
   int *P=(int *)malloc(N*sizeof(int ));
   int *VK=(int *)malloc(N*sizeof(int ));
   int **M=(int **)malloc(N*sizeof(int *));
   int *VK_1=(int *)malloc(N*sizeof(int ));
   for(i=0;i<N;i++) M[i]=(int *)malloc(N*sizeof(int));
   for(i=0;i<N;i++)
    for(j=0;j<N;j++) M[i][j]=(i==j)?0:MAX;
   for(i=0;i<N;i++)
   { c=G[i].first;
     while(c!=G[i].last)
     { M[i][c->v]=c->w;
        c=c->next;
     }
   }
   printf("\n\t");
   printf("Dati virful final: ");
   scanf("%d",&V);
   V--;
   for(i=0;i<N;i++)
   { VK_1[i]=M[i][V];
      P[i]=-1;
   }
   while(f)
   { for(i=0;i<N;i++) VK[i]=MAX;
      for(i=0;i<N;i++)
       for(j=0;j<N;j++)
        if(i!=j && VK[i]>VK_1[j]+M[i][j])
       { VK[i]=VK_1[j]+M[i][j];
          P[i]=j;
       }
     VK[V]=0;
      for(i=0;i<N && VK[i]==VK_1[i];i++);
      f=(i==N)?0:1;
      t=VK_1; VK_1=VK; VK=t;
   }
   for(i=0;i<N;i++)
   { printf("\n  Drumul min din %d in %d este",i+1,V+1);
      if(VK_1[i]==MAX) {printf(" nu exista.");}
       else
       { for(k=i,j=0;j<N && P[k]!=-1 && k!=V;j++)
          { if(!j) printf(": %d",k+1);
             else printf("->%d",k+1);
             k=P[k];
          }
          if(i<N-1) printf("->%d",V+1);
           else printf(": %d",V+1);
          printf(" : Are lungimea: %d.\r",VK_1[i]);
       }
   }
   for(i=0;i<N;i++) free(M[i]);
   free(P); free(M); free(VK); free(VK_1);
}
//-------------------------------------------------------------------
                                        /* Meniul principal */
void Menu()
{ int m;

   printf("\n\
		--------------------------------------------»\n\
		є               [ MENIU ]                  є\n\
		---------------------------------------------%c\n\
		є [1] - Introducerea grafului:  ( LstAd ). є\n\
		є                                          є\n\
		є [2] - Drum minim:          (Alg. Ford ). є\n\
		є                                          є\n\
		є [3] - Drum minim:   (Alg.Belman-Kalaba). є\n\
		є                                          є\n\
		є [4] - Drum maxim:          (Alg. Ford ). є\n\
		є                                          є\n\
		є [5] - Drum maxim:   (Alg.Belman-Kalaba). є\n\
		є                                          є\n\
		є Esc - Iesirea.                           є\n\
		--------------------------------------------ј\n",185);
   do m=getch();
   while((m<49 || m>53) && m!=27);
   switch(m) {
    case 49: ListAd();      break;
    case 50: F(); getch();  break;
    case 51: BK(); getch(); break;
    case 52: main2();getch(); break;
    case 53: main2();getch();break;
    case 27: ElebList();   return;
  }
  Menu();
}
//-------------------------------------------------------------------
			/* Prezentarea temei */
void Prezt()
{
   printf("\n\n\n\n\t\t");
   printf("Lucrare de laborator Nr4 la Matematica Discreta.");
   printf("\r\n\n\t\t\t\t");
   printf("Drum minim.");
   getch();
}
//-------------------------------------------------------------------
	     /* Lista de adiacenta si matricea ponderilor*/
void ListAd()
{ int i,v,w;
  struct List *c;
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
				  /* LstAd */
  if(G) ElebList();
  printf("\n\t");
  printf("Dati nr de virfuri a grafului : ");
  scanf("%d",&N);
  G=(struct Graph *)malloc(N*sizeof(struct Graph));
  printf("\n\t");
  printf("Introduceti lista de adiacenta: \n\n\r");
  for(i=0;i<N;i++)
  { printf("%d|",i+1);
    G[i].first=(struct List*)malloc(sizeof(struct List));
     G[i].last=G[i].first;
     G[i].last->next=NULL;
     G[i].last->v=-1;
     scanf("%d",&v);;
     if(N<v || v<0)
     {
        printf("\n\n\n\n\n\t\t\t");
        printf("Eroare!");
        getch();
        Menu();
     }
     while(v)
     { G[i].last->v=v-1;
        G[i].last->next=(struct List*)malloc(sizeof(struct List));
        G[i].last=G[i].last->next;
        G[i].last->next=NULL;
        G[i].last->v=-1;
        scanf("%d",&v);
        if(N<v || v<0)
        {
           printf("\n\n\n\n\n\t\t\t");
           printf("Eroare!");
           getch();
           Menu();
        }
     }
  }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
				  /* MatPnd */
  printf("\n\t");
  printf("Introduceti ponderea pentru fiecare arc:\n\n\r");
  for(i=0;i<N;i++)
  { G[i].last=G[i].first;
     while(G[i].last->v+1)
     { printf("  u%d%d| ",i+1,G[i].last->v+1);
        scanf("%d",&w);
       G[i].last->w=w;
       G[i].last=G[i].last->next;
     }
  }
//+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
}
//-------------------------------------------------------------------
	  		      /* Eleberarea listei */
void ElebList()
{ struct List *c,*t;
   while(N--)
   { c=G[N].first;
      while(c!=G[N].last)
      { t=c->next;
         free(c);
         c=t;
      }
   }
   free(G);
}
//-------------------------------------------------------------------
		  /* Vizualizarea drumului minim Ford */
void DrumFord(int v)
{ int k;
   if(v!=V) {k=v; DrumFord(G[v].p);}
   if(k!=v) printf(": %d",v+1);
    else {printf("->%d",v+1); k++;}
}







void main2()
{int a[40][40],b[40][40],c[40],v[40],d[40][40],t,z,i,j,s=0,n,m,mi=1,min,h,max,p=1,k,q,g=0,l,x_i,x_j,r=0;
printf(" Dati numarul de virfuri: ");
scanf("%d",&n);
printf("\n");

for(x_i=1;x_i<=n;x_i++)
for(x_j=1;x_j<=n;x_j++)
a[x_i][x_j]=100;

for (x_i=2;x_i<=n;x_i++)
for(x_j=1;x_j<=x_i-1;x_j++)
a[x_i][x_j]=-999;

for(x_i=1;x_i<=n+1;x_i++)
for(x_j=1;x_j<=n;x_j++)
{

system("cls");
printf("\n");
printf(" Matricea C: \n");
for(j=1;j<=n+1;j++)
printf("-------");
printf("\n");

printf("|      ");
for(j=1;j<=n;j++)
printf("|   x%d ",j);
printf("|\n");

for(j=1;j<=n+1;j++)
printf("-------");
printf("\n");

for(i=1;i<=n;i++)
{
    printf("|   x%d |",i);

    for(j=1;j<=n;j++)

if(a[i][j]<100)
        if(a[i][j]>-999)
            printf("  % d  |",a[i][j]);
            else printf(" %  d |",a[i][j]);
            else printf("      |");
    printf("\n");
for(j=1;j<=n+1;j++)
printf("-------");
printf("\n");

}
if(a[x_i][x_j]==-999) continue;
 if (x_i <= n){
printf("c[%d][%d]= ",x_i,x_j);
scanf("%d",&a[x_i][x_j]);
 }
}
printf("Alegeti virful final: x");
scanf("%d",&h);

for(i=1;i<=n;i++)
for(j=1;j<=n;j++)
b[i][j]=a[i][j];

q=n+1;

for(i=1;i<=n;i++)
b[q][i]=a[i][h];

for(i=1;i<=n;i++)
v[i]=0;

while(r!=n)
{r=0;
max=-10000;

k=1;
for(i=1;i<=n;i++)
{for(j=1;j<=n;j++)
if(b[i][j]+b[q][j]>=max)
max=b[i][j]+b[q][j];
v[k]=max;
max=-10000;
k++;}
q++;

for(i=1;i<=n;i++)
b[q][i]=v[i];


for(j=1;j<=n;j++)
if(b[q-1][j]==b[q][j])
r++;

}


for(i=1;i<=q;i++)
{for(j=1;j<=n;j++)
printf("%d\t",b[i][j]);
printf("\n");}


system("cls");

printf("\n");
printf(" Matricea C: \n");
for(j=1;j<=n+1;j++)
printf("-------");
printf("\n");

printf("|      ");
for(j=1;j<=n;j++)
printf("|   x%d ",j);
printf("|\n");

for(j=1;j<=n+1;j++)
printf("-------");
printf("\n");

for(i=1;i<=n;i++)
{
    printf("|   x%d |",i);

 for(j=1;j<=n;j++)
if(b[i][j]>=0)
if(b[i][j]>-999)

            printf("  % d  |",b[i][j]);
            else printf("% d |",b[i][j]);
            else printf("      |");
    printf("\n");

for(j=1;j<=n+1;j++)
printf("-------");
printf("\n");
}


for(i=n+1;i<=q;i++)
{
    printf("|   m%d |",mi);

 for(j=1;j<=n;j++)

if(b[i][j]>=0)
            if(b[i][j]>=10)
            if(b[i][j]>-999)
            printf("  % d |",b[i][j]);
            else printf("  % d  |",b[i][j]);
            else printf("% d |",b[i][j]);
            else printf("      |");
    printf("\n");
for(j=1;j<=n+1;j++)
printf("-------");
printf("\n");
mi++;
}

printf("\n");

printf("Dati inceputul drumului: x");
scanf("%d",&z);
printf("\n");
printf("\n");
printf("Drumurile max dmax(x%d,x%d) sunt:\n",z,h);
printf("\n");

max=-9999;
t=1;
d[1][t]=z;
t++;
for(i=z;i<=h-1;)
{for(j=i+1;j<=h;j++)
if(b[i][j]+b[q][j]>max)
{max=b[i][j]+b[q][j];
d[1][t]=j;}
else if(b[i][j]+b[q][j]==max)
d[2][t]=j;
max=-9999;
i=d[1][t];
t++;}

for(i=1;i<t;i++)
{c[i]=d[1][i];
if(d[2][i]>0)
{g=i;
l=d[2][i];}
p++;
}

if(g!=0)
{
for(i=1;i<g;i++)
d[2][i]=d[1][i];

max=-9999;
t=g+1;
for(i=l;i<=h-1;)
{for(j=i+1;j<=h;j++)
if(b[i][j]+b[q][j]>max)
{max=b[i][j]+b[q][j];
d[2][t]=j;}
else if(b[i][j]+b[q][j]==max)
d[1][t]=j;
max=-9999;
i=d[2][t];
t++;}

if(d[2][1]>0)
printf("dmax(x%d,x%d)=( ",z,h);

for(j=1;j<t;j++)
if(d[2][j]>0)
printf("x%d ",d[2][j]);
if(d[2][1]>0)
printf(")\n",z,h);
printf("\n");
}

printf("dmax(x%d,x%d)=( ",z,h);
for(i=1;i<p;i++)
printf("x%d ",c[i]);
printf(")\n");
printf("\n");

getch();
}
