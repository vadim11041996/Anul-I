#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>
#include <VALUES.H>
#include <math.h>

typedef  char uns[20];
typedef uns  matr[10][10][10];
char* copy(int);
void drum(char [20][20],int);
int  num(char);
int main()
{ int *v[10];
	int adj[10][10]={0};
	int p[10][10]={0},C[10][10]={0};
	int ss=0;
	char s[20][20]={0};
	int i,j,n,x,k;
	int t1=0,t2=0;
	char c1;
	uns K0[10][10]={0};
	matr K1,K12;
	system("cls");
	system("Color 9");
	printf("Introdu numarul de virfuri:");
	scanf("%i",&n);
	printf("\n");
	c1=(n%10)+48;
	for(i=0;i<n;i++)
		 v[i]=(int*)malloc(n*sizeof(int));
	printf("Introdu lista de adiacenta:\n");
	for(i=0;i<n;i++)
		{printf("V%i: ",i+1); j=1;k=0;
		 while (j!=0)
			{scanf("%i",&j);
				*(v[i]+k)=j;k++;
			 }
		}
	 for(i=0;i<n;i++){k=0;
		 while (*(v[i]+k)!=0)
			{ adj[i][(*(v[i]+k))-1]=1;k++;}
		}
	 for(i=0;i<n;i++){k=0;
		 while (*(v[i]+k)!=0)
			{ strcpy(K0[i][(*(v[i]+k))-1],copy(*(v[i]+k)));	k++;}
		}
	 for(i=0;i<n;i++)  free(v[i]);
	 for(i=0;i<10;i++)
		 for(j=0;j<10;j++)
			 for(t1=0;t1<10;t1++)
					{ strcpy(K1[i][j][t1],"");
						strcpy(K12[i][j][t1],"");
					}
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				if  (strlen(K0[i][j])!=0)
						 { strcpy((K1[i][j][0]),copy(i+1));
							 strcat(K1[i][j][0],copy(j+1));}
				else strcpy(K1[i][j][0],"");
	//strcpy(s,"
	for(k=1;k<n;k++)
	 {
	  for(i=0;i<n;i++)
		for(j=0;j<n;j++)  {x=0;
			for(t1=0;t1<n;t1++)
			   if ((strlen(K1[i][t1][0])!=0)&&(strlen(K0[t1][j])!=0)){t2=0;
				   while (strlen(K1[i][t1][t2])!=0)
					 {strcpy(K12[i][j][x],K1[i][t1][t2]);
					  strcat(K12[i][j][x],K0[t1][j]);
					  if ((K12[i][j][x][0]=='1')&&(K12[i][j][x][strlen(K12[i][j][x])-1]==c1))
						{strcpy(s[ss],K12[i][j][x]); ss++; }
						 x++;t2++;
					 }
				  }
			}
	   for(i=0;i<10;i++)
		 for(j=0;j<10;j++)
		  for(t1=0;t1<10;t1++)
			  strcpy(K1[i][j][t1],"");
	   for(i=0;i<n;i++)
		for(j=0;j<n;j++)
		  if (strlen(K12[i][j][0])!=0)	{t2=0;
			 while (strlen(K12[i][j][t2])!=0)
			  {strcpy(K1[i][j][t2],K12[i][j][t2]); t2++;}
			}
		for(i=0;i<10;i++)
		 for(j=0;j<10;j++)
		  for(t1=0;t1<10;t1++)
		   strcpy(K12[i][j][t1],"");
	 }
	x=0;
	for(i=0;i<n;i++)
	 for(j=0;j<n;j++)	 p[i][j]=0;
	printf("Introdu ponderile\n");
	for(i=0;i<n;i++)
	 for(j=0;j<n;j++)
		 if (adj[i][j]!=0)
			 {printf("C(x%i,x%i)=",i+1,j+1);
			  scanf("%i",&C[i][j]);
			  }
	for(i=0;i<ss;i++)
		{ j=1;
			k=C[s[i][0]-49][s[i][1]-49]-p[s[i][0]-49][s[i][1]-49];
			while (s[i][j]!=c1)
			 { if (C[s[i][j]-49][s[i][j+1]-49]-p[s[i][j]-49][s[i][j+1]-49]==0)   {k=0;break;}
				 else
				 if (k>C[s[i][j]-49][s[i][j+1]-49]-p[s[i][j]-49][s[i][j+1]-49])
					 k=C[s[i][j]-49][s[i][j+1]-49]-p[s[i][j]-49][s[i][j+1]-49];
				 j++;
			 }
		x=x+k;
		for(j=0;s[i][j]!=c1;j++)
		 if (k>0)
			p[s[i][j]-49][s[i][j+1]-49]+=k;
		}
     printf("               ีออออออออออออออออออออออออออออออออออออธ\n");
     printf("               ณ  Fluxul maxim este: %i              ณ\n",x);
     printf("               ิออออออออออออออออออออออออออออออออออออพ\n\n");

    // printf("               ฦออออออออออออออออออออออออออออออออออออต\n");
    // printf("               ณ  Valoarea fluxului in arcuri este: ณ\n");
    // printf("               ิออออออออออออออออออออออออออออออออออออพ\n\n");
     printf("\t\t");
//	for(i=0;i<n;i++)
	// for(j=0;j<n;j++)
	  //if (adj[i][j]==1)
       // printf("\nF(x%i,x%i)=%i\t",i+1,j+1,p[i][j]);
getch();
}
char* copy(int n)
{ int i=0,z,d;
	float d1=n;
	char *s2,*s,s1[20];
	while ((n%10!=0)||(n/10!=0)){
		    i++;
		 n=n/10;
		}
	s=ecvt(d1,i,&d,&z);
	strcpy(s1,s);
	s2=s1;
 return s2;
}
