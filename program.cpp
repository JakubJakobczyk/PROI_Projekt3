/*
Projekt 3 1812
Autor: Jakub Jakobczyk
Prowadzacy: dr inż. Piotr Witonski
*/

#include <iostream>
#include <cstdlib>
#include <string>
#include <deque>
#include <fstream>


#include "program.h"
#include "osoba.h"

using namespace std;

Program::Program()
{
	
}

void Program::uruchom()
{
	string ster, plik;
	do
	{
		wypiszOpcje();
		getline(cin, ster);
		if(ster=="1")
		{
			kwestionariusz.push_back(przeprowadzAnkiete());
		}
		else if(ster=="2")
		{
			wyswietlWyniki();
		}
		else if(ster=="3")
		{
			cout<<"Podaj nazwe pliku (podanie nazwy juz istniejacego nadpisuje go)"<<endl;
			getline(cin, plik);
			try
			{
				zapiszDoPliku(plik);
			}
			catch(int e)
			{
				cout<<"Blad!"<<endl;
			}
		}
		else if(ster=="4")
		{
			cout<<"Podaj nazwe pliku"<<endl;
			getline(cin, plik);
			try
			{
				wczytajZPliku(plik);
			}
			catch(int e)
			{
				cout<<"Blad: ";
				if(e==1) cout<<"Nie znaleziono pliku"<<endl;
				else cout<<"nieznany blad"<<endl;
			}
		}
		else if(ster!="0")
		{
			cout<<"Nieznana komenda"<<endl;
		}
	}while(ster!="0");
	
	kwestionariusz.clear();
}

void Program::wypiszOpcje()
{
	cout<<endl<<"-------------------"<<endl;
	cout<<"[0] - zakoncz"<<endl;
	cout<<"[1] - dodaj ankiete"<<endl;
	cout<<"[2] - pokaz wyniki ankiety"<<endl;
	cout<<"[3] - zapisz wyniki do pliku"<<endl;
	cout<<"[4] - wczytaj wyniki z pliku"<<endl;
}

void Program::wyswietlWyniki()
{
	int a, b;
	cout<<"Liczba osob ktore wziely udzial w ankiecie: "<<kwestionariusz.size()<<endl;
	for (int i = 0; i<kwestionariusz.size(); i++)
	{
		cout<<endl<<"Osoba nr: "<<i+1<<endl;
		kwestionariusz[i]->wypisz();
		cout<<endl;
	}
	cout<<endl<<"Informatycy:";
	Informatyk::ilePracuje();
	cout<<endl<<"Lekarze:";
	Lekarz::ilePracuje();
	cout<<endl<<"Studenci: ";
	Student::ileStudentow();
	a = Inny::getSumaZarobkow();
	b = Inny::getIlosZatrudnionych();
	if(b!=0) cout<<endl<<"Srednie zarobki osob zatrudnionych: "<<(a/b)<<endl;
}

Osoba* Program::przeprowadzAnkiete()
{
	Osoba *o;
	Zawod *z;
	Zamieszkanie *m;
	Wyksztalcenie *w;
	Zainteresowania *zai;
	cout<<"Dodawanie informacji o uczestniku badania"<<endl;
	try
	{
		//z=dodajZawod();
		//m=dodajZamieszkanie();
		//w=dodajWyksztalcenie();
		//zai=dodajZainteresowania();
	}
	catch(int err)
	{
		cout<<"Blad: ";
		if(err==1) cout<<"Wprowadzone dana nie jest liczba naturalna"<<endl;
		else cout<<"Nieznany blad"<<endl;
		
		cout<<"Anulowanie dotychczasowo wprowadzonych danych"<<endl;
		if(z!=NULL) delete z;
		if(m!=NULL) delete m;
		if(w!=NULL) delete w;
		if(zai!=NULL) delete zai;
	}
	z = new Informatyk(2, 4500);
	m = new Dom("AAA", 1, 100, false);//(std::string msc, int pok, int pow, bool cGar)
	w = new Wyzsze("PW","magister inzynier","elektronika");//(std::string szkl, std::string ttl, std::string kier)
	zai = new GryKomputerowe("RPG");
	return new Osoba(z, m, w, zai);//(Zawod* z, Zamieszkanie *zam, Wyksztalcenie *w, Zainteresowania *zaint);
}

