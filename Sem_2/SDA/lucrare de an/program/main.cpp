//main.cpp
/* Lucrare de an
Tema : Magazine
Autor : Braduleac Vadim
Grupa : AI-151
*/
#include "data.h"
main()
{
	int option;
	while(1)
	{
	        system("COLOR 9");
            system("Cls");
            printf("    嬪様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様邑\n");
            printf("    �                      >>> MAGAZIN ALIMENTAR  <<<                        �\n");
            printf("    塒様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様様余\n");
    printf("\n");
            printf("                            嬪様様様様様様様様様様様邑\n");
            printf("                            �      >>> MENU <<<      �\n");
            printf("                            突様様様様様様様様様様様裕\n");
            printf("                            �  [1] Indroducere date  �\n");
            printf("                            団陳陳陳陳陳陳陳陳陳陳陳調\n");
            printf("                            �  [2] Adaugare date     �\n");
            printf("                            団陳陳陳陳陳陳陳陳陳陳陳調\n");
            printf("                            �  [3] Afisare date      �\n");
            printf("                            団陳陳陳陳陳陳陳陳陳陳陳調\n");
            printf("                            �  [4] Modificare        �\n");
            printf("                            団陳陳陳陳陳陳陳陳陳陳陳調\n");
            printf("                            �  [5] Sortari           �\n");
            printf("                            団陳陳陳陳陳陳陳陳陳陳陳調\n");
            printf("                            �  [6] Ajutor            �\n");
            printf("                            団陳陳陳陳陳陳陳陳陳陳陳調\n");
            printf("                            �  [7] Iesire            �\n");
            printf("                            塒様様様様様様様様様様様余\n");
            printf("                          Alegeti o optiune intre 1 si 6 \n");
            printf("\n\n\n\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t嬪様様様様様様様�\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t� UTM-FCIM-2016 �\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t塒様様様様様様様�\n");
    option = getch();
    switch(option)
                  {
                                    case '1' : crearea(); break;
									case '2' : adaugare(); break;
                                    case '3' : afisare();break;
                                    case '4' : modificare();break;
                                    case '5' : sortare();break;
                                    case '6' : ajutor();break;
                                    case '7' :
                    system("COLOR 16");
                    system("Cls");
                    printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");
	                printf("\t\t\t\t\t");
	                puts("Creat de Braduleac Vadim");
	    			printf("\t\t\t\t\t");
	    			puts("mail: vadim11041996@bk.ru");
	   				printf("\t\t\t\t\t");
	   				puts("tel:  068690110");
	  			    puts("\n");
	  				printf("\t\t\t\t\t");
	  				puts("Acest produs este protejat !!!");
	  			    puts("\n");
	  				printf("\t\t\t\t\t");
	   				puts("Toate drepturile sunt rezervate !!!");
					getch();
					return 0;
                  }
    }
}


