#ifndef CONTACTE_H
#define CONTACTE_H
#include <iostream>
#include <string>
using namespace std;

class Contacte
{

private:
	string nrTelefon; // Obligatoriu
	string Nume; // Obligatoriu
	string Prenume; // Obligatoriu
	string Companie; // opțional
	string Email; // Opțional
public:
	string getNrTelefon();
	void setNrTelefon(int nrTelefon);
	string getNume();
	void setNume(string nume);
	string getPrenume();
	void setPrenume(string prenume);
	string getCompanie();
	void setCompanie(string companie);
	string getEmail();
	void setEmail(string email);
	void info();
	Contacte();
	Contacte( string nume, string prenume, string nrtelefon, string email, string companie);
	string tostring();
	// Supraîncărcarea operatorului de citire
	friend ostream& operator << (ostream&, const Contacte&);
	friend istream& operator >> (istream&, Contacte&);
};

#endif