Zawod* Program::dodajZawod()
{
	string nzw, pom;
	int staz, zarob;
	cout<<"Dodawanie informacji o zatrudnieniu"<<endl<<"Podaj nazwe:"<<endl;
	getline(cin, nzw);
	
	if (nzw=="Student"||nzw=="student")
	{
		cout<<"Ktory rok?"<<endl;
		staz = pobierzLNat();
		cout<<"Podaj kwote stypendium(0 jesli nie dotyczy)"<<endl;
		zarob = pobierzLNat();
		return new Student(staz, zarob);
	}
	else
	{
		if(nzw=="Informatyk"||nzw=="informatyk")
		{
			cout<<"Podaj staz w latach"<<endl;
			staz = pobierzLNat();
			cout<<"Podaj zarabiana kwote w PLN"<<endl;
			zarob = pobierzLNat();
			return new Informatyk(staz, zarob);
		}
		else if (nzw=="Lekarz"||nzw=="lekarz")
		{
			cout<<"Podaj staz w latach"<<endl;
			staz = pobierzLNat();
			cout<<"Podaj zarabiana kwote w PLN"<<endl;
			zarob = pobierzLNat();
			return new Lekarz(staz, zarob);
		}
		else
		{
			cout<<"Podaj nazwe zawodu"<<endl;
			getline(cin,pom);
			cout<<"Podaj staz w latach"<<endl;
			staz = pobierzLNat();
			cout<<"Podaj zarabiana kwote w PLN"<<endl;
			zarob = pobierzLNat();
			return new Inny(pom, staz, zarob);
		}
	}
}

Zamieszkanie* Program::dodajZamieszkanie()
{
	string pom, mjsc; //(std::string msc, int pok, int pow, bool cGar)
	int pok, pow;
	cout<<"Dodawanie informacji o zamieszkaniu"<<endl<<"Podaj miejscowosc"<<endl;
	getline(cin, mjsc);
	cout<<"Podaj typ(mieszkanie/dom/akademik):"<<endl;
	getline(cin, pom);
	if(pom=="mieszkanie"||pom=="Mieszkanie")
	{
		cout<<"Podaj liczbe pokoji"<<endl;
		pok = pobierzLNat();
		cout<<"Podaj powierzchnie"<<endl;
		pow = pobierzLNat();
		return new Mieszkanie(mjsc, pok, pow);
	}
	else if(pom=="dom"||pom=="Dom")
	{
		cout<<"Podaj liczbe pokoji"<<endl;
		pok = pobierzLNat();
		cout<<"Podaj powierzchnie"<<endl;
		pow = pobierzLNat();
		cout<<"Podaj czy ma garaz(T/N)";
		getline(cin, pom);
		if(pom=="t"||pom=="T") return new Dom(mjsc, pok, pow, true);
		else if(pom=="n"||pom=="N") return new Dom(mjsc, pok, pow, false);
		else throw 2;
	}
	else if(pom=="akademik"||pom=="Akademik")
	{
		cout<<"Podaj nazwe akademika";
		getline(cin, pom);
		cout<<"Podaj liczbe wspollokatorow"<<endl;
		pok = pobierzLNat();
		return new Akademik(mjsc, pok, pom);
	}
	else throw 2;
}

Wyksztalcenie* Program::dodajWyksztalcenie()
{
	//("PW","inzynier","robienie halasu")
	string ttl, kier, pom;
	cout<<"Dodawanie informacji o wyksztalceniu"<<endl<<"Podaj wyksztalcenie"<<endl;
	getline(cin, pom);
	if(pom=="wyzsze"||pom=="Wyzsze")
	{
		cout<<"Podaj tytul"<<endl;
		getline(cin, ttl);
		cout<<"Podaj kierunek"<<endl;
		getline(cin, kier);
		cout<<"Podaj nazwe ukonczonej szkoly wyzszej"<<endl;
		getline(cin, pom);
		return new Wyzsze(pom, ttl, kier);
	}
	else if(pom=="srednie"||pom=="Srednie")
	{
		cout<<"Podaj nazwe szkoly"<<endl;
		getline(cin, pom);
		cout<<"Okresl czy technikum (T/N)"<<endl;
		getline(cin, kier);
		if(kier=="t"||kier=="T") return new Srednie(pom, true);
		else if(kier=="n"||kier=="N") return new Srednie(pom, false);
		else throw 2;
	}
	else if(pom=="zawodowe"||pom=="Zawodowe")
	{
		cout<<"Podaj nazwe szkoly"<<endl;
		getline(cin, pom);
		cout<<"Podaj zawod"<<endl;
		getline(cin, kier);
		return new ZasadniczeZawodowe(pom, kier);
	}
	else throw 2;
}

