#include "header.h"

void nuskaitymas(string txtname, vector<studentas>& grupe, int& StudSkai, int VidArMed)
{
    ifstream f;
    string title;
    char delimeter(' ');
    int NamuDarbuSk;

    f.open(txtname + ".txt", ios::in);
    skaitymoKlaidosFailas(f, txtname);
    getline(f, title, '\n');
    NamuDarbuSk = count(title.begin(), title.end(), 'N');
    while (!f.eof()) {
        if (f.fail()) {}
        StudSkai++;
        grupe.reserve(StudSkai);
        studentas stud;
        stud.n = NamuDarbuSk;
        stud.nd.reserve(stud.n);
        getline(f, stud.Vardas, delimeter);
        char a = ' ';
        while (a == ' ') f.get(a);
        getline(f, stud.Pavarde, delimeter);
        stud.Pavarde = a + stud.Pavarde;
        for (int i = 0; i < stud.n; i++) {
            int paz;
            f >> paz;
            stud.vid = stud.vid + (float)paz;
            stud.nd.push_back(paz);
        }
        f >> stud.egz;
        string temp;
        getline(f, temp, '\n');
        if (VidArMed == 1) mediana(stud);
        else stud.galutinis = stud.vid / (float)stud.n;
        stud.galutinis = stud.galutinis * 0.4 + (float)stud.egz * 0.6;
        grupe.push_back(stud);
        stud.nd.clear();
    }
    f.close();
}

void mediana(studentas& stud)
{
    sort(stud.nd.begin(), stud.nd.end());
    if (stud.n % 2 != 0) stud.galutinis = (float)stud.nd.at(stud.n / 2);
    else {
        int med;
        med = stud.nd.at((stud.n - 1) / 2) + stud.nd.at(stud.n / 2);
        stud.galutinis = (float)med / 2.0;
    }
}

void ivedimas(vector<studentas>& grupe, int StudSkai, int VidArMed, int AutoGen)
{
    for (int i = 0; i < StudSkai; i++) {
        studentas stud;

        cout << "\n Iveskite " << i + 1 << " studento varda ir pavarde \n";
        cin >> stud.Vardas >> stud.Pavarde;

        if (AutoGen == 1) autogen(stud, i);
        else pazymiai(stud, i);
        if (VidArMed == 1) mediana(stud);
        else stud.galutinis = stud.vid / (float)stud.n;
        stud.galutinis = stud.galutinis * 0.4 + (float)stud.egz * 0.6;
        grupe.push_back(stud);
        stud.nd.clear();
    }
}

void autogen(studentas& stud, int i)
{
    std::random_device rd;
    std::mt19937::result_type reiksme = rd() ^ (
        (std::mt19937::result_type)
        std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::system_clock::now().time_since_epoch()
            ).count() +
        (std::mt19937::result_type)
        std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::high_resolution_clock::now().time_since_epoch()
            ).count());

    std::mt19937 gen(reiksme);
    std::mt19937::result_type n;

    cout << "\n" << i + 1 << " studento atsitiktinai sugeneruoti pazymiai: \n";
    while ((n = gen()) > std::mt19937::max() - (std::mt19937::max() - 19) % 20) {}
    stud.n = n % 20 + 1;
    stud.nd.reserve(stud.n);
    for (int j = 0; j < stud.n; j++) {
        int random;
        while ((n = gen()) > std::mt19937::max() - (std::mt19937::max() - 9) % 10) {}
        random = n % 10 + 1;
        cout << random << " ";
        stud.vid = stud.vid + (float)random;
        stud.nd.push_back(random);
    }
    cout << endl;
    while ((n = gen()) > std::mt19937::max() - (std::mt19937::max() - 9) % 10) {}
    stud.egz = n % 10 + 1;
    cout << "\n" << i + 1 << " studento atsitiktinai sugeneruotas egzamino balas: " << stud.egz << endl;
}

