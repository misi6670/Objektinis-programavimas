// v0.1_masyvas.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


using std::cout;
using std::cin;
using std::string;
using std::vector;
using std::endl;
using std::left;
using std::setw;
using std::setfill;
using std::fixed;
using std::setprecision;

struct duomuo {
    string Vardas;
    string Pavarde;
    int nd[15];
    int n=0;
    int egz;
    float galutinis=0;
};

int main()
{
    duomuo Eil; duomuo Eil_masyvas[20];
    vector <duomuo> Eil_vect;
    const char separator = ' ';
    const int VardSimb = 15;
    const int PavSimb = 15;
    const int GalutSimb = 16;
    cout << "Iveskite mokiniu skaiciu (iki 20)\n";
    int MokSkai;
    cin >> MokSkai;
    for (int i = 0; i < MokSkai; i++) {
        cout << "\n Iveskite studento varda ir pavarde \n";
        cin >> Eil_masyvas[i].Vardas >> Eil_masyvas[i].Pavarde;
        cout << "\n Iveskite studento pazymius (iki 15), suvedus visus pazymius irasykite 0\n";
        int nulis = 1;
            while (nulis != 0) {
                cin >> Eil_masyvas[i].nd[Eil_masyvas[i].n];
                Eil_masyvas[i].galutinis = Eil_masyvas[i].galutinis + (float)Eil_masyvas[i].nd[Eil_masyvas[i].n];
                if (Eil_masyvas[i].nd[Eil_masyvas[i].n] == 0) nulis = 0;
                else Eil_masyvas[i].n++;
            }
        cout << "\n Iveskite studento egzamino rezultata \n";
        cin >> Eil_masyvas[i].egz;
        Eil_masyvas[i].galutinis = Eil_masyvas[i].galutinis / (float) Eil_masyvas[i].n;
        Eil_masyvas[i].galutinis = Eil_masyvas[i].galutinis * 0.4 + Eil_masyvas[i].egz * 0.6;
    }

    cout << left << setw(VardSimb) << setfill(separator) << "Vardas";
    cout << left << setw(PavSimb) << setfill(separator) << "Pavarde";
    cout << left << setw(GalutSimb) << setfill(separator) << "Galutinis (Vid.)" << endl;
    cout << string( VardSimb + PavSimb + GalutSimb, '-') << endl;
    for (int i = 0; i < MokSkai; i++) {
        cout << left << setw(VardSimb) << setfill(separator) << Eil_masyvas[i].Vardas;
        cout << left << setw(PavSimb) << setfill(separator) << Eil_masyvas[i].Pavarde;
        cout << left << setw(GalutSimb) << setfill(separator) << fixed << setprecision(2) << Eil_masyvas[i].galutinis << endl;
    }
    return(0);
}

