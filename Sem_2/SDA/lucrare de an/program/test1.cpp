#include <graphics.h> 	// biblioteca primitive grafice
#include <stdlib.h>
int main()
{

   int graphdriver, graphmode;
   int left,top,right,bottom;
   graphdriver = DETECT;
   initgraph(&graphdriver, &graphmode, " ");
   left=top=0;
   printf("Introduceti right: ", right);
   scanf("%d", &right);
   printf("Introduceti bottom: ", bottom);
   scanf("%d", &bottom);
   rectangle(left,top,right,bottom);
   getch();
   closegraph();
   return 0;
}