void pazymiai(studentas& stud, int i)
{
    cout << "\n Iveskite " << i + 1 << " studento pazymius, suvedus visus pazymius irasykite 0\n";
    int nulis = 1;
    while (nulis != 0) {
        int paz;
        cin >> paz;
        skaitymoKlaidosPaz(paz, stud.n);
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
    skaitymoKlaidosPaz(stud.egz, -1);
}

void isvedimas(vector<studentas> grupe, int VidArMed)
{
    const char separator = ' ';
    const int VardSimb = 15;
    const int PavSimb = 15;
    const int GalutSimb = 16;

    sort(grupe.begin(), grupe.end(), compareTwoStudents);
    cout << endl;
    cout << left << setw(VardSimb) << setfill(separator) << "Vardas";
    cout << left << setw(PavSimb) << setfill(separator) << "Pavarde";
    if (VidArMed == 1) cout << left << setw(GalutSimb) << setfill(separator) << "Galutinis (Med.)" << endl;
    else cout << left << setw(GalutSimb) << setfill(separator) << "Galutinis (Vid.)" << endl;
    cout << string(VardSimb + PavSimb + GalutSimb, '-') << endl;
    for (auto& tt : grupe) {
        cout << left << setw(VardSimb) << setfill(separator) << tt.Vardas;
        cout << left << setw(PavSimb) << setfill(separator) << tt.Pavarde;
        cout << left << setw(GalutSimb) << setfill(separator) << fixed << setprecision(2) << tt.galutinis << endl;
    }
}

bool compareTwoStudents(studentas a, studentas b)
{
    if (a.Vardas != b.Vardas)
        return a.Vardas.compare(b.Vardas) < 0;

    if (a.Pavarde != b.Pavarde)
        return a.Pavarde.compare(b.Pavarde) < 0;

    return (a.galutinis > b.galutinis);
}

void irasymas(string name, vector<studentas> grupe, int VidArMed)
{
    const char separator = ' ';
    const int VardSimb = 15;
    const int PavSimb = 15;
    const int GalutSimb = 16;
    ofstream f(name);

    sort(grupe.begin(), grupe.end(), compareTwoStudents);
    f << left << setw(VardSimb) << setfill(separator) << "Vardas";
    f << left << setw(PavSimb) << setfill(separator) << "Pavarde";
    if (VidArMed == 1) f << left << setw(GalutSimb) << setfill(separator) << "Galutinis (Med.)" << endl;
    else f << left << setw(GalutSimb) << setfill(separator) << "Galutinis (Vid.)" << endl;
    f << string(VardSimb + PavSimb + GalutSimb, '-') << endl;
    for (auto& tt : grupe) {
        f << left << setw(VardSimb) << setfill(separator) << tt.Vardas;
        f << left << setw(PavSimb) << setfill(separator) << tt.Pavarde;
        f << left << setw(GalutSimb) << setfill(separator) << fixed << setprecision(2) << tt.galutinis << endl;
    }
    f.close();
}

void padalinimas(vector<studentas> grupe, vector<studentas>& grupe1, vector<studentas>& grupe2)
{
    int sk1 = 0;
    int sk2 = 0;
    for (auto& tt : grupe) {
        if (tt.galutinis < 5) {
            grupe1.push_back(tt);
            sk1++;
            grupe1.reserve(sk1);
        }
        else {
            grupe2.push_back(tt);
            sk2++;
            grupe2.reserve(sk2);
        }
    }
}

void generavimas(string txt, int sk)
{
    vector<studentas> grupe;
    std::random_device rd;
    std::mt19937::result_type reiksme = rd() ^ (
        (std::mt19937::result_type)
        std::chrono::duration_cast<std::chrono::seconds>(
            std::chrono::system_clock::now().time_since_epoch()
            ).count() +
        (std::mt19937::result_type)
        std::chrono::duration_cast<std::chrono::microseconds>(
            std::chrono::high_resolution_clock::now().time_since_epoch()
            ).count());

    std::mt19937 gen(reiksme);
    std::mt19937::result_type n;

    ofstream f(txt);
    int ndsk;
    grupe.reserve(sk);
    if (sk <= 1000) {
        while ((n = gen()) > std::mt19937::max() - (std::mt19937::max() - 14) % 15) {}
        ndsk = n % 20 + 1;
    }
    else if (sk <= 100000) {
        while ((n = gen()) > std::mt19937::max() - (std::mt19937::max() - 9) % 10) {}
        ndsk = n % 10 + 1;
    }
    else {
        while ((n = gen()) > std::mt19937::max() - (std::mt19937::max() - 4) % 5) {}
        ndsk = n % 5 + 1;
    }
    
    for (int i = 0; i < sk; i++) {
        studentas stud;
        stud.n = ndsk;
        stud.nd.reserve(stud.n);
        stud.Vardas = "Vardas" + to_string(i + 1);
        stud.Pavarde = "Pavarde" + to_string(i + 1);
        for (int j = 0; j < stud.n; j++) {
            int random;
            while ((n = gen()) > std::mt19937::max() - (std::mt19937::max() - 9) % 10) {}
            random = n % 10 + 1;
            stud.vid = stud.vid + (float)random;
            stud.nd.push_back(random);
        }
        while ((n = gen()) > std::mt19937::max() - (std::mt19937::max() - 9) % 10) {}
        stud.egz = n % 10 + 1;
        grupe.push_back(stud);
        stud.nd.clear();
    }

    f << "Vardas Pavarde";
    for (int i = 0; i < ndsk; i++) f << " ND" << i + 1 ;
    f << " Egz." << endl;

    for (auto& tt : grupe) {
        f << tt.Vardas << " " << tt.Pavarde << " ";
        for (auto& ss : tt.nd) f << ss << " ";
        f << tt.egz;
        if (&tt != &grupe.back()) f << endl;
    }

    f.close();
}

void test(string txt, int duomsk, int StudSkai, int VidArMed)
{
    vector <studentas> grupe;
    vector <studentas> grupe1;
    vector <studentas> grupe2;

    if (remove("neislaike.txt") == 0) remove("neislaike.txt");
    if (remove("islaike.txt") == 0) remove("islaike.txt");
    cout << endl;

    auto start = high_resolution_clock::now(); auto st = start;
    generavimas(txt + ".txt", duomsk);
    duration<double> diff = high_resolution_clock::now() - start;
    cout << "Failo is " << duomsk << " irasu kurimas uztruko: " << diff.count() << " s\n";

    start = high_resolution_clock::now();
    nuskaitymas(txt, grupe, StudSkai, VidArMed);
    diff = high_resolution_clock::now() - start;
    cout << duomsk << " irasu nuskaitymas is failo uztruko: " << diff.count() << " s\n";

    start = high_resolution_clock::now();
    padalinimas(grupe, grupe1, grupe2);
    diff = high_resolution_clock::now() - start;
    cout << duomsk << " studentu rusiavimas i dvi grupes/kategorijas uztruko: " << diff.count() << " s\n";

    start = high_resolution_clock::now();
    if (!grupe1.empty()) irasymas("neislaike.txt", grupe1, VidArMed);
    diff = high_resolution_clock::now() - start;
    cout << duomsk << " irasu neislaikiusiu studentu isvedimas i nauja faila uztruko: " << diff.count() << " s\n";

    start = high_resolution_clock::now();
    if (!grupe2.empty()) irasymas("islaike.txt", grupe2, VidArMed);
    diff = high_resolution_clock::now() - start;
    cout << duomsk << " irasu islaikiusiu studentu isvedimas i nauja faila uztruko: " << diff.count() << " s\n";

    diff = high_resolution_clock::now() - st;
    cout << endl << duomsk << " irasu testo laikas: " << diff.count() << " s\n";

    grupe1.clear();
    grupe2.clear();
    grupe.clear();
}
