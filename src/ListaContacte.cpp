#include "ListaContacte.h"
#include <fstream>
#include <sstream>
vector<string> tokenize(string str, char delimiter) {
    vector<string> result;
    stringstream ss(str);
    string token;
    while (getline(ss, token, delimiter))
        result.push_back(token);

    return result;
}

ListaContacte::ListaContacte() {
}

ListaContacte::~ListaContacte() {
}

void ListaContacte::add(Contacte &c) {
    this->listaContacte.push_back(c);
}
void ListaContacte::load()
{
    string v;


    ifstream f("agenda.txt");
    while(getline(f,v))
    {
        vector<string>rez = tokenize(v,';');
        Contacte c1{rez[0],rez[1],rez[2],rez[3],rez[4]};
        this->listaContacte.push_back(c1);
    }
    f.close();


}
void ListaContacte::save()
{
    ofstream g("agenda.txt");
    for(auto &a:this->listaContacte)
    {
        g<<a.tostring();
    }
    g.close();
}
void ListaContacte::stergere(string s){
    int index = this->cautarestergere(s);
    if(index == -1)
    {
        cout<<"Asigura te ca acest contact exista"<<endl;
    }
    else
    this->listaContacte.erase(this->listaContacte.begin()+index);
}
int ListaContacte::cautarestergere(string s) {
    for (int i=0; i<this->listaContacte.size(); i++) {
        if (this->listaContacte[i].getNrTelefon() == s)
            return i;
    }
    return -1;
}
void ListaContacte::block(string s)
{
    int index = this->cautarestergere(s);
    if(index == -1)
    {
        cout<<"Contactul nu exista!"<<endl;
    }
    else
    {
    ofstream g;
    g.open("block.txt",std::ios_base::app);
    g<<listaContacte[index].tostring();
    g.close();
    }
}
int ListaContacte::cautarefiltru(string s) {
    for (int i=0; i<this->listaContacte.size(); i++) {
        if (this->listaContacte[i].getNrTelefon() == s || this->listaContacte[i].getNume() == s || this->listaContacte[i].getPrenume() == s || this->listaContacte[i].getCompanie() == s || this->listaContacte[i].getEmail() == s)
            return i;
    }
    return -1;
}
void ListaContacte::afisarecautare(string s)
{

    int index = this->cautarefiltru(s);
    if(index == -1) cout<<"Contactul nu a fost gasit sau nu exista";
    else cout<<listaContacte[index];

}
void ListaContacte::loadblock()
{
    string v;
    char str[100];
    ifstream f("block.txt");
    getline(f,v);
    while(getline(f,v))
    {
        vector<string>rez = tokenize(v,';');
        Contacte c1{rez[0],rez[1],rez[2],rez[3],rez[4]};
        cout<<c1<<endl;

    }
    f.close();
}
