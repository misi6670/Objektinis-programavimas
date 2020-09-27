// v0.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stdlib.h> 

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
using std::sort;

struct studentas {
    string Vardas = "";
    string Pavarde = "";
    vector <int> nd;
    int n = 0;
    int egz = 0;
    float galutinis = 0;
    float vid = 0;
};

int main()
{
    vector <studentas> grupe;
    const char separator = ' ';
    const int VardSimb = 15;
    const int PavSimb = 15;
    const int GalutSimb = 16;
    int StudSkai = 0;
    int VidArMed = 0;
    int AutoGen = 0;

    cout << "\n Iveskite studentu skaiciu\n";
    cin >> StudSkai;
    grupe.reserve(StudSkai);
    for (int i = 0; i < StudSkai; i++) {
        studentas stud;
        cout << "\n Iveskite " << i + 1 << " studento varda ir pavarde \n";
        cin >> stud.Vardas >> stud.Pavarde;
        cout << "\n Iveskite " << i + 1 << " studento pazymius, suvedus visus pazymius irasykite 0\n";
        int nulis = 1;
        while (nulis != 0) {
            int paz;
            cin >> paz;
            stud.vid = stud.vid + (float)paz;
            if (paz == 0) nulis = 0;
            else {
                stud.nd.push_back(paz);
                stud.n++;
                stud.nd.reserve(stud.n);
                cout << "Ivedete " << stud.n << " pazymi(-ius)" << endl;
            }
        }
        cout << "\n Iveskite " << i + 1 << " studento egzamino rezultata \n";
        cin >> stud.egz;
       stud.galutinis = stud.vid / (float)stud.n;
        stud.galutinis = stud.galutinis * 0.4 + (float)stud.egz * 0.6;
        grupe.push_back(stud);
        stud.nd.clear();
    }
    cout << endl;
    for (auto& tt : grupe) {
        cout << tt.Vardas << " " << tt.Pavarde << endl;
        for (auto& yy : tt.nd){
            cout << yy << " ";
        }
        cout << endl;
        cout << "egzaminas: " << tt.egz << endl;
        cout << "galutinis: " << tt.galutinis << endl;
    }
    /*
    cout << "Galutinio balo skaiciavimui naudoti vidurki ar mediana? \n";
    cout << "Noredami naudoti mediana, iveskite '1'; \n";
    cout << "Noredami naudoti vidurki, iveskite '0' ar koki kita SKAICIU; \n";
    cin >> VidArMed;
    cout << "\n Jei norite, kad studento namu darbu ir egzamino balai butu generuojami automatiskai, iveskite '1'; \n";
    cout << "Kitu atveju iveskite '0' arba bet koki kita SKAICIU; \n";
    cin >> AutoGen;
    cout << "\n Iveskite studentu skaiciu\n";
    cin >> StudSkai;
    studentas* grupe = new studentas[StudSkai];
    for (int i = 0; i < StudSkai; i++) {
        cout << "\n Iveskite " << i + 1 << " studento varda ir pavarde \n";
        cin >> grupe[i].Vardas >> grupe[i].Pavarde;
        if (AutoGen == 1) {
            cout << "\n" << i + 1 << " studento atsitiktinai sugeneruoti pazymiai: \n";
            grupe[i].n = rand() % 20 + 1;
            for (int j = 0; j < grupe[i].n; j++) {
                grupe[i].nd[j] = rand() % 10 + 1;
                cout << grupe[i].nd[j] << " ";
                grupe[i].vid = grupe[i].vid + (float)grupe[i].nd[j];
            }
            cout << endl;
            grupe[i].egz = rand() % 10 + 1;
            cout << "\n" << i + 1 << " studento atsitiktinai sugeneruotas egzamino balas: " << grupe[i].egz << endl;
        }
        else {
            cout << "\n Iveskite " << i + 1 << " studento pazymius, suvedus visus pazymius irasykite 0\n";
            int nulis = 1;
            while (nulis != 0) {
                cin >> grupe[i].nd[grupe[i].n];
                grupe[i].vid = grupe[i].vid + (float)grupe[i].nd[grupe[i].n];
                if (grupe[i].nd[grupe[i].n] == 0) nulis = 0;
                else {
                    grupe[i].n++;
                    cout << "Ivedete " << grupe[i].n << " pazymi(-ius)" << endl;
                }
            }
            cout << "\n Iveskite " << i + 1 << " studento egzamino rezultata \n";
            cin >> grupe[i].egz;
        }
        if (VidArMed == 1) {
            sort(grupe[i].nd, grupe[i].nd + grupe[i].n);
            if (grupe[i].n % 2 != 0) grupe[i].galutinis = (float)grupe[i].nd[grupe[i].n / 2];
            else grupe[i].galutinis = ((float)grupe[i].nd[(grupe[i].n - 1) / 2] + (float)grupe[i].nd[grupe[i].n / 2]) / 2.0;
        }
        else grupe[i].galutinis = grupe[i].vid / (float)grupe[i].n;
        grupe[i].galutinis = grupe[i].galutinis * 0.4 + (float)grupe[i].egz * 0.6;
    }
    cout << left << setw(VardSimb) << setfill(separator) << "\n Vardas";
    cout << left << setw(PavSimb) << setfill(separator) << "Pavarde";
    if (VidArMed == 1) cout << left << setw(GalutSimb) << setfill(separator) << "Galutinis (Med.)" << endl;
    else cout << left << setw(GalutSimb) << setfill(separator) << "Galutinis (Vid.)" << endl;
    cout << string(VardSimb + PavSimb + GalutSimb, '-') << endl;
    for (int i = 0; i < StudSkai; i++) {
        cout << left << setw(VardSimb) << setfill(separator) << grupe[i].Vardas;
        cout << left << setw(PavSimb) << setfill(separator) << grupe[i].Pavarde;
        cout << left << setw(GalutSimb) << setfill(separator) << fixed << setprecision(2) << grupe[i].galutinis << endl;
    }
    */
    grupe.clear();
    return(0);
}