Zainteresowania* Program::dodajZainteresowania()
{
	string pom;
	cout<<"Dodawanie informacji o zainteresowaniach"<<endl<<"Podaj hobby"<<endl;
	getline(cin, pom);
	if(pom=="sport"||pom=="Sport")
	{
		cout<<"Podaj dyscypline"<<endl;
		getline(cin, pom);
		return new Sport(pom);
	}
	else if(pom=="gry komputerowe"||pom=="Gry komputerowe")
	{
		cout<<"Podaj gatunek"<<endl;
		getline(cin, pom);
		return new GryKomputerowe(pom);
	}
	else return new Inne(pom);
}

bool Program::czyLiczba(string &str)
{ 
	int i = str.length()-1;
	for(; i>=0; i--)
	{
		if(!isdigit(str[i])) return false;
	}
	return true;
}

int Program::pobierzLNat()
{
	string pom;
	int i;
	getline(cin, pom);
	if(czyLiczba(pom))
	{
		i = atoi(pom.c_str());
		if(i<0) throw 2;
	}
	else throw 1;
	return i;
}

void Program::zapiszDoPliku(string nazwa)
{
	ofstream plik;
	plik.open (nazwa);
	if (!plik.is_open()) throw 1;
	
	for (int i = 0; i<kwestionariusz.size(); i++)
	{
		plik<<kwestionariusz[i]->pobierzDane();
	}
	
	plik.close();
}

void Program::wczytajZPliku(std::string nazwa)
{
	ifstream plik;
	string linia, temp, szkl, ttl, kier, mjsc;
	int a ,b;
	Zawod *z;
	Zamieszkanie *m;
	Zainteresowania *zai;
	Wyksztalcenie *w;
	
	plik.open (nazwa, ios::in);
	if (!plik.is_open()) throw 1;
	
	while (getline(plik, temp))
	{
		getline(plik, linia);
		a = atoi(linia.c_str());
		getline(plik, linia);
		b = atoi(linia.c_str());
		
		if(temp=="Student") z = new Student(a,b);
		else if(temp=="Informatyk") z = new Informatyk(a,b);
		else if(temp=="Lekarz") z = new Lekarz(a,b);
		else z = new Inny(temp, a, b);
		
		getline(plik, temp);
		getline(plik, mjsc);
		if(temp=="Dom")
		{
			getline(plik, linia);
			a = atoi(linia.c_str());
			getline(plik, linia);
			b = atoi(linia.c_str());
			getline(plik, temp);
			if(temp == "T") m = new Dom(mjsc, a, b, true);
			else m = new Dom(mjsc, a, b, false);
		}
		else if(temp=="Mieszkanie")
		{
			getline(plik, linia);
			a = atoi(linia.c_str());
			getline(plik, linia);
			b = atoi(linia.c_str());
			m = new Mieszkanie(mjsc, a, b);
		}
		else if(temp=="Akademik")
		{
			getline(plik, linia);
			a = atoi(linia.c_str());
			getline(plik, temp);
			m = new Akademik(mjsc, a, temp);
		}
		
		
		getline(plik, temp);
		getline(plik, szkl);
		if(temp=="Wyzsze")
		{
			getline(plik, ttl);
			getline(plik, kier);
			w = new Wyzsze(szkl, ttl, kier);
		}
		else if(temp=="Srednie")
		{
			getline(plik, kier);
			if(kier == "T") w = new Srednie(szkl, true);
			else w = new Srednie(szkl, false);
		}
		else if(temp=="Zawodowe")
		{
			getline(plik, kier);
			w = new ZasadniczeZawodowe(szkl, kier);
		}
		
		getline(plik, temp);
		if(temp=="Gry komputerowe")
		{
			getline(plik, temp);
			zai = new GryKomputerowe(temp);
		}
		else if(temp=="Sport")
		{
			getline(plik, temp);
			zai = new Sport(temp);
		}
		else zai = new Inne(temp);
		kwestionariusz.push_back(new Osoba(z, m, w, zai));
		
		
	}
	
	plik.close();
}