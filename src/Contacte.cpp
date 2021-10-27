#include "Contacte.h"
#include <iostream>
#include <sstream>
using namespace std;

string Contacte::getNrTelefon()
{
	return this->nrTelefon;
}
void Contacte::setNrTelefon(int nrTelefon)
{
	this->nrTelefon = nrTelefon;
}
string Contacte::getNume()
{
	return this->Nume;
}
void Contacte::setNume(string nume)
{
	this->Nume = nume;
}
string Contacte::getPrenume()
{
	return this->Prenume;
}
void Contacte::setPrenume(string prenume)
{
	this->Prenume = prenume;
}
string Contacte::getCompanie()
{
	return this->Companie;
}
void Contacte::setCompanie(string companie)
{
	this->Companie = companie;
}
string Contacte::getEmail()
{
	return this->Email;
}
void Contacte::setEmail(string email)
{
	this->Email = email;
}
void Contacte::info()
{
    cout<<"Numar:"<<nrTelefon<<endl;
    cout<<"Nume:"<<Nume<<endl;
    cout<<"Prenume:"<<Prenume<<endl;
    cout<<"Companie:"<<Companie<<endl;
    cout<<"Email:"<<Email<<endl;
}
Contacte::Contacte(){}
// Constructorul funcției
Contacte::Contacte( string nume, string prenume, string nrtelefon, string email, string companie)
{
	this->nrTelefon = nrtelefon;
	this->Nume = nume;
	this->Prenume = prenume;
	this->Companie = companie;
	this->Email = email;
}

string Contacte::tostring()
{
    stringstream buffer;
    buffer<<this->Nume<<";"<<this->Prenume<<";"<<this->nrTelefon<<";"<<this->Email<<";"<<this->Companie<<endl;
    return buffer.str();
}
// Operatorul de scriere
ostream& operator << (ostream& output, const Contacte& contact)
{

	output <<"Contact "<<endl<< "Nume >> " << contact.Nume << endl << "Prenume >> " << contact.Prenume
		<< endl << "Numar Telefon >> " << contact.nrTelefon << endl
		<< "Email >> " << contact.Email << endl << "Companie >> "
		<< contact.Companie << endl<<endl;

	return output;
}
// Operatorul de citire
istream& operator >> (istream& input, Contacte& Contact)
{
	cout << "Introdu un Nume >> ";
	input >> Contact.Nume;
	cout << "Introdu un Prenume >> ";
	input >> Contact.Prenume;
	cout << "Introdu un Numar de Telefon >> ";
	input >> Contact.nrTelefon;
	cout << "Introdu un Email/- (optional) >> ";
	input >> Contact.Email;
	cout << "Introdu o Companie/- (optional) >> ";
	input >> Contact.Companie;
	return input;
}
