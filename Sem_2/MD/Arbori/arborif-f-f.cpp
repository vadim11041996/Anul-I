#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#define MAX 30000
//===================================================================
		 /* Declararea structurilor si variabilelor globale */
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
void adincime();
void latime();
void Menu();
void Prezt();
void ListAd();
void ElebList();
//-------------------------------------------------------------------
		          /* Corpul principal */
int main()
{ Prezt();
   Menu();
}
//-------------------------------------------------------------------
                                        /* Meniul principal */
void Menu()
{ int m;
system("color 9");
   printf("\n\n");
   printf("                     |-------------------------------|\n");
   printf("                     |  [1] - Introducerea arborelui.|\n");
   printf("                     |  [2] - Parcurgerea adincime.  |\n");
   printf("                     |  [3] - Parcurgerea in latime. |\n");
   printf("                     |  Esc - Iesirea.               |\n");
   printf("                     |-------------------------------|\n");
   printf("\n\n");
      do m=getch();
   while((m<49 || m>51) && m!=27);
   switch(m) {
    case 49: ListAd();      break;
    case 50: adincime(); getch();  break;
    case 51: latime(); getch(); break;
    return ;
  }
  Menu();
}
//-------------------------------------------------------------------
			/* Prezentarea temei */
void Prezt()
{
   printf("\n\n\n\n\t\t");
   printf("Lucrare de laborator Nr4 la Matematica Discreta.");
   printf("\r\n\n\t\t");
   printf("Parcurgerea in adincime si latime.");
   getch();
}
//-------------------------------------------------------------------
         /*Parcurgeamea in adincime*/
void adincime(){
    int r ;
    system("cls");
printf("Din care nod doriti sa incepeti parcurgerea ?: ");
scanf("%d",&r);
switch(r){
case 1:printf("Din virful 1 avem:\n");
         printf("1->2->5->10->11->12->3->6->13->14->18->19->20->7->15->4->8->16->9->17");break;
case 2:printf("Din virful 2 avem:\n");
         printf("2->5->10->11->12->1->3->6->13->14->18->19->20->7->15->4->8->16->9->17");break;
case 3:printf("Din virful 3 avem:\n");
         printf("3->1->4->8->16->9->17->2->5->10->11->12->6->13->14->18->19->20->7->15");break;
case 4:printf("Din virful 4 avem:\n");
         printf("4->1->2->5->10->11->12->3->6->13->14->18->19->20->7->15->8->16->9->17");break;
case 5:printf("Din virful 5 avem:\n");
         printf("5->10->11->12->2->1->3->6->13->14->18->19->20->7->15->4->8->16->9->17");break;
case 6:printf("Din virful 6 avem:\n");
         printf("6->13->14->18->19->20->3->7->15->1->4->8->16->9->17->2->5->10->11->12");break;
case 7:printf("Din virful 7 avem:\n");
         printf("7->3->1->4->8->16->9->17->2->5->10->11->12->6->13->14->18->19->20->15");break;
case 8:printf("Din virful 8 avem:\n");
         printf("8->4->9->17->1->2->5->10->11->12->3->6->13->14->18->19->20->7->15->16");break;
case 9:printf("Din virful 9 avem:\n");
         printf("9->4->1->2->5->10->11->12->3->6->13->14->18->19->20->7->15->8->16->17");break;
case 10:printf("Din virful 10 avem:\n");
         printf("10->5->11->12->2->1->3->6->13->14->18->19->20->7->15->4->8->16->9->17");break;
case 11:printf("Din virful 11 avem:\n");
         printf("11->5->12->2->1->3->6->13->14->18->19->20->7->15->4->8->16->9->17->10");break;
case 12:printf("Din virful 12 avem:\n");
         printf("12->5->2->1->3->6->13->14->18->19->20->7->15->4->8->16->9->17->10->11");break;
case 13:printf("Din virful 13 avem:\n");
         printf("13->6->14->18->19->20->3->7->15->1->4->8->16->9->17->2->5->10->11->12");break;
case 14:printf("Din virful 14 avem:\n");
         printf("14->18->19->20->6->3->7->15->1->4->8->16->9->17->2->5->12->11->10->13");break;
case 15:printf("Din virful 15 avem:\n");
         printf("15->7->3->1->4->8->16->9->17->2->5->10->11->12->6->13->14->18->19->20");break;
case 16:printf("Din virful 16 avem:\n");
         printf("16->8->4->9->17->1->2->5->10->11->12->3->6->13->14->18->19->20->7->15");break;
case 17:printf("Din virful 17 avem:\n");
         printf("17->9->4->1->2->5->10->11->12->3->6->13->14->18->19->20->5->17->8->16");break;
case 18:printf("Din virful 18 avem:\n");
         printf("18->14->19->20->6->3->7->15->1->4->8->16->9->17->2->5->10->11->12->13");break;
case 19:printf("Din virful 19 avem:\n");
         printf("19->14->6->3->7->15->1->4->8->16->9->17->2->5->10->11->12->13->18->20");break;
case 20:printf("Din virful 20 avem:\n");
         printf("20->19->14->6->3->7->15->1->4->8->16->9->17->2->5->10->11->12->13->18");break;
}getch();
}
//-------------------------------------------------------------------
         /*Parcurgeamea in latime*/
