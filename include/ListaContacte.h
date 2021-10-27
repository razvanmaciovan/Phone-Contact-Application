#ifndef LISTACONTACTE_H
#define LISTACONTACTE_H
#include "Contacte.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class ListaContacte
{
public:
	vector<Contacte>listaContacte;

	ListaContacte();
	~ListaContacte();
	void add(Contacte &c);
    vector<Contacte> get_all() {return this->listaContacte;};
    void load();
    void save();
    void stergere(string s);
    int cautarestergere(string s);
    void block(string s);
    int cautarefiltru(string s);
    void afisarecautare(string s);
    void loadblock();
};

#endif
