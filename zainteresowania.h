/*
Projekt 3 1812
Autor: Jakub Jakobczyk
Prowadzacy: dr inż. Piotr Witonski
*/

#ifndef ZAINTERESOWANIA_H
#define ZAINTERESOWANIA_H



#include <string>
#include <iostream>



class Zainteresowania
{
	protected:
		std::string nazwa;
	public:
	
		virtual void wypiszZainteresowania() = 0;
		virtual std::string pobierzDane() = 0;
};


class Sport : public Zainteresowania
{
	private:
		std::string szczegol;
	public:
		Sport(std::string szcg)
		{
			szczegol = szcg;
			nazwa = "Sport";
		}
		
		void wypiszZainteresowania()
		{
			std::cout<<nazwa<<", "<<szczegol;
			
		}
		
		virtual std::string pobierzDane()
		{
			std::string s;
			
			s = nazwa;
			s+="\n";
			s+=szczegol;
			s+="\n";
			
			return s;
		}
};

class GryKomputerowe : public Zainteresowania
{
	private:
		std::string jakie;
	public:
		GryKomputerowe(std::string jk)
		{
			jakie = jk;
			nazwa = "Gry komputerowe";
		}
		void wypiszZainteresowania()
		{
			std::cout<<nazwa<<", "<<jakie;
		}
		
		virtual std::string pobierzDane()
		{
			std::string s;
			
			s = nazwa;
			s+="\n";
			s+=jakie;
			s+="\n";
			
			return s;
		}
};

class Inne : public Zainteresowania
{
	public:
		Inne(std::string nzw)
		{
			nazwa = nzw;
		}
		void wypiszZainteresowania()
		{
			std::cout<<nazwa;
		}
		
		virtual std::string pobierzDane()
		{
			return (nazwa+"\n");
		}
};



#endif