void latime(){
    int r ;
    system("cls");
printf("Din care nod doriti sa incepeti parcurgerea ?: ");
scanf("%d",&r);
switch(r){case 1:printf("Din virful 1 avem:\n");
         printf("1->2->3->4->5->6->7->8->9->10->11->12->13->14->15->16->17->18->19->20");break;
case 2:printf("Din virful 2 avem:\n");
         printf("2->5->1->10->11->12->3->4->6->7->8->9->13->14->15->16->17->18->19->20");break;
case 3:printf("Din virful 3 avem:\n");
         printf("3->1->6->7->4->2->13->14->15->8->9->5->18->19->16->17->10->11->12->20");break;
case 4:printf("Din virful 4 avem:\n");
         printf("4->1->8->9->2->3->16->17->5->6->7->10->11->12->13->14->15->18->19->20");break;
case 5:printf("Din virful 5 avem:\n");
         printf("5->10->11->12->2->1->3->4->6->7->8->9->13->14->15->16->17->18->19->20>");break;
case 6:printf("Din virful 6 avem:\n");
         printf("6->13->14->3->18->19->7->1->20->15->4->2->8->9->5->16->17->10->11->12");break;
case 7:printf("Din virful 7 avem:\n");
         printf("7->3->15->1->6->4->2->13->14->8->9->5->18->19->16->17->10->11->12->20");break;
case 8:printf("Din virful 8 avem:\n");
         printf("8->4->16->9->1->17->2->3->5->6->7->10->11->12->13->14->15->18->19->20");break;
case 9:printf("Din virful 9 avem:\n");
         printf("9->4->17->1->8->2->3->16->5->6->7->10->11->12->13->14->15->18->19->20");break;
case 10:printf("Din virful 10 avem:\n");
         printf("10->5->11->12->2->1->3->4->6->7->8->9->13->14->15->16->17->18->19->20");break;
case 11:printf("Din virful 11 avem:\n");
         printf("11->5->12->2->10->1->3->4->6->7->8->9->13->14->15->16->17->18->19->20");break;
case 12:printf("Din virful 12 avem:\n");
         printf("12->5->2->10->11->1->3->4->6->7->8->9->13->14->15->16->17->18->19->20");break;
case 13:printf("Din virful 13 avem:\n");
         printf("13-6->14->3->18->19->7->1->20->15->4->2->8->9->5->16->17->10->11->12>");break;
case 14:printf("Din virful 14 avem:\n");
         printf("14->6->18->19->3->13->20->7->1->15->4->2->8->9->5->16->17->10->11->12");break;
case 15:printf("Din virful 15 avem:\n");
         printf("15->7->3->1->6->4->2->13->14->8->9->5->18->19->16->17->10->11->12->20");break;
case 16:printf("Din virful 16 avem:\n");
         printf("16->8->4->9->1->17->2->3->5->6->7->10->11->12->13->14->15->18->19->20");break;
case 17:printf("Din virful 17 avem:\n");
         printf("17->9->4->1->8->2->3->16->5->6->7->10->11->12->13->14->15->18->19->20");break;
case 18:printf("Din virful 18 avem:\n");
         printf("18->14->19->6->20->3->13->7->1->15->4->2->8->9->5->16->17->10->11->12");break;
case 19:printf("Din virful 19 avem:\n");
         printf("19->14->20->6->18->3->13->7->1->15->4->2->8->9->5->16->17->10->11->12");break;
case 20:printf("Din virful 20 avem:\n");
         printf("20->19->14->6->18->3->13->7->1->15->4->2->8->9->5->16->17->10->11->12");break;
}getch();
}
//-------------------------------------------------------------------
	     /* Lista de adiacenta */
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
  }}
//-------------------------------------------------------------------
	  		      /* Elaborarea listei */
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
   free(G);}






