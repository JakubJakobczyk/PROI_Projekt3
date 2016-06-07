/*
Projekt 3 1812
Autor: Jakub Jakobczyk
Prowadzacy: dr inż. Piotr Witonski
*/

#include <string>
#include "osoba.h"

Osoba::Osoba(Zawod* z, Zamieszkanie *zam, Wyksztalcenie *w, Zainteresowania *zaint)
{
	//std::cout<<"Konstruktor osoby"<<std::endl;
	zainteresowania = zaint;
	zamieszkanie = zam;
	zawod = z;
	wyksztalcenie = w;
}

Osoba::~Osoba()
{
	delete this->zawod;
	delete this->zamieszkanie;
	delete this->wyksztalcenie;
	delete this->zainteresowania;
	//std::cout<<"Destruktor osoby "<<std::endl;
}

void Osoba::wypisz()
{
	std::cout<<"1)Informacje o zatrudnieniu: "<<std::endl;
	zawod->wypiszNazwe();
	std::cout<<std::endl<<"Zarobki: ";
	zawod->wypiszZarobki();
	std::cout<<std::endl;
	zawod->wypiszStaz();
	std::cout<<std::endl<<"2)Informacje o zamieszkaniu:"<<std::endl;
	zamieszkanie->wypiszInformacje();
	std::cout<<std::endl<<"Miejscowosc: ";
	zamieszkanie->wypiszMiejscowosc();
	std::cout<<std::endl<<"3)Informacje o wyksztalceniu:"<<std::endl;
	wyksztalcenie->wypiszWyksztalcenie();
	std::cout<<std::endl;
	wyksztalcenie->wypiszSzkole();
	std::cout<<std::endl<<"4)Informacje o zainteresowaniach:"<<std::endl;
	zainteresowania->wypiszZainteresowania();
}

std::string Osoba::pobierzDane()
{
	std::string s=zawod->pobierzDane();
	s+=zamieszkanie->pobierzDane();
	s+=wyksztalcenie->pobierzDane();
	s+=zainteresowania->pobierzDane();
	
	return s;
}