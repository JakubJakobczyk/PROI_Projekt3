/*
Projekt 3 1812
Autor: Jakub Jakobczyk
Prowadzacy: dr inż. Piotr Witonski
*/

#ifndef ZAWOD_H
#define ZAWOD_H



#include <string>
#include <iostream>
#include<sstream>


class Zawod
{
	protected:
		static int sumaZarobkow;
		static int iloscZatr;
		int zarobki;
		int staz;
		std::string nazwa;
	public:
		//Zawod();
		//virtual ~Zawod() {}
		
		virtual void wypiszNazwe()
		{
			std::cout<<nazwa;
		}
		virtual void wypiszZarobki()
		{
			std::cout<<zarobki;
		}
		virtual void wypiszStaz()
		{
			std::cout<<"Doswiadczenie: "<<staz<<" lat";
		}
		virtual std::string pobierzDane()
		{
			std::string s;
			std::ostringstream ss;
			
			s = nazwa;
			s+="\n";
			ss << staz;
			s+=ss.str();
			ss.str("");
			s+="\n";
			ss << zarobki;
			s+=ss.str();
			s+="\n";
			return s;
		}
};


class Informatyk : public Zawod
{
	private:
		static int ilosc;
	public:
		Informatyk(int st, int zar)
		{
			staz = st;
			zarobki = zar;
			nazwa = "Informatyk";
			ilosc++;
			iloscZatr++;
			sumaZarobkow+=zar;
		}
		static void ilePracuje()
		{
			std::cout<<ilosc;
		}
};

class Lekarz : public Zawod
{
	private:
		static int ilosc;
	public:
		Lekarz(int st, int zar)
		{
			staz = st;
			zarobki = zar;
			nazwa = "Lekarz";
			ilosc++;
			iloscZatr++;
			sumaZarobkow+=zar;
		}
		static void ilePracuje()
		{
			std::cout<<ilosc;
		}
};

class Student : public Zawod
{
	private:
		static int ilosc;
	public:
		Student(int st, int styp)
		{
			staz = st;
			zarobki = styp;
			nazwa = "Student";
			ilosc++;
		}
		static void ileStudentow()
		{
			std::cout<<ilosc;
		}
		void wypiszZarobki()
		{
			std::cout<<"Nie dotyczy"<<std::endl<<"Stypendium: ";
			if(zarobki==0)std::cout<<"brak";
			else std::cout<<zarobki;
		}
		void wypiszStaz()
		{
			std::cout<<"Rok nr: "<<staz;
		}
};

class Inny : public Zawod
{
	private:
	public:
		Inny(std::string nzw, int st, int zar)
		{
			staz = st;
			zarobki = zar;
			nazwa = nzw;
			sumaZarobkow+=zar;
			iloscZatr++;
		}
		
		static int getSumaZarobkow()
		{
			return sumaZarobkow;
		}
		
		static int getIlosZatrudnionych()
		{
			return iloscZatr;
		}
};



#endif