#include<iostream>
#include "Graf_complet.h"
using namespace std;

Graf_complet::Graf_complet(): Graf(){
    this->nr_muchii=0;
}

Graf_complet::Graf_complet(int nr_noduri,int nr_muchii):Graf(nr_noduri){
    this->nr_muchii=nr_muchii;
}

Graf_complet::Graf_complet(const Graf_complet &complet): Graf(complet){
    this->nr_muchii=complet.nr_muchii;
}

int Graf_complet:: grafecomplet(){
    if(this->nr_muchii>=(this->nr_noduri*(this->nr_noduri-1))/2)
        return 1;
    else
        return 0;

}

int Graf_complet:: getMuchii(){
    return this->nr_muchii;
}

void Graf_complet::setMuchii(int nr_muchii){
    this->nr_muchii=nr_muchii;
}

Graf_complet& Graf_complet:: operator=(const Graf_complet &complet){
    if(this == &complet)
        return *this;
    nr_muchii=complet.nr_muchii;
    nr_noduri=complet.nr_noduri;
    return *this;
}

void Graf_complet::print(ostream &out) const{
    Graf::print(out);
    out<<"\nNumarul de muchii al grafului este: "<<nr_muchii;

}
void Graf_complet::read(istream &in){
    Graf::read(in);
    cout<<"Citeste numarul de muchii: ";
    in>>nr_muchii;
}

istream &operator>>(istream &in, Graf_complet &complet){
    complet.read(in);
    return in;

}

ostream &operator<<(ostream &out,const Graf_complet &complet){
    out<<"Afisarea unui graf complet: "<<endl;
    complet.print(out);
    return out;
}

Graf_complet:: ~Graf_complet(){
    this->nr_muchii=0;
    this->nr_noduri=0;
}
