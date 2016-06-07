/*
Projekt 3 1812
Autor: Jakub Jakobczyk
Prowadzacy: dr inż. Piotr Witonski
*/

#ifndef PROGRAM_H
#define PROGRAM_H

#include "osoba.h"
#include "zawod.h"
#include "zamieszkanie.h"
#include "zainteresowania.h"
#include "wyksztalcenie.h"
#include "program.h"

class Program
{
	private:
		void wypiszOpcje();
		std::deque<Osoba*> kwestionariusz;
		Osoba* przeprowadzAnkiete();
		Zawod* dodajZawod();
		Zamieszkanie* dodajZamieszkanie();
		Zainteresowania* dodajZainteresowania();
		Wyksztalcenie* dodajWyksztalcenie();
		bool czyLiczba(std::string&);
		int pobierzLNat();
		void wyswietlWyniki();
		void zapiszDoPliku(std::string nazwa);
		void wczytajZPliku(std::string nazwa);
	public:
		Program();
		void uruchom();
	
	/*friend std::ostream & operator<<(std::ostream &wyjscie, const Osoba &o)
	{
		wyjscie<<"osoba";
		return wyjscie;
	}*/
};

#endif