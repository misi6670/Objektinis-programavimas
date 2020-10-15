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
    int Testavimas = 0;
    string txtname;

    cout << "Noredami testuoti programa iveskite '1'; \n";
    cout << "Kitu atveju iveskite '0' ar bet koki kita SKAICIU \n";
    cin >> Testavimas;
    skaitymoKlaidos(Testavimas);

    cout << "\n Galutinio balo skaiciavimui naudoti vidurki ar mediana? \n";
    cout << "Noredami naudoti mediana, iveskite '1'; \n";
    cout << "Noredami naudoti vidurki, iveskite '0' ar koki kita SKAICIU; \n";
    cin >> VidArMed;
    skaitymoKlaidos(VidArMed);

    if (Testavimas == 1) {
        if (remove("studentai1000.txt") == 0) remove("studentai1000.txt");
        if (remove("studentai10000.txt") == 0) remove("studentai10000.txt");
        if (remove("studentai100000.txt") == 0) remove("studentai100000.txt");
        if (remove("studentai1000000.txt") == 0) remove("studentai1000000.txt");
        if (remove("studentai10000000.txt") == 0) remove("studentai10000000.txt");

        test("studentai1000", 1000, StudSkai, VidArMed);
        test("studentai10000", 10000, StudSkai, VidArMed);
        test("studentai100000", 100000, StudSkai, VidArMed);
        test("studentai1000000", 1000000, StudSkai, VidArMed);
        test("studentai10000000", 10000000, StudSkai, VidArMed);
    }
    else {
        cout << "\n Noredami duomenis nuskaityti is failo iveskite '1'; \n";
        cout << "Kitu atveju iveskite '0' ar bet koki kita SKAICIU \n";
        cin >> Ivedimas;
        skaitymoKlaidos(Ivedimas);

        if (Ivedimas == 1) {

            cout << "\n Iveskite norimo nuskaityti tekstinio failo pavadinima ('.txt' vesti nereikia)" << endl;
            cin >> txtname;
            nuskaitymas(txtname, grupe, StudSkai, VidArMed);
        }
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
        grupe1.clear();
        grupe2.clear();
        grupe.clear();
    }
    return(0);
}
