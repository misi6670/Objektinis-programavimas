// v0.4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "header.h"

int main()
{
    vector <studentas> grupe;
    int StudSkai = 0;
    int VidArMed = 0;
    int AutoGen = 0;
    int Ivedimas = 0;

    cout << "Noredami duomenis nuskaityti is failo iveskite '1'; \n";
    cout << "Kitu atveju iveskite '0' ar bet koki kita SKAICIU \n";
    cin >> Ivedimas;
    skaitymoKlaidos(Ivedimas);

    cout << "\n Galutinio balo skaiciavimui naudoti vidurki ar mediana? \n";
    cout << "Noredami naudoti mediana, iveskite '1'; \n";
    cout << "Noredami naudoti vidurki, iveskite '0' ar koki kita SKAICIU; \n";
    cin >> VidArMed;
    skaitymoKlaidos(VidArMed);

    if (Ivedimas == 1) nuskaitymas(grupe, StudSkai, VidArMed);
    else {
        cout << "\n Jei norite, kad studento namu darbu ir egzamino balai butu generuojami automatiskai, iveskite '1'; \n";
        cout << "Kitu atveju iveskite '0' arba bet koki kita SKAICIU; \n";
        cin >> AutoGen;
        skaitymoKlaidos(AutoGen);

        cout << "\n Iveskite studentu skaiciu\n";
        cin >> StudSkai;
        skaitymoKlaidosStud(StudSkai);

        grupe.reserve(StudSkai);
        ivedimas(grupe, StudSkai, VidArMed, AutoGen);
    }
    isvedimas(grupe, VidArMed);
    vector <studentas> grupe1;
    vector <studentas> grupe2;
    padalinimas(grupe, grupe1, grupe2);
    if (remove("neislaike.txt") == 0) remove("neislaike.txt");
    if (remove("islaike.txt") == 0) remove("islaike.txt");
    if (!grupe1.empty()) irasymas("neislaike.txt", grupe1, VidArMed);
    if (!grupe2.empty()) irasymas("islaike.txt", grupe2, VidArMed);
    grupe.clear();
    grupe1.clear();
    grupe2.clear();
    return(0);
}
