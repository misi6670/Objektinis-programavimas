// v0.1_masyvas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>


using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;

struct duomuo {
    string Vardas;
    string Pavarde;
    int nd[15];
    int n;
    int egz;
    float galutinis=0;
};

int main()
{
    duomuo Eil; duomuo Eil_masyvas[20];
    vector <duomuo> Eil_vect;
    cout << "Iveskite mokiniu skaiciu (iki 20)\n";
    int MokSkai;
    cin >> MokSkai;
    for (int i = 0; i < MokSkai; i++) {
        cout << "\n Iveskite studento varda ir pavarde \n";
        cin >> Eil_masyvas[i].Vardas >> Eil_masyvas[i].Pavarde;
        cout << "\n Iveskite studento egzamino rezultata \n";
        cin >> Eil_masyvas[i].egz;
        cout << "\n Iveskite kiek pazymiu gavo studentas (iki 15)?\n";
        cin >> Eil_masyvas[i].n;
        cout << "\n Iveskite " << Eil_masyvas[i].n << " pazymi(-ius):\n";
        for (int ii = 0; ii < Eil_masyvas[i].n; ii++) {
            cout << "liko ivesti " << Eil_masyvas[i].n - ii << " pazymi(-ius)\n";
            cin >> Eil_masyvas[i].nd[ii];
            Eil_masyvas[i].galutinis = Eil_masyvas[i].galutinis + (float) Eil_masyvas[i].nd[ii];
        }
        Eil_masyvas[i].galutinis = Eil_masyvas[i].galutinis / (float) Eil_masyvas[i].n;
        Eil_masyvas[i].galutinis = Eil_masyvas[i].galutinis * 0.4 + Eil_masyvas[i].egz * 0.6;
    }

    for (int i = 0; i < MokSkai; i++) {
        cout << "\n Ivesta:" << Eil_masyvas[i].Vardas << " " << Eil_masyvas[i].Pavarde << " " << Eil_masyvas[i].galutinis << endl; // suapvalinti rezultata
    }
    return(0);
}

