#ifndef MATRICE_H
#define MATRICE_H
using namespace std;


class Matrice{
private:
    int **a;
public:
    Matrice();
    Matrice(int **a);
    Matrice(const Matrice &matrice);
    int** getMatrice();
    int getdim(int **a) const;
    void setMatrice(int **a);
    Matrice& operator=(const Matrice &matrice);
    void print_mat(ostream& out) const;
    void read_mat(istream &in);
    friend ostream &operator<<(ostream &out, Matrice &matrice);
    friend istream &operator>>(istream &in, Matrice &matrice);
    virtual ~Matrice();
};

#endif // MATRICE_H
