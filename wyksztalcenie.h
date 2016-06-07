/*
Projekt 3 1812
Autor: Jakub Jakobczyk
Prowadzacy: dr inż. Piotr Witonski
*/

#ifndef WYKSZTALCENIE_H
#define WYKSZTALCENIE_H



#include <string>
#include <iostream>



class Wyksztalcenie
{
	protected:
		std::string szkola;
		int rokUkonczenia;
	public:
		virtual void wypiszWyksztalcenie() = 0;
		virtual void wypiszSzkole() = 0;
		virtual std::string pobierzDane() = 0;
};


class Wyzsze : public Wyksztalcenie
{
	private:
		std::string tytul;
		std::string kierunek;
	public:
		Wyzsze(std::string szkl, std::string ttl, std::string kier)
		{
			szkola = szkl;
			tytul = ttl;
			kierunek = kier;
		}
		
		void wypiszWyksztalcenie()
		{
			std::cout<<"Wyksztalcenie: wyzsze, "<<tytul;
		}
		
		void wypiszSzkole()
		{
			std::cout<<"Ukonczona szkola wyzsza: "<<szkola<<", kierunek: "<<kierunek;
		}
		
		std::string pobierzDane()
		{
			std::string s;
			
			s = "Wyzsze\n";
			s+=szkola;
			s+="\n";
			s+=tytul;
			s+="\n";
			s+=kierunek;
			s+="\n";
			
			return s;
		}
};

class Srednie : public Wyksztalcenie
{
	private:
		bool czyTechnikum;
		
	public:
		Srednie(std::string szkl, bool cT)
		{
			szkola = szkl;
			czyTechnikum = cT;
		}
		
		void wypiszWyksztalcenie()
		{
			std::cout<<"Wyksztalcenie: srednie"<<std::endl;
		}
		void wypiszSzkole()
		{
			std::cout<<"Ukonczona szkola: "<<szkola<<std::endl<<"Typ: ";
			if(czyTechnikum) std::cout<<"Technikum";
			else std::cout<<"Liceum";
		}
		
		std::string pobierzDane()
		{
			std::string s;
			
			s = "Srednie\n";
			s+=szkola;
			s+="\n";
			if(czyTechnikum) s+="T";
			else s+="N";
			s+="\n";
			
			return s;
		}
};

class ZasadniczeZawodowe : public Wyksztalcenie
{
	private:
		std::string zawod;
	public:
		ZasadniczeZawodowe(std::string szkl, std::string zwd)
		{
			szkola = szkl;
			zawod = zwd;
		}
		
		void wypiszWyksztalcenie()
		{
			std::cout<<"Wyksztalcenie: zasadnicze zawodowe"<<std::endl;
		}
		void wypiszSzkole()
		{
			std::cout<<"Ukonczona szkola: "<<szkola<<std::endl<<"Zdobyty zawod: "<<zawod;
		}
		
		std::string pobierzDane()
		{
			std::string s;
			
			s = "Zawodowe\n";
			s+=szkola;
			s+="\n";
			s+=zawod;
			s+="\n";
			
			return s;
		}
};



#endif