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
            printf("    ������������������������������������������������������������������������͸\n");
            printf("    �                      >>> MAGAZIN ALIMENTAR  <<<                        �\n");
            printf("    ������������������������������������������������������������������������;\n");
    printf("\n");
            printf("                            ������������������������͸\n");
            printf("                            �      >>> MENU <<<      �\n");
            printf("                            ������������������������͵\n");
            printf("                            �  [1] Indroducere date  �\n");
            printf("                            ������������������������Ĵ\n");
            printf("                            �  [2] Adaugare date     �\n");
            printf("                            ������������������������Ĵ\n");
            printf("                            �  [3] Afisare date      �\n");
            printf("                            ������������������������Ĵ\n");
            printf("                            �  [4] Modificare        �\n");
            printf("                            ������������������������Ĵ\n");
            printf("                            �  [5] Sortari           �\n");
            printf("                            ������������������������Ĵ\n");
            printf("                            �  [6] Ajutor            �\n");
            printf("                            ������������������������Ĵ\n");
            printf("                            �  [7] Iesire            �\n");
            printf("                            ������������������������;\n");
            printf("                          Alegeti o optiune intre 1 si 6 \n");
            printf("\n\n\n\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t���������������͸\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t� UTM-FCIM-2016 �\n");
            printf("\t\t\t\t\t\t\t\t\t\t\t\t���������������;\n");
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


