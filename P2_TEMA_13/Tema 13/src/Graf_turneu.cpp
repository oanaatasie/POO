#include<iostream>
#include "Graf_turneu.h"

Graf_turneu::Graf_turneu(): Graf_complet(), Graf_antisimetric(){ }

Graf_turneu::Graf_turneu(int nr_noduri,int nr_muchii,int **a): Graf_complet(nr_noduri,nr_muchii), Graf_antisimetric(nr_noduri,a){ }

Graf_turneu::Graf_turneu(const Graf_turneu &turneu):Graf_complet(turneu),Graf_antisimetric(turneu){ }

int Graf_turneu::grafeturneu(){
    if (grafeantisimetric() && grafecomplet())
        return 1;
    else
        return 0;
}

Graf_turneu& Graf_turneu::operator=(const Graf_turneu &turneu){
    if(this == &turneu)
        return *this;
    nr_muchii=turneu.nr_muchii;
    nr_noduri=turneu.nr_noduri;
    M=turneu.M;
    return *this;
}

void Graf_turneu::print(ostream &out) const{
    out<<"Numarul de muchii: "<<nr_muchii<<endl;
    Graf_antisimetric::print(out);
}

void Graf_turneu::read(istream &in){
    cout<<"Numarul de muchii este: ";
    in>>nr_muchii;
    Graf_antisimetric::read(in);
}

istream &operator>>(istream &in, Graf_turneu &turneu){
    turneu.read(in);
    return in;
}

ostream &operator<<(ostream &out, const Graf_turneu &turneu){
    out<<"Afisarea grafului turneu: "<<endl;
    turneu.print(out);
    return out;
}

Graf_turneu::~Graf_turneu()
{
    this->nr_muchii=0;
    delete &this->M;
}
