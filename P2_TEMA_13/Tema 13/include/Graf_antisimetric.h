#ifndef GRAF_ANTISIMETRIC_H
#define GRAF_ANTISIMETRIC_H
#include "Matrice.h"
#include "Graf.h"
using namespace std;


class Graf_antisimetric:  public virtual Graf{
protected:
    Matrice M;
public:
    Graf_antisimetric();
    Graf_antisimetric(int nr_noduri,int **a);
    Graf_antisimetric(const Graf_antisimetric &antisim);
    int grafeantisimetric();
    void afisare_arce();
    Matrice getobiectmatrice();
    Graf_antisimetric& operator=(const Graf_antisimetric &antisim);
    void print(ostream &out) const;
    void read(istream &in);
    friend iostream &operator>>(iostream &in, Graf_antisimetric &antisimetric);
    friend ostream &operator<<(ostream &out, Graf_antisimetric &antisimetric);
    virtual ~Graf_antisimetric();
};

#endif // GRAF_ANTISIMETRIC_H
