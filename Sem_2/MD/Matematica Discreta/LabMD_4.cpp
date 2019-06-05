#include <stdio.h>
#include <conio.h>
#include <process.h>
#include<dos.h>
#include<time.h>
#include<windows.h>
void setcolor(unsigned short color)
{
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hcon,color);
}


int a[20][20],x,c[20][20];
int vector(int a[15],int u)
{int m,i,t=a[0];
  for(m=u;m>=2;m--)
    for(i=0;i<m-1;i++)
    if(t>a[i+1])
      t=a[i+1];
return t;
}
int vector1(int a[15],int u)
{int m,i,t=a[0];
  for(m=u;m>=2;m--)
    for(i=0;i<m-1;i++)
    if(t<a[i+1])
      t=a[i+1];
return t;
}
void bkmin()
 { int i,j,x1,x2;
   int m[15],m1[15],m2[15];
   int k,l,t,o,n,p[15],t1;
   for(i=0;i<x;i++)
	for(j=0;j<x;j++)
	 {if(a[i][j]==0)
	  c[i][j]=1000;
	 if(i==j) c[i][j]=0;}
  r: printf("Dati virful final:");
   scanf("%d",&x2);
   if(x2<0||x2>x) {printf("\nAsa virf graful dat nu Exista!\n");goto r;}
   for(i=0;i<x;i++)
   m[i]=c[i][x2-1];
 a:for(i=0;i<x;i++)
	 {for(j=0;j<x;j++)
	   m1[j]=c[i][j]+m[j];
	   m2[i]=vector(m1,x);
	 }
   k=0;
   for(j=0;j<x;j++)
	if(m2[j]==m[j]) k++;
   for(j=0;j<x;j++)
	m[j]=m2[j];
   if(k!=x) goto a;
   for(x1=1;x1<=x;x1++){
   if(m[x1-1]==1000){printf("Drumul din x%d in x%d nu exista in graful dat\n",x1,x2);
   getch(); goto b;  }
   if(x1==x2) goto b;
   printf("p[dmin(x%d,x%d)]=%d\n",x1,x2,m[x1-1]);
   l=x1-1;o=0;
  c:for(j=0;j<x;j++)
	  {m2[j]=m[j]+c[l][j];
	   p[j]=j;}
	   for(n=x;n>=2;n--)
	   for(k=0;k<n-1;k++)
	{if(m2[k]>m2[k+1])
	{t=m2[k+1];m2[k+1]=m2[k];m2[k]=t;
	 t1=p[k+1];p[k+1]=p[k];p[k]=t1;}
	if(m2[k]==m2[k+1]&&p[k]==l)
	 {t1=p[k+1];p[k+1]=p[k];p[k]=t1;}
	}
	  m1[o]=p[0];o++;l=p[0];
	   if(l!=x2-1) goto c;
	printf(" Drumul de valoarea minima din virful x%d in virful x%d este\n",x1,x2);
	printf("(x%d",x1);
	for(j=0;j<o;j++)
	 printf(",x%d",m1[j]+1);
	printf(")\n");
   k=getch();
   b:   if(k==27) break;
 }
}
void bkmax()
{ int i,j,x1,x2;
   int m[15],m1[15],m2[15];
   int k,l,t,o,n,p[15],t1;
   for(i=0;i<x;i++)
	for(j=0;j<x;j++)
	 {if(a[i][j]==0)
	  c[i][j]=-1000;
	 if(i==j) c[i][j]=0;}
  r: printf("Dati virful final:");
   scanf("%d",&x2);
   if(x2<0||x2>x) {printf("\nAsa virf graful dat nu Exista!\n");goto r;}
   for(i=0;i<x;i++)
   m[i]=c[i][x2-1];
 a:for(i=0;i<x;i++)
	 {for(j=0;j<x;j++)
	   m1[j]=c[i][j]+m[j];
	   m2[i]=vector1(m1,x);
	 }
   k=0;
   for(j=0;j<x;j++)
	if(m2[j]==m[j]) k++;
   for(j=0;j<x;j++)
	m[j]=m2[j];
   if(k!=x) goto a;
   for(x1=1;x1<=x;x1++){
   if(x1==x2) goto b;
   if(m[x1-1]==-1000){printf("Drumu din x%d in x%d nu exista in graful dat",x1,x2);
   getch();   goto b;}
   if(m[x1-1]>1000){printf("Graful dat contine circuit!!!");
   int delay(1000);
   break;}
   printf("p[dmax(x%d,x%d)]=%d\n",x1,x2,m[x1-1]);
   l=x1-1;o=0;
 c:for(j=0;j<x;j++)
	  {m2[j]=m[j]+c[l][j];
	   p[j]=j;}
	   for(n=x;n>=2;n--)
	   for(k=0;k<n-1;k++)
	{if(m2[k]<m2[k+1])
	{t=m2[k+1];m2[k+1]=m2[k];m2[k]=t;
	 t1=p[k+1];p[k+1]=p[k];p[k]=t1;}
	if(m2[k]==m2[k+1]&&p[k]==l)
	 {t1=p[k+1];p[k+1]=p[k];p[k]=t1;}
	}
	m1[o]=p[0];o++;l=p[0];
	   if(l!=x2-1) goto c;
	printf(" Drumul de valoarea maxima din virful x%d in virful x%d este\n",x1,x2);
	printf("(x%d",x1);
	for(j=0;j<o;j++)
	 printf(",x%d",m1[j]+1);
	printf(")\n");
   k=getch();
   b:   if(k==27) break;
 }
}
void ford()
{struct arc{int u;
 int o;}b[30];
 int i,j,x1,x2,t=0;
 int p1[15],p[15],k,A,l,d[15],y1,y2;
 for(i=0;i<x;i++)
  for(j=0;j<x;j++)
   if(a[i][j]!=0)
   {b[t].u=i;b[t].o=j;t++;}
b: printf("Introduceti virful initial:\n");
 scanf("%d",&x1);
 if(x1<0||x1>x) {printf("\nAsa virf graful dat nu contine!\n");goto b;}
  for(j=0;j<x;j++)
   {p[j]=1000;
	if(j==x1-1) p[j]=0;
	}
p:for(i=0;i<x;i++)
	p1[i]=p[i];
  for(i=0;i<t;i++)
   {k=p[b[i].o]-p[b[i].u];
   if(k>c[b[i].u][b[i].o]) {p[b[i].o]=p[b[i].u]+c[b[i].u][b[i].o];}
	}
   k=0;
   for(i=0;i<x;i++)
   if(p1[i]==p[i]) k++;
  if(k!=x) goto p;
  for(x2=1;x2<=x;x2++)
{ if(x1==x2) goto a;
  if(p[x2-1]==1000) {printf("Nu exista drumul din x%d in x%d\n",x1,x2);getch();goto a;}
  if(x2<0||x2>x) {printf("\nAsa virf graful dat nu Exista!\n");getch();goto a;}
  printf("Valoarea drumului minim din virful x%d in virful x%d este\n",x1,x2);
  printf("p[dmin(x%d,x%d)]=%d",x1,x2,p[x2-1]);
  printf("\nDrumul de valoarea minima din virful x%d in virful x%d este\n",x1,x2);
  l=x2-1;k=0;
  for(i=t-1;i>=0;i--)
   if(b[i].o==l)
   if(p[b[i].o]-p[b[i].u]==c[b[i].u][b[i].o]) {d[k]=b[i].o;k++;l=b[i].u;}
  printf("dmin=(x%d",x1);
  for(i=k-1;i>=0;i--)
  printf(",x%d",d[i]+1);
  printf(")\n");
  A=getch();
 a:  if(A==27) break;
 }
}
void intr()
{  int xx,yy,A,t,n,m,m1,n1,i1,j1,i,j;
setcolor(10);
printf("\n\n\n\n\n\
           ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n\
           บ                                                             บ\n\
	   บ       Lucrare de laborator Nr4 la Matematica Discreta.      บ\n\
           บ                                                             บ\n\
	   ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ%c\n\
           บ                          TEMA:                              บ\n\
	   บ    Algoritmul de parcurgere a drumurilor minime folosind    บ\n\
           บ        algoritmul Bellman-Kalaba si algoritmul Ford         บ\n\
           บ                                                             บ\n\
           บ                                                             บ\n\
           บ  A efectuat :                             st.........       บ\n\
           บ                                           .............     บ\n\
           บ  A verificat:                             ...............   บ\n\
           บ                                           ..............    บ\n\
           บ                                                             บ\n\
	   ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n",185);

       	getch();
        printf("\n\
           ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n\
	   บ                     INTRODUCETI DATELE                      บ\n\
	   ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n",185);

   printf(" Numarul de virfuri este:");
   scanf("%d",&x);
   printf("Introduceti matricea de adiacenta:");
   printf("\n\nA    ");
   for (i=0;i<x;i++)
   printf("x%d    ",i+1);
   printf("\n");
   yy=9;xx=0;
   for (i=0;i<x;i++)
   {  yy=yy+1;
      xx=0;
      printf("\nx%d",i+1);
      for (j=0;j<x;j++)
	 {  xx=xx+6;
	  a:
	    A=getch();
	    if(A==48){a[i][j]=0;printf("%d",a[i][j]);}
	    if(A==49){if(i==j) goto a;a[i][j]=1;printf("%d",a[i][j]);}
	    if((A!=48)&&(A!=49)){xx=xx-6;j--;}
	  }
   }    n=xx,m=yy;m1=0,n1=0;
    for(;;)
  { b:    t=getch();
    if (t==13) break;
    if(t==72) {m--;m1++;}
    if(t==80) {m++;m1--;}
    if(t==77) {n=n+6;n1--;}
    if(t==75) {n=n-6;n1++;}
    if(t==48) {i1=i-m1-1;j1=j-n1-1; a[i1][j1]=0; printf("%d",a[i1][j1]);}
    if(t==49){i1=i-m1-1;j1=j-n1-1;if(i1==j1) goto b;a[i1][j1]=1; printf("%d",a[i1][j1]); }
    if(t==83) {printf(" ");}
   }
}
void main()
 {int c1,i,j,A;
   intr();
  clrscr();
   printf("\n");
   for(i=0;i<x;i++)
    for(j=0;j<x;j++)
     if(a[i][j]!=0)
     {printf("p(x%d,x%d)=",i+1,j+1);
      scanf("%d",&c[i][j]);}
 a:printf("\nDoriti sa corectati poderea unui arc(enter-da;orice tasta-nu;)?\n");
   A=getch();
   if(A==13){printf("Dati virful initial=");scanf("%d",&i);
	     printf("Dati virful final=");scanf("%d",&j);
	     printf("p(x%d,x%d)=",i,j);scanf("%d",&c[i-1][j-1]);goto a;
	     }
for(;;)   { clrscr();
	printf("\n\t\tAlegeti algoritmul care sa prelucreze graful dat:\n");
	printf("\n\t1-Algoritmul Bellman-Kalaba de determinare a drumurilor minime;\n");
	printf("\n\t2-Algoritmul Bellman-Kalaba de determinare a drumurilor maxime;\n");
	printf("\n\t3-Algoritmul Ford de determinare a drumurilor de valoare minima;\n");
	printf("\n\t4-Exit;\n");
	 scanf("%d",&c1);
	 switch(c1)
	   {   case 1:bkmin();break;
	       case 2:bkmax();break;
	       case 3:ford();break;
	       case 4:exit(0);break;
	   }
  }
}
