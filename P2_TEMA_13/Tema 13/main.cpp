#include <iostream>
#include<cstring>
#include "Matrice.h"
#include "Graf.h"
#include "Graf_complet.h"
#include "Graf_antisimetric.h"
#include "Graf_turneu.h"
using namespace std;


int main()
{
    try{
        Matrice X;
        cout<<"Citirea matricei: "<<endl;
        cin>>X;
        cout<<X<<endl;
        cout<<"Citirea grafului complet: "<<endl;
        Graf_complet Y,Z;
        cin>>Y;
        cout<<Y<<endl;
        cout<<"Este sau nu graful complet: "<<Y.grafecomplet()<<endl;
        Z=Y;
        cout<<Y<<endl;
        cout<<"Citirea grafului antisimetric: "<<endl;
        Graf_antisimetric A;
        cin>>A;
        cout<<A<<endl;
        A.afisare_arce();
        cout<<endl;
        cout<<"Este sau nu graful antisimetric: "<<A.grafeantisimetric()<<endl;
        cout<<"Citirea grafului turneu: "<<endl;
        Graf_turneu C,D;
        cin>>C;
        cout<<C<<endl;
        D=C;
        cout<<D<<endl;
        cout<<"Este sau nu graful turneu: "<<D.grafeturneu()<<endl;
        D.afisare_arce();

    }
    catch (runtime_error &e)
    {
        cout << e.what() << endl;
    }
    return 0;
}
