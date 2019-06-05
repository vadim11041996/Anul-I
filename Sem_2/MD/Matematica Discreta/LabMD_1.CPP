#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
void setcolor(unsigned short color)
{
HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hcon,color);
}


typedef struct LISTA{
   int virf;
   struct LISTA *next;
}LISTA;



int din_adiacenta(int **m_adiacenta, int ***m_incidenta, LISTA ***lista,int virfuri,int *arcuri)
{
   LISTA **_lista=NULL, *pos=NULL;
   int **_m_incidenta;
   int _arcuri=0, i, j, ac=0;

   for(i=0;i<virfuri;i++)
      for(j=0;j<virfuri;j++)
		 if(m_adiacenta[i][j]==1)_arcuri++;

   _m_incidenta=(int**)malloc(_arcuri*sizeof(int*));
   if(!_m_incidenta)return 0;
   for(i=0;i<_arcuri;i++)
   {
	  _m_incidenta[i]=(int*)malloc(virfuri*sizeof(int));
      if(!_m_incidenta[i])return 0;
	  for(j=0;j<virfuri;j++) _m_incidenta[i][j]=0;
   }

   _lista=(LISTA**)malloc(virfuri*sizeof(LISTA*));
   if(!lista)return 0;

   for(i=0;i<virfuri;i++)
   {
      _lista[i]=NULL;
      for(j=0;j<virfuri;j++)
	  {
	     if(m_adiacenta[i][j]==1)
		 {
		    if(i==j)_m_incidenta[ac][i]=2;
			else
			{
		       _m_incidenta[ac][i]=-1;
			   _m_incidenta[ac][j]=1;
			}
            ac++;

			if(!_lista[i])
			{
			   _lista[i]=(LISTA*)malloc(sizeof(LISTA));
			   pos=_lista[i];
			}
			else
			{
			   pos->next=(LISTA*)malloc(sizeof(LISTA));
			   pos=pos->next;
			}
			pos->virf=j+1;
			pos->next=NULL;
		 }
      }
   }

   *m_incidenta=_m_incidenta;
   *arcuri=_arcuri;
   *lista=_lista;
   return 1;
}



int din_incidenta(int ***m_adiacenta, int **m_incidenta, LISTA ***lista,int virfuri,int arcuri)
{
   LISTA **_lista=NULL, *pos=NULL;
   int **_m_adiacenta=NULL;
   int i,j,source,dest;

   _m_adiacenta=(int**)malloc(virfuri*sizeof(int*));
   if(!_m_adiacenta)return 0;
   for(i=0;i<virfuri;i++)
   {
	  _m_adiacenta[i]=(int*)malloc(virfuri*sizeof(int));
      if(!_m_adiacenta[i])return 0;
	  for(j=0;j<virfuri;j++) _m_adiacenta[i][j]=0;
   }

   _lista=(LISTA**)malloc(virfuri*sizeof(LISTA*));
   if(!lista)return 0;
   for(i=0;i<virfuri;i++)_lista[i]=NULL;

   for(i=0;i<arcuri;i++)
   {
      for(j=0;j<virfuri;j++)
	  {
	     if(m_incidenta[i][j]==-1)source=j;
		 else if(m_incidenta[i][j]==1)dest=j;
		 else if(m_incidenta[i][j]==2)source=dest=j;
	  }
	  _m_adiacenta[source][dest]=1;

	  if(!_lista[source])
	  {
	     _lista[source]=(LISTA*)malloc(sizeof(LISTA));
		 pos=_lista[source];
	  }
	  else
	  {
	     pos=_lista[source];
		 while(pos->next) pos=pos->next;
	     pos->next=(LISTA*)malloc(sizeof(LISTA));
		 pos=pos->next;
	  }
	  pos->virf=dest+1;
	  pos->next=NULL;
   }

   *m_adiacenta=_m_adiacenta;
   *lista=_lista;
   return 1;
}



