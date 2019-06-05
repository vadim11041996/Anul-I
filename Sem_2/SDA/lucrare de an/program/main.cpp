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
            printf("    ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸\n");
            printf("    ³                      >>> MAGAZIN ALIMENTAR  <<<                        ³\n");
            printf("    ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾\n");
    printf("\n");
            printf("                            ÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸\n");
            printf("                            ³      >>> MENU <<<      ³\n");
            printf("                            ÆÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍµ\n");
            printf("                            ³  [1] Indroducere date  ³\n");
            printf("                            ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n");
            printf("                            ³  [2] Adaugare date     ³\n");
            printf("                            ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n");
            printf("                            ³  [3] Afisare date      ³\n");
            printf("                            ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n");
            printf("                            ³  [4] Modificare        ³\n");
            printf("                            ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n");
            printf("                            ³  [5] Sortari           ³\n");
            printf("                            ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n");
            printf("                            ³  [6] Ajutor            ³\n");
            printf("                            ÃÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄÄ´\n");
            printf("                            ³  [7] Iesire            ³\n");
            printf("                            ÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾\n");
            printf("                          Alegeti o optiune intre 1 si 6 \n");
            printf("\n\n\n\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\tÕÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¸\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t³ UTM-FCIM-2016 ³\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\tÔÍÍÍÍÍÍÍÍÍÍÍÍÍÍÍ¾\n");
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


