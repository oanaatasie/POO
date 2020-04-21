#ifndef GRAF_COMPLET_H
#define GRAF_COMPLET_H
#include "Graf.h"
using namespace std;

class Graf_complet: public virtual Graf{
protected:
    int nr_muchii;
public:
    Graf_complet();
    Graf_complet(int nr_noduri,int nr_muchii);
    Graf_complet(const Graf_complet &complet);
    int grafecomplet();
    int getMuchii();
    void setMuchii(int nr_muchii);
    Graf_complet& operator=(const Graf_complet &complet);
    void print(ostream &out) const;
    void read(istream &in);
    friend ostream &operator<<(ostream &out,const Graf_complet &complet);
    friend istream &operator>>(istream &in,  Graf_complet &complet);
    virtual ~Graf_complet();
};

#endif // GRAF_COMPLET_H