int din_lista(int ***m_adiacenta, int ***m_incidenta, LISTA **lista,int virfuri,int *arcuri)
{
   LISTA *pos=NULL;
   int **_m_adiacenta=NULL, **_m_incidenta=NULL;
   int _arcuri=0, i, j;

   _m_adiacenta=(int**)malloc(virfuri*sizeof(int*));
   if(!_m_adiacenta)return 0;
   for(i=0;i<virfuri;i++)
   {
	  _m_adiacenta[i]=(int*)malloc(virfuri*sizeof(int));
      if(!_m_adiacenta[i])return 0;
	  for(j=0;j<virfuri;j++) _m_adiacenta[i][j]=0;
   }

   for(i=0;i<virfuri;i++)
   {
      pos=lista[i];
	  while(pos)
	  {
	     _m_adiacenta[i][pos->virf-1]=1;

		 _arcuri++;
		 _m_incidenta=(int**)realloc(_m_incidenta,_arcuri*sizeof(int*));
		 if(!_m_incidenta)return 0;
		 _m_incidenta[_arcuri-1]=(int*)malloc(virfuri*sizeof(int));
		 if(!_m_incidenta[_arcuri-1])return 0;
		 for(j=0;j<virfuri;j++) _m_incidenta[_arcuri-1][j]=0;
		 if(i==pos->virf-1) _m_incidenta[_arcuri-1][i]=2;
		 else
		 {
		    _m_incidenta[_arcuri-1][i]=-1;
			_m_incidenta[_arcuri-1][pos->virf-1]=1;
	     }

		 pos=pos->next;
	  }
   }

   *m_incidenta=_m_incidenta;
   *arcuri=_arcuri;
   *m_adiacenta=_m_adiacenta;
   return 1;
}



