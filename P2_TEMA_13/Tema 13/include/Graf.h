#ifndef GRAF_H
#define GRAF_H

using namespace std;

class Graf{
protected:
    int nr_noduri;
public:
    Graf();
    Graf(int nr_noduri);
    Graf(const Graf &graf);
    int getNumberNodes();
    void setNumberNodes(int nr_noduri);
    Graf& operator=(const Graf &graf);
    virtual void print(ostream& out) const =0;
    virtual void read(istream &in)=0;
    friend istream &operator>>(istream &in, Graf &graf);
    friend ostream &operator<<(ostream &out,const Graf &graf);
    virtual ~Graf();
};

#endif // GRAF_H
