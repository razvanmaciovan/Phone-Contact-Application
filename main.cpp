//Sistem de contacte
//Aplicația permite stocarea detaliilor despre contacte, precum: număr telefon(obligatoriu),
//label contact(obligatoriu), companie(opțional), email(opțional) etc.Aplicația permite
//adăugarea de noi contacte, ștergerea unui contact existent, blocarea numerelor nedorite și
//căutări în funcție de oricare câmp(selectat în prealabil) al unui contact.

#include "Contacte.h"
#include "ListaContacte.h"
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
#include <fstream>
using std::cin; using std::cout; using std::endl;
ListaContacte lista;
void ListaContacte();
void Meniu();
void ReturnMeniu();
void AdaugaContact();
void StergeContact();
void BlocareNumar();
void CautareContact();
void BlockList();
Contacte contact;
int main()
{

    int length;
    ifstream filestr;

    filestr.open("agenda.txt", ios::binary); // open your file
    filestr.seekg(0, ios::end); // put the "cursor" at the end of the file
    length = filestr.tellg(); // find the position of the cursor
    filestr.close(); // close your file
    if(length<=2);
    else lista.load();


	Meniu();


	return 0;
}

void Meniu()
{

	string Alegere;
	cout << "Management Contacte\n\n" << "(1) Lista Contacte\n" << "(2) Adauga Contact Nou\n"
		<< "(3) Sterge Contact Existent\n" << "(4) Blocheaza Numar Telefon\n"
		<< "(5) Cautare Contacte\n" << "(6) Contacte Blocate\n\n" << "(7) Iesire\n\n" << "Introdu optiunea dorita >> ";
	cin >> Alegere;
	if (Alegere[0] == '1') { system("cls");  ListaContacte(); }
	if (Alegere[0] == '2') { system("cls");  AdaugaContact(); }
	if (Alegere[0] == '3') { system("cls");  StergeContact(); }
	if (Alegere[0] == '4') { system("cls");  BlocareNumar(); }
	if (Alegere[0] == '5') { system("cls");  CautareContact(); }
	if (Alegere[0] == '6') { system("cls");  BlockList(); }
	if (Alegere[0] == '7') exit(0);
	else { system("cls"); cout << "Introdu o optiune corecta !\n\n"; Meniu(); }
}
void ReturnMeniu()
{
	char Alegere;
	cout << "\nVrei sa te intorci la Meniul Principal ? (Y/N) >> ";
	cin >> Alegere;
	if (tolower(Alegere) == 'y') { system("cls"); Meniu(); }
	if (tolower(Alegere) == 'n') exit(0);
	else
	{
		system("cls");
		cout << "Introdu o optiune valida !\n";
		ReturnMeniu();
	}
}
void ListaContacte()
{

    vector<Contacte> list = lista.get_all();
    for (auto &a : list)
        cout<<a;


	ReturnMeniu();
}
void AdaugaContact()
{
    Contacte c1;
	cin>>c1;
	lista.add(c1);
	lista.save();
	ReturnMeniu();
}
void StergeContact()
{
    string s;
	cout<<"Introduceti numarul de telefon al contactului care sa fie sters"<<endl;
	cin>>s;
	lista.stergere(s);
	lista.save();
	ReturnMeniu();
}
void BlocareNumar()
{
    string s;
	cout<<"Introduceti numarul de telefon al contactului care sa fie blocat. Acest proces nu este reversibil!"<<endl;
	cin>>s;
	lista.block(s);
	lista.stergere(s);
	lista.save();
	ReturnMeniu();
}
void CautareContact()
{
    string s;
	cout << "Introduceti nume/prenume/telefon/email/companie"<<endl;
	cin>>s;
    lista.afisarecautare(s);
	ReturnMeniu();
}
void BlockList()
{
    lista.loadblock();
    ReturnMeniu();
}
