#include<iostream>
#include "Matrice.h"
using namespace std;

Matrice:: Matrice(){
    this->a=NULL;
}

Matrice::Matrice(int **a){
    if(a!=NULL)
       {
        int dim=getdim(a);
        try{
            this->a=new int*[dim];
            for(int i=0;i<dim;i++)
                this->a[i]=new int[dim];
            }catch(bad_alloc &x){
                cout << "Alocare Nereusita" << endl;
                exit(EXIT_FAILURE);
            }
        for(int i=0;i<dim;i++)
            for(int j=0;j<dim;j++)
                this->a[i][j]=a[i][j];
       }
    else
        throw runtime_error(string("Matricea este VIDA"));

}
Matrice::Matrice(const Matrice &matrice){

    int dim=getdim(matrice.a);
    try{
        this->a=new int*[dim];
        for(int i=0;i<dim;i++)
            this->a[i]=new int[dim];
        }catch(bad_alloc &x){
            cout << "Alocare Nereusita" << endl;
            exit(EXIT_FAILURE);
        }
    for(int i=0;i<dim;i++)
        for(int j=0;j<dim;j++)
            this->a[i][j]=matrice.a[i][j];

}

int** Matrice::getMatrice (){
        return this->a;
}

int Matrice::getdim(int **a) const{
    int i=0;
    while(a[0][i]==0 || a[0][i]==1)
            ++i;
    return i;
}
void Matrice::setMatrice(int **a){
    if(a!=NULL)
       {
        int dim=getdim(a);
        try{
            this->a=new int*[dim];
            for(int i=0;i<dim;i++)
               this->a[i]=new int[dim];
        }catch(bad_alloc &x){
            cout << "Alocare Nereusita" << endl;
            exit(EXIT_FAILURE);
        }
        for(int i=0;i<dim;i++)
            for(int j=0;j<dim;j++)
                this->a[i][j]=a[i][j];
       }
    else
        throw runtime_error(string("Matricea este VIDA"));
}

Matrice& Matrice::operator= (const Matrice &matrice){

    if(this == &matrice)
        return *this;
    int dim=getdim(matrice.a);
    try{
        a=new int*[dim];
        for(int i=0;i<dim;i++)
            a[i]=new int[dim];
        }catch(bad_alloc &x){
            cout << "Alocare Nereusita" << endl;
            exit(EXIT_FAILURE);
        }
    for (int i=0; i<dim; i++)
        for (int j=0; j<dim; j++)
            a[i][j] = matrice.a[i][j];
    return *this;
}

void Matrice::print_mat(ostream& out) const{
    int dim=getdim(a);
    out<<"Matricea este: "<<endl;
    for(int i=0;i<dim;i++)
        {for(int j=0;j<dim;j++)
            out<<a[i][j]<<" ";
            out<<endl;
        }
}

void Matrice::read_mat(istream &in){
    int dim,i,j,m;
    in>>dim;
    in>>m;
    try{
        a=new int*[dim-1];
        for(int i=0;i<dim;i++)
            a[i]=new int[dim-1];
        }catch(bad_alloc &x){
            cout << "Alocare Nereusita" << endl;
            exit(EXIT_FAILURE);
        }
    for (int i=0; i<dim; i++)
        for(int j=0; j<dim; j++)
            a[i][j]=0;
   while(m)
        {
        in>>i>>j;
        a[i][j]=1;
        m--;
        }
}

ostream &operator<<(ostream &out, Matrice &matrice){
    out<<"Afisarea matricii: "<<endl;
    matrice.print_mat(out);
    return out;
}

istream &operator>>(istream &in, Matrice &matrice){
    matrice.read_mat(in);
    return in;
}

Matrice::~Matrice(){
    int dim=getdim(this->a);
    for(int i=0;i<dim;i++)
	{
		delete [] this->a[i];
	}
	delete [] this->a;
}
