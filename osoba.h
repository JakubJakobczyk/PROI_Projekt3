/*
Projekt 3 1812
Autor: Jakub Jakobczyk
Prowadzacy: dr inż. Piotr Witonski
*/

#ifndef OSOBA_H
#define OSOBA_H

#include "zawod.h"
#include "zamieszkanie.h"
#include "zainteresowania.h"
#include "wyksztalcenie.h"

class Osoba
{
	private:
		Zawod *zawod;
		Zamieszkanie *zamieszkanie;
		Zainteresowania *zainteresowania;
		Wyksztalcenie *wyksztalcenie;
	public:
		Osoba(Zawod* z, Zamieszkanie *zam, Wyksztalcenie *w, Zainteresowania *zaint);
		~Osoba();
		void wypisz();
		std::string pobierzDane();
	
	/*friend std::ostream & operator<<(std::ostream &wyjscie, const Osoba &o)
	{
		wyjscie<<"osoba";
		return wyjscie;
	}*/
};

#endif