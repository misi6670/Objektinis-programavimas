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

struct studentas {
    string Vardas;
    string Pavarde;
    int nd[15];
    int n=0;
    int egz;
    float galutinis=0;
};

int main()
{
    vector <studentas> Eil_vect;
    const char separator = ' ';
    const int VardSimb = 15;
    const int PavSimb = 15;
    const int GalutSimb = 16;
    int StudSkai=0;
    cout << "Iveskite studentu skaiciu\n";
    cin >> StudSkai;
    studentas* grupe = new studentas[StudSkai];
    for (int i = 0; i < StudSkai; i++) {
        cout << "\n Iveskite " << i+1 << " studento varda ir pavarde \n";
        cin >> grupe[i].Vardas >> grupe[i].Pavarde;
        cout << "\n Iveskite " << i + 1 << " studento pazymius, suvedus visus pazymius irasykite 0\n";
        int nulis = 1;
        while (nulis != 0) {
            cin >> grupe[i].nd[grupe[i].n];
            grupe[i].galutinis = grupe[i].galutinis + (float)grupe[i].nd[grupe[i].n];
            if (grupe[i].nd[grupe[i].n] == 0) nulis = 0;
            else {
                grupe[i].n++;
                cout << "Ivedete " << grupe[i].n << " pazymi(-ius)" << endl;
            }
        }
        cout << "\n Iveskite " << i + 1 << " studento egzamino rezultata \n";
        cin >> grupe[i].egz;
        grupe[i].galutinis = grupe[i].galutinis / (float) grupe[i].n;
        grupe[i].galutinis = grupe[i].galutinis * 0.4 + grupe[i].egz * 0.6;
    }
    cout << left << setw(VardSimb) << setfill(separator) << "\n Vardas";
    cout << left << setw(PavSimb) << setfill(separator) << "Pavarde";
    cout << left << setw(GalutSimb) << setfill(separator) << "Galutinis (Vid.)" << endl;
    cout << string( VardSimb + PavSimb + GalutSimb, '-') << endl;
    for (int i = 0; i < StudSkai; i++) {
        cout << left << setw(VardSimb) << setfill(separator) << grupe[i].Vardas;
        cout << left << setw(PavSimb) << setfill(separator) << grupe[i].Pavarde;
        cout << left << setw(GalutSimb) << setfill(separator) << fixed << setprecision(2) << grupe[i].galutinis << endl;
    }
    return(0);
}

