#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
void setcolor(unsigned short color)
{
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hcon,color);
}
//----------------------------
void Prezt()
{

  printf("\n\n\n\n\n\
           ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n\
           บ                                                             บ\n\
	   บ     Lucrare de laborator Nr2-3 la Matematica Discreta.      บ\n\
           บ                                                             บ\n\
	   ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ%c\n\
           บ                          TEMA:                              บ\n\
	   บ             Cautarea in largime si adincime                 บ\n\
           บ                                                             บ\n\
           บ                                                             บ\n\
           บ  A efectuat :                             st.gr......       บ\n\
           บ                                           .............     บ\n\
           บ  A verificat:                             Lector asistent   บ\n\
           บ                                           ............      บ\n\
           บ                                                             บ\n\
	   ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n",185);

       	getch();
       }

//---------------------------
int main()
{int i,j,k,l,n,s,x,y,h;
 char ch;
//---------------------------
 Prezt();
 L1:static int a[30][20],b[30];
 printf("\n\t");
 setcolor(9); printf("Introduceti numarul de virfuri ale arborelui : ");
 setcolor(14);
 scanf("%i",&n);
 printf("\n\t");
 setcolor(9); printf("Introduceti lista de adiacenta :\n\n ");
 for(i=0;i<n;i++)
 { setcolor(4);
  printf("\r%2i|",i+1); setcolor(14);
   scanf("%i",&a[i][0]);
  for(j=1;j<n+1;j++)
  if(a[i][j-1]!=0) scanf("%i",&a[i][j]);
  else break;}
//----------------------------
 for(i=0;i<n;i++) b[i]=i+1;
      for(i=0;i<n;i++)
           for(j=0;j<n;j++)
                if(a[i][j]!=0)
	      if(b[a[i][j]-1]!=0&&0<a[i][j]&&a[i][j]<=n) b[a[i][j]-1]=0;
	  else goto l2; // Eror!
	  else break;
                for(i=0,x=0;x<n;x++)
                     if(b[x]!=0) {b[0]=x+1; i++;}
                     if(i>1) goto l2; // Eror!
                     x=y=0;
                     printf("\n\n\r");
 setcolor(1); printf("Parcurgerea in largime :\n\r");
 setcolor(14);
 printf("\n %d,",b[0]);
 for(i=1;i<n;i++)
 { if(a[b[x]-1][y]==0) {x++; y=0; i--;}
	 else {b[i]=a[b[x]-1][y]; y++;
			 printf(" %d,",b[i]);
			 if(i%15==0) printf("\n");
			}
 }
 goto l4;
 l2:printf("\n\n\t\t\t");
 setcolor(4); printf("Eroare!");
 goto l3;
//-------------------------------
 l4:printf("\n\n\n\r");
 setcolor(1); printf("Parcurgerea in adimcime:\n");
 i=b[0]-1;j=s=h=0;
 setcolor(14);
 printf("\n %d,",b[0]);
 while(h<n-1)
 {k=i;
  if(a[k][j]!=0)
  { printf(" %i,",a[k][j]);
	 i=a[k][j]-1;
  }
  l1:if(a[k][j]==0)
{ if(s==0)l=k+1;
if(s==1)l=x+1;
 for(x=0;x<n;x++)
      for(y=0;y<n+1;y++)
{ if(a[x][y]==l&&a[x][y+1]!=0)
 { printf(" %i,",a[x][y+1]);
i=a[x][y+1]-1;
s=0;
goto l5; }
 if(a[x][y]==l&&a[x][y+1]==0)
 { s=1;goto l1;}
}
 }
  l5:h++;
  if(h%15==0) printf("\n");
 }
//-----------------------------
 l3:
 printf("\n\n\n");
 setcolor(11); printf("           Enter -> reincarca programul...\n\n");
 setcolor(11); printf("           Esc   -> iesire din program!");
 setcolor(15);
 while(1)
 { ch=getch();
	if(ch==27) exit(0);
	if(ch==13) goto L1; }}
