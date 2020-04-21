#include<iostream>
#include "Graf.h"
using namespace std;


Graf:: Graf(){
    this->nr_noduri=0;
}
Graf:: Graf(int nr_noduri){
    this->nr_noduri=nr_noduri;
}

Graf:: Graf(const Graf &graf){
    this->nr_noduri=graf.nr_noduri;
}

int Graf:: getNumberNodes(){
    return this->nr_noduri;
}

void Graf:: setNumberNodes(int nr_noduri){
    this->nr_noduri=nr_noduri;
}
Graf& Graf::operator=(const Graf &graf){
    if(this == &graf)
        return *this;
    nr_noduri=graf.nr_noduri;
    return *this;
}

void Graf:: print(ostream &out) const{
    out<<"Numarul de noduri ale grafului este: ";
    out<<nr_noduri;
}
void Graf::read(istream &in){
    cout<<"Citeste numarul de noduri: ";
    in>>nr_noduri;
}
istream &operator>>(istream &in, Graf &graf){
    graf.read(in);
    return in;
}

ostream &operator<<(ostream &out,const Graf &graf){
    out<<"Afisarea grafului: "<<endl;
    graf.print(out);
    return out;
}

Graf:: ~Graf(){
     this->nr_noduri=0;
}

