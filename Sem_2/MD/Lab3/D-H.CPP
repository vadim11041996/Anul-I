#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

main()
{ int *v[10],*a,*p,t1;
	int i,j,n,t[10];
	char c;
	int ch[10][10]={0};
	int i1;
	system("color 9");
	et1:printf("DATI NUMARUL DE VIRFURI\n");
	scanf("%i",&n);
	for(i=0;i<n;i++)
        v[i]=(int*)malloc((n-1)*sizeof(int));
	printf("INTRODUCETI LISTA DE ADIACENTA\n");
	for(i=0;i<n;i++)
		{printf("V %i->: ",i+1);
		 a=v[i];j=1;
		 while (j!=0)
			{ scanf("%i",&j);
				  *(v[i]++)=j;
			 }
		 v[i]=a;
		}
	 for(i=0;i<n;i++)
		{a=v[i];
		 while (*v[i]!=0)
			{ ch[i][*v[i]-1]=1;
			  v[i]++;
			}
		 v[i]=a;
		}
	 for(i=0;i<n;i++)
        free(v[i]);
	 for(i=0;i<n;i++)
	    { for(j=0;j<n;j++)
	    t[j]=0;
	      t1=0;
	      while (t1==0)
		{t1=1;
		 for(j=0;j<n;j++)
		    if ((ch[i][j]==1)&&(t[j]==0))
		      {
		          t1=0;
		       for(i1=0;i1<n;i1++)
			  if ((ch[i][i1]==0)&&(ch[j][i1])==1)
				ch[i][i1]=1;
			t[j]=1;break;
			}
		}
	    }
	 for(i=0;i<n;i++)
        t[i]=0;
	 printf("MATRICEA DRUMURILOR ESTE:\n");
	 for(i=0;i<n;i++)
		{ for(j=0;j<n;j++)
			{ if (ch[i][j]==1)
			t[i]++;
				printf("\t%i",ch[i][j]);
				}
		 printf("\n");
		}
		i1=0;
		for(i=0;i<n;i++)
            i1+=t[i];
		if (i1==((n-1)*n)/2)
		{ printf("DRUMUL HAMILTONIAN ESTE:\n");
			for(i=0;i<n;i++)
				{ i1=t[0];
					for(j=0;j<n;j++)
						if (t[j]>i1)
                            i1=t[j];
					for(j=0;j<n;j++)
					 if (t[j]==i1)  {
                            printf("V%i -> ",j+1);
                     t[j]=-1;
                     break;
                     }
					}
				printf("\b\b  ");
		 }
		else printf("\n\t\tNU EXITA DRUM HAMILTONIAN PENTRU GRAFUL DAT\n");
	 getch();
}

