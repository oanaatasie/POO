#include<iostream>
#include "Graf_antisimetric.h"
using namespace std;


Graf_antisimetric::Graf_antisimetric():Graf(), M(){ }

Graf_antisimetric::Graf_antisimetric(int nr_noduri, int **a):Graf(nr_noduri), M(a){ }

Graf_antisimetric::Graf_antisimetric(const Graf_antisimetric &antisim): Graf(antisim){
    this->M = antisim.M;
}

int Graf_antisimetric::grafeantisimetric(){
    int i,j,ok=1,**a;
    try{
        a=new int*[this->nr_noduri];
        for(int i=0;i<this->nr_noduri;i++)
           a[i]=new int[this->nr_noduri];
        }catch(bad_alloc &x){
            cout << "Alocare Nereusita" << endl;
            exit(EXIT_FAILURE);
        }
    a=M.getMatrice();
    for(i=0;i<this->nr_noduri;i++)
        for(j=0;j<this->nr_noduri;j++)
            if(i!=j && a[i][j]==1 && a[j][i]==1)
                {ok=0;
                break;
                }
    return ok;
}

Graf_antisimetric& Graf_antisimetric:: operator=(const Graf_antisimetric &antisim){
    if(this == &antisim)
        return *this;
    M=antisim.M;
    nr_noduri=antisim.nr_noduri;
    return *this;
}

void Graf_antisimetric::afisare_arce(){
    int i,j,**a;
    try{
        a=new int*[this->nr_noduri];
        for(int i=0;i<this->nr_noduri;i++)
           a[i]=new int[this->nr_noduri];
        }catch(bad_alloc &x){
            cout << "Alocare Nereusita" << endl;
            exit(EXIT_FAILURE);
        }
    a=M.getMatrice();
    cout<<"Arcele grafului sunt: "<<endl;
    for(i=0;i<this->nr_noduri;i++)
        for(j=0;j<this->nr_noduri;j++)
            if(a[i][j]==1)
                cout<<i<<" "<<j<<endl;
}
Matrice Graf_antisimetric::getobiectmatrice(){
    return this->M;
}
void Graf_antisimetric::print(ostream &out) const{
    Graf::print(out);
    out<<endl;
    M.print_mat(out);
}
void Graf_antisimetric::read(istream &in){
    Graf::read(in);
    M.read_mat(in);
}
iostream &operator>>(iostream &in, Graf_antisimetric &antisimetric){
    antisimetric.read(in);
    return in;
}

ostream &operator<<(ostream &out, Graf_antisimetric &antisimetric){
    out<<"Afisarea grafului antisimetric: "<<endl;
    antisimetric.print(out);
    return out;
}

Graf_antisimetric::~Graf_antisimetric()
{   this->nr_noduri=0;
    delete &this->M;
}
