// v0.1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>

using std::cout;
using std::cin;
using std::string;
using std::vector;

struct duomuo {
    string Vardas;
    string Pavarde;
    int nd[15];
    int egz;
    float galutinis=0;
};

int main()
{
    duomuo Eil; duomuo Eil_masyvas[10];
    vector <duomuo> Eil_vect;
    cout << "Iveskite studento varda, pavarde, jo egzamino rezultata ir namu darbu rezultatus\n";
    cin >> Eil.Vardas >> Eil.Pavarde >> Eil.egz;
    for (int i = 0; i < 5; i++) {
        cin >> Eil.nd[i];
        Eil.galutinis = Eil.galutinis + Eil.nd[i];
    }

    float vid = (float)Eil.galutinis / 5.0;
    Eil.galutinis = vid * 0.4 + Eil.egz * 0.6;
    cout << "Ivesta:" << Eil.Vardas << " " << Eil.Pavarde << " " << Eil.galutinis << std::endl;


    char a;
    cin >> a;
}
    

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
