//data.h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
FILE *f, *f1, *f2, *pf, *pa;
int i,n,j;

struct alimentar{
	char categorie[20];
	char nume[20];
	 int cantitate;
	 float pret;
	 char tara[20];
	}produs1, produs11;
#include "crearea.cpp"
#include "afisare.cpp"
#include "adaugare.cpp"
#include "modificare.cpp"
#include "sortare.cpp"
#include "fsupl.cpp"
#include "ajutor.cpp"
