/*
Projekt 3 1812
Autor: Jakub Jakobczyk
Prowadzacy: dr inż. Piotr Witonski
*/

#ifndef ZAMIESZKANIE_H
#define ZAMIESZKANIE_H



#include <string>
#include <iostream>

//#include "informatyk.h"


class Zamieszkanie
{
	protected:
		std::string miejscowosc;
	public:
		//Zawod();
		//virtual ~Zawod() {}
	
		virtual void wypiszMiejscowosc()
		{
			std::cout<<miejscowosc;
		}
		virtual void wypiszInformacje() = 0;
		virtual std::string pobierzDane() = 0;
};


class Mieszkanie : public Zamieszkanie
{
	private:
		int iloscPokoji;
		int powierzchnia;
	public:
		Mieszkanie(std::string msc, int pok, int pow)
		{
			miejscowosc = msc;
			
			iloscPokoji = pok;
			powierzchnia = pow;
		}
		
		void wypiszInformacje()
		{
			std::cout<<"Mieszkanie"<<std::endl;
			std::cout<<"Il pokoji: "<<iloscPokoji<<", powierzchnia: "<<powierzchnia;
		}
		
		std::string pobierzDane()
		{
			std::string s="Mieszkanie\n";
			std::ostringstream ss;
			
			s+=miejscowosc;
			s+="\n";
			ss << iloscPokoji;
			s+=ss.str();
			ss.str("");
			s+="\n";
			ss << powierzchnia;
			s+=ss.str();
			s+="\n";
			
			return s;
		}
};

class Dom : public Zamieszkanie
{
	private:
		int iloscPokoji;
		int powierzchnia;
		bool czyGaraz;
	public:
		Dom(std::string msc, int pok, int pow, bool cGar)
		{
			miejscowosc = msc;
			
			iloscPokoji = pok;
			powierzchnia = pow;
			czyGaraz = cGar;
		}
		
		void wypiszInformacje()
		{
			std::cout<<"Dom"<<std::endl;
			std::cout<<"Ilosc pokoji: "<<iloscPokoji<<", powierzchnia: "<<powierzchnia;
			if(czyGaraz) std::cout<<" + garaz";
		}
		
		std::string pobierzDane()
		{
			std::string s="Dom\n";
			std::ostringstream ss;
			
			s+=miejscowosc;
			s+="\n";
			ss << iloscPokoji;
			s+=ss.str();
			ss.str("");
			s+="\n";
			ss << powierzchnia;
			s+=ss.str();
			if(czyGaraz) s+="\nT";
			else s+="\nN";
			s+="\n";
			
			return s;
		}
};

class Akademik : public Zamieszkanie
{
	private:
		int ilWspolokatorow;
		std::string nazwa;
	public:
		Akademik(std::string msc, int wspol, std::string nzw)
		{
			miejscowosc = msc;
			
			ilWspolokatorow = wspol;
			nazwa = nzw;
		}
		
		void wypiszInformacje()
		{
			std::cout<<"Akademik"<<std::endl<<nazwa;
			
			std::cout<<"Ilosc wspollokatorow: "<<ilWspolokatorow;
		}
		
		std::string pobierzDane()
		{
			std::string s="Mieszkanie\n";
			std::ostringstream ss;
			
			s+=miejscowosc;
			s+="\n";
			ss << ilWspolokatorow;
			s+=ss.str();
			s+="\n";
			s+=nazwa;
			s+="\n";
			
			return s;
		}
};



#endif