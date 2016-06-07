/*
Projekt 3 1812
Autor: Jakub Jakobczyk
Prowadzacy: dr in¿. Piotr Witonski
*/



/*Odkomentowac przy debugowaniu, pozwala na sledzenie konstruktorow i destruktorow*/
//#define _DEBUG 1


#include <deque>
#include "program.h"


int Informatyk::ilosc(0);
int Lekarz::ilosc(0);
int Student::ilosc(0);
int Zawod::sumaZarobkow(0);
int Zawod::iloscZatr(0);

int main()
{
	Program *p = new Program;
	p->uruchom();
	
	system("PAUSE");
	return 0;
}