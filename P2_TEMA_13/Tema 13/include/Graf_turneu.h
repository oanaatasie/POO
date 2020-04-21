#ifndef GRAF_TURNEU_H
#define GRAF_TURNEU_H
#include "Graf_complet.h"
#include "Graf_antisimetric.h"
using namespace std;

class Graf_turneu: public Graf_complet,public Graf_antisimetric{
public:
    Graf_turneu();
    Graf_turneu(int nr_noduri,int nr_muchii,int **a);
    Graf_turneu(const Graf_turneu &turneu);
    int grafeturneu();
    Graf_turneu& operator=(const Graf_turneu &turneu);
    void print(ostream &out) const;
    void read(istream &in);
    friend istream &operator>>(istream &in, Graf_turneu &turneu);
    friend ostream &operator<<(ostream &out, const Graf_turneu &turneu);
    virtual ~Graf_turneu();

};

#endif // GRAF_TURNEU_H
