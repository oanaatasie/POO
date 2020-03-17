//TEMA 13

#include <iostream>
#include<cmath>
using namespace std;
class Polinom
{
private:
    double *coefs;
    int nrcoefs;
public:
    //Constructorul default, care seteaza gradul la 0(polinomul nul)
    Polinom()
    {
        coefs = NULL;
        nrcoefs = 0;
    }
    // Constrctorul cu parametrii
    Polinom(double *pol, int grade)
    {
        if(coefs!=NULL)
        {
            nrcoefs=grade+1;
            coefs=new double[nrcoefs];
            for(int i=0; i<nrcoefs; i++)
                coefs[i]=pol[i];
        }
        else
            cout<<"Vectorul de coeficienti este VID";
    }

    //  Constrctor de copiere
    Polinom( const Polinom &pol)
    {
        nrcoefs=pol.nrcoefs;
        coefs=new double[nrcoefs];
        for(int i=0; i<nrcoefs; i++)
            coefs[i]=pol.coefs[i];
    }
    // get-uri si set-uri
    double *getCoefs()
    {
        return coefs;
    }
    int getNumberOfCoefs()
    {
        return nrcoefs;
    }
    void setCoefs(double *coefs, int nrcoefs)
    {
        if (coefs != NULL)
        {
            this->nrcoefs = nrcoefs;
            this->coefs = new double[this->nrcoefs];
            for (int i = 0; i < this->nrcoefs; i++)
            {
                this->coefs[i] = coefs[i];
            }
        }
        else
             cout<<"Vectorul de coeficienti este VID";
    }

    //metoda publica pentru calculul valorii unui polinom intr-un punct
    double getvalue(double x)
    {
        if(x!=0)
        {
            double value = 0;
            for(int i=0; i<nrcoefs; i++)
                value+=coefs[i]*pow(x,i);
            return value;

        }
        return 0;

    }

    //supraincarcarea operatorului +
    Polinom operator+( const Polinom &pol)
    {
        int maxcoefs;
        if(nrcoefs>pol.nrcoefs)
            maxcoefs=nrcoefs;
        else
            maxcoefs=pol.nrcoefs;
        double *results=new double[maxcoefs];
        for(int i=0; i<nrcoefs; i++)
            results[i]=coefs[i];
        for(int i=0; i<pol.nrcoefs; i++)
            results[i]+=pol.coefs[i];
        int lastzero=maxcoefs;
        while(results[lastzero-1]==0) // daca prin adunare se reduc coeficientii se vor elimina zerorile de la finalul polinomului
            lastzero--;
        if(lastzero!=maxcoefs)
        {
            double *newresult=new double[lastzero];
            for(int i=0; i<lastzero; i++)
                newresult[i]=results[i];
            results=newresult;
            maxcoefs=lastzero;
        }
        Polinom result(results, maxcoefs-1);
        return result;

    }

    //supraincarcarea operatorului -
    Polinom operator-(const Polinom &pol)
    {
        int maxcoefs;
        if(nrcoefs>pol.nrcoefs)
            maxcoefs=nrcoefs;
        else
            maxcoefs=pol.nrcoefs;
        double *results=new double[maxcoefs];
        for(int i=0; i<nrcoefs; i++)
            results[i]=coefs[i];
        for(int i=0; i<pol.nrcoefs; i++)
                if(i>=nrcoefs)
                    results[i]=0-pol.coefs[i];
                else
                    results[i]-=pol.coefs[i];
        int lastzero=maxcoefs;
        while(results[lastzero-1]==0) // daca prin scadere se reduc coeficientii se vor elimina zerorile de la finalul polinomului
            lastzero--;

        if(lastzero!=maxcoefs && lastzero>0)
        {
            double *newresult=new double[lastzero];
            for(int i=0; i<lastzero; i++)
                newresult[i]=results[i];
            results=newresult;
            maxcoefs=lastzero;
        }
        Polinom result(results, maxcoefs-1);
        return result;

    }

    //supraincarcarea operatorului *
    Polinom operator*(const Polinom &pol)
    {
        int maxcoefs=(nrcoefs-1)+(pol.nrcoefs-1)+1; //gradul pol produs este egal cu suma gradelor polinoamelor;
        double *results=new double[maxcoefs];
        for(int i=0; i<maxcoefs; i++)
            results[i]=0;
        for(int i=0; i<nrcoefs; i++)
            for(int j=0; j<pol.nrcoefs; j++)
                results[i+j]+=coefs[i]*pol.coefs[j];
        Polinom result(results, maxcoefs-1);
        return result;
    }

    //supraincarcarea operatorului de afisare
    friend ostream &operator<<(ostream &out, const Polinom &pol)
    {
        string output("");
        for(int i=0; i<pol.nrcoefs; i++)
        {
            out<<pol.coefs[i]<< " * x^" << i;
            if (i != pol.nrcoefs - 1)
                out << " + ";
        }
        return out;
    }

    //supraincarcarea operatorului de citire
    friend istream &operator>>(istream &in, Polinom &pol)
    {
        int nr;
        in>>nr;
        pol.nrcoefs=nr;
        double *vect=new double[nr];
        for(int i=0; i<nr; i++)
        {
            in>>vect[i];
        }
        pol.coefs=vect;
        return in;
    }
    //destructor
    ~Polinom()
    {
        nrcoefs=0;
        if(coefs!=NULL)
            delete[] coefs;
    }
};
int main()
{
    double point;
    cin>>point;
    Polinom poly1;
    cin>>poly1;
    cout << poly1 << endl;
    Polinom poly2;

    cin>>poly2;
    cout << poly2 << endl;
    // afisarea valorii unui polinom intr-un punct
    cout<<"Valoarea in "<<point<<" este "<<poly1.getvalue(point) << endl;
    // suma a 2 polinoame
    cout << "Poly1 + Poly2 = " << endl;
    cout << poly1 + poly2 << endl;
    // diferenta a doua polinoame
    cout << "Poly1 - Poly2 = " << endl;
    cout << poly1 - poly2 << endl;
    // inmultirea a 2 polinoame
    cout << "Poly1 * Poly2 = " << endl;
    cout << poly1 * poly2 << endl;

    return 0;
}
