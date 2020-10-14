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

        /*
        failø kûrimà;
        duomenø nuskaitymà ið failø;
        studentø rûðiàvimà á dvi grupes/kategorijas;
        surûðiuotø studentø iðvedimà á du naujus failus.
        */
        if (remove("studentai1000.txt") == 0) remove("studentai1000.txt");
        if (remove("studentai10000.txt") == 0) remove("studentai10000.txt");
        if (remove("studentai100000.txt") == 0) remove("studentai100000.txt");
        if (remove("studentai1000000.txt") == 0) remove("studentai1000000.txt");
        if (remove("studentai10000000.txt") == 0) remove("studentai10000000.txt");

        auto start = std::chrono::high_resolution_clock::now(); auto st = start;
        generavimas("studentai1000.txt", 1000, grupe);
        std::chrono::duration<double> diff = std::chrono::high_resolution_clock::now() - start;
        std::cout << "Failo kurimas uztruko: " << diff.count() << " s\n";

        start = std::chrono::high_resolution_clock::now(); st = start;
        nuskaitymas("studentai1000", grupe, StudSkai, VidArMed);
        diff = std::chrono::high_resolution_clock::now() - start;
        std::cout << "Failo kurimas uztruko: " << diff.count() << " s\n";
        std::cout << "Duomenu nuskaitymas is failo uztruko: " << diff.count() << " s\n";
        
        /*
        generavimas("studentai1000.txt", 1000);
        generavimas("studentai10000.txt", 10000);
        generavimas("studentai100000.txt", 100000);
        generavimas("studentai1000000.txt", 1000000);
        generavimas("studentai10000000.txt", 10000000);
        */
    }
    else {
        cout << "Noredami duomenis nuskaityti is failo iveskite '1'; \n";
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
        grupe.clear();
        grupe1.clear();
        grupe2.clear();  
    }
    return(0);
}