int main()
{
  int **m_incidenta=NULL, **m_adiacenta=NULL;
  int i, j, buf, x, y, option, virfuri, arcuri, source, dest;
  LISTA **lista=NULL, *pos=NULL,*next=NULL;
  char s[100],*ptr;
  setcolor(10);
  printf("\n\n\n\n\n\
           ษอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออป\n\
           บ                                                             บ\n\
	   บ       Lucrare de laborator Nr1 la Matematica Discreta.      บ\n\
           บ                                                             บ\n\
	   ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออ%c\n\
           บ                          TEMA:                              บ\n\
	   บ      Memorarea grafului in memorie sub diferite forme.      บ\n\
           บ                                                             บ\n\
           บ                                                             บ\n\
           บ  A efectuat :                             st.gr......       บ\n\
           บ                                           .............     บ\n\
           บ  A verificat:                             ...............   บ\n\
           บ                                           .............     บ\n\
           บ                                                             บ\n\
	   ศอออออออออออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n",185);

       	getch();

  while(1)
  {

        system("cls");
    setcolor(9);
  printf("\n\n\n\n\n\
           ษอออออออออออออออออออออออออออออออออออออออออออออออออออออป\n\
	   บ     Introducerea grafului prin intermediul:         บ\n\
	   ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออ%c\n\
	   บ     1.Matricii de adiacenta                         บ\n\
	   บ     2.Matricii de incidenta                         บ\n\
	   บ     3.Listei de adiacenta                           บ\n\
	   ศอออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n",185);
  printf("\n\n\
           ษอออออออออออออออออออออออออออออออออออออออออออออออออออออป\n\
	   บ     Afisarea grafului prin intermediul:             บ\n\
	   ฬอออออออออออออออออออออออออออออออออออออออออออออออออออออ%c\n\
	   บ     4.Matricii de adiacenta                         บ\n\
	   บ     5.Matricii de incidenta                         บ\n\
	   บ     6.Listei de adiacenta                           บ\n\
	   ศอออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n",185);
  printf("\n\n\
	   ษอออออออออออออออออออออออออออออออออออออออออออออออออออออป\n\
	   บ     7.Stergerea grafului din memorie                บ\n\
	   บ     0.Iesire                                        บ\n\
	   ศอออออออออออออออออออออออออออออออออออออออออออออออออออออผ\n",185);
   setcolor(3);
  printf("\n Comanda> ");
	scanf("%d",&option);
	system("cls");


	switch(option)
	{
	  case 1:
          setcolor(12);
	    if(m_adiacenta!=NULL) puts(" Erorare !!! :  Memoria este ocupata.");
		else
		{ setcolor(14);
           printf(" Numarul de virfuri al grafului: ");
		   scanf("%d",&virfuri);

		   m_adiacenta=(int**)malloc(virfuri*sizeof(int*));
		   if(!m_adiacenta)exit(1);
		   for(i=0;i<virfuri;i++)
		   {
		      m_adiacenta[i]=(int*)malloc(virfuri*sizeof(int));
		      if(!m_adiacenta[i])exit(1);
		   }

		   system("cls");
		   x=6;
		   y=5;
                   setcolor(14);
		   puts("\n Itroduceti elementele matricii de adiacenta:\n");
		   for(i=0;i<virfuri;i++,x+=4,y++)
		   {
		      gotoxy(2,y);
		      cprintf("X%d",i+1);
		      gotoxy(x,4);
		      cprintf("X%d ",i+1);
		   }
		   for(i=0,y=5;i<virfuri;i++,y++)
		     for(j=0,x=6;j<virfuri;j++,x+=4)
		     {
		        gotoxy(x,y);
			    if( getch()!='1' ) m_adiacenta[i][j]=0;
			    else m_adiacenta[i][j]=1;
			    printf("%d",m_adiacenta[i][j]);
		     }
		}
                setcolor(12);
        if(!din_adiacenta(m_adiacenta,&m_incidenta,&lista,virfuri,&arcuri))

		   puts("\n Eroare !!!:  Conversie esuata!");
		getch();
	    break;
	  case 2:
	    if(m_incidenta!=NULL)
		{   setcolor(12);
		   puts(" Erorare !!!:  Memorie ocupata.");
		   getch();
		}
		else
		{
	    gotoxy(2,2);
            setcolor(14);
	    printf(" Numarul de virfuri ale grafului: ");
		gotoxy(2,3);
		printf(" Numarul de arcuri ale grafului : ");
		gotoxy(36,2);
		scanf("%d",&virfuri);
		gotoxy(36,3);
		scanf("%d",&arcuri);

		m_incidenta=(int**)malloc(arcuri*sizeof(int*));
		if(!m_incidenta)exit(1);
		for(i=0;i<arcuri;i++)
		{
		   m_incidenta[i]=(int*)malloc(virfuri*sizeof(int));
		   if(!m_incidenta[i])exit(1);
		}

		for(i=0;i<arcuri;i++)
		{
		   clrscr();
                   setcolor(14);
		   printf("\n Muchia %d:\n",i+1);
                   setcolor(10);
		   printf("  Originea  :");
		   gotoxy(3,4);
                   setcolor(9);
		   printf("Destinatia:");
	       gotoxy(15,3);
		   scanf("%d",&source);
		   gotoxy(15,4);
		   scanf("%d",&dest);

		   if( source>virfuri || source<1 || dest>virfuri || dest<1 )
		   {   setcolor(12);
		      puts("Ati introdus niste valori inexistente!");
			  getch();
			  i--;
			  continue;
		   }
		   source--;
		   dest--;
		   for(j=0;j<virfuri;j++)
		   {
		      if(j!=source && j!=dest) m_incidenta[i][j]=0;
			  else if(j==source && j==dest)m_incidenta[i][j]=2;
			  else if(j==source) m_incidenta[i][j]=-1;
			  else if(j==dest) m_incidenta[i][j]=1;
		   }
		}
		}
		if(!din_incidenta(&m_adiacenta,m_incidenta,&lista,virfuri,arcuri))
		{  setcolor(12);
		   puts("\n Eroare !!!:  Conversie esuata!");
		   getch();
		}
	    break;
	  case 3:
	    if(lista!=NULL)
		{  setcolor(12);
		   puts(" Erorare:  Memorie ocupata.");
		   getch();
		}
		else
		{
        printf(" Numarul de virfuri a grafului: ");
		scanf("%d",&virfuri);

		lista=(LISTA**)malloc(virfuri*sizeof(LISTA*));
		if(!lista)exit(1);

		clrscr();
		for(i=0;i<virfuri;i++)
		{
		   printf(" Introduceti prin virgula elementele adiacente virfului %d: ",i+1);
		   fflush(stdin);
		   gets(s);
		   pos=lista[i]=NULL;

		   if( (ptr=strtok(s,",")) )
		   {
		      buf=atoi(ptr);
			  if(buf>0 && buf<=virfuri)
			  {
			     lista[i]=(LISTA*)malloc(sizeof(LISTA));
			     if(!lista[i]) exit(1);
				 pos=lista[i];
				 pos->next=NULL;
			     pos->virf=buf;
			  }

			  while( (ptr=strtok(NULL,",")) )
			  {
			     buf=atoi(ptr);
				 if(buf>0 && buf<=virfuri)
				 {
				    if(!lista[i])
					{
			           lista[i]=(LISTA*)malloc(sizeof(LISTA));
			           if(!lista[i]) exit(1);
			           pos=lista[i];
				       pos->next=NULL;
			           pos->virf=buf;
					}
					else
					{
		  	           pos->next=(LISTA*)malloc(sizeof(LISTA));
				       if(!pos->next) exit(1);
				       pos=pos->next;
				       pos->virf=buf;
			           pos->next=NULL;
					}
				 }
			  }
		   }
		}
		}
		if(!din_lista(&m_adiacenta,&m_incidenta,lista,virfuri,&arcuri))
		{
		   puts("\n Eroare !!!:  Conversie esuata!");
		   getch();
		}
	    break;
	  case 4:
	    if(!m_adiacenta)

            puts(" Erorare !!!:  Graful nu e introdus.");
		else
		{
	         puts(" Reprezentarea grafului introdus in forma matricii de adiacenta:");
		   textcolor(RED);
		   x=6;
		   y=5;
		   for(i=0;i<virfuri;i++,x+=4,y++)
		   {
		      gotoxy(2,y);
		      cprintf("X%d",i+1);
		      gotoxy(x,4);
		      cprintf("X%d ",i+1);
	       }
		   textcolor(WHITE);
		   for(i=0,y=5;i<virfuri;i++,y++)
		     for(j=0,x=6;j<virfuri;j++,x+=4)
		     {
		        gotoxy(x,y);
			    printf("%d",m_adiacenta[i][j]);
		     }
        }
		getch();
	    break;
	  case 5:
	    if(!m_incidenta)

            puts(" Erorare !!!:  Graful nu e introdus.");
		else
		{
	       puts(" Reprezentarea grafului introdus in forma matricii de incidenta:");
		   textcolor(RED);
	       for(i=0,x=5;i<virfuri;i++,x+=4)
		   {
		      gotoxy(x,3);
		      cprintf("X%d",i+1);
		   }
		   for(i=0;i<arcuri;i++)
		   {
		      gotoxy(2,4+i);
		      cprintf("U%d",i+1);
		   }
		   textcolor(WHITE);
		   for(i=0,y=4;i<arcuri;i++,y++)
		     for(j=0,x=5;j<virfuri;j++,x+=4)
		     {
		        gotoxy(x,y);
			    if(m_incidenta[i][j]!=-1) printf(" %d",m_incidenta[i][j]);
			    else printf("%d",m_incidenta[i][j]);
		     }
        }
		getch();
	    break;
	  case 6:

	    if(!lista) puts(" Eroare !!!:  Graful nu e introdus.");
		else
		{
	       puts(" Reprezentarea grafului introdus in forma listei de adiacenta:\n");
		   textcolor(RED);
		   for(i=0;i<virfuri;i++)
		   {
		      cprintf("  %d:",i+1);
		      pos=lista[i];
		      while(pos)
		      {
		         printf(" %d,",pos->virf);
		         pos=pos->next;
		      }
		      printf(" 0\n");
		   }
		   textcolor(BLUE);
		}
	    getch();
	    break;
	  case 7:
        if(m_incidenta!=NULL)
        {
           for(i=0;i<arcuri;i++) free(m_incidenta[i]);
	       free(m_incidenta);
		   m_incidenta=NULL;
        }

        if(m_adiacenta!=NULL)
        {
           for(i=0;i<virfuri;i++) free(m_adiacenta[i]);
	       free(m_adiacenta);
		   m_adiacenta=NULL;
        }

        if(lista!=NULL)
        {
          for(i=0;i<virfuri;i++)
	      {
	        pos=lista[i]->next;
	    	free(lista[i]);
		    while(pos)
		    {
		       next=pos->next;
		       free(pos);
		       pos=next;
		    }
	      }
	      free(lista);
		  lista=NULL;
        }       setcolor(12);
		puts(" Graful a fost sters din memoria calculatorului");
		getch();
	    break;
	  case 0:
	    return 0;
	  default:
		puts("Ati introdus o comanda inexistenta!");
		getch();
	}
  }
}
