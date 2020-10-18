#include "header.h"

void nuskaitymas(string txtname, vector<studentas>& grupe, int& StudSkai, int VidArMed)
{
    int NamuDarbuSk;
    int pirmas = 0;
    vector<string> eilute;
    string eil;
    ifstream f(txtname + ".txt");

    while (f) {
        if (!f.eof()) {
            std::getline(f, eil);
            eilute.push_back(eil);
        }
        else break;
    }
    f.close();

    for (auto str : eilute) {
        if (pirmas == 0) {
            NamuDarbuSk = count(str.begin(), str.end(), 'N');
            pirmas = 1;
        }
        else {
            studentas stud;
            stud.n = NamuDarbuSk;
            stud.nd.reserve(stud.n);
            for (int i = 0; i < str.length(); i++)
            {
                if (str.at(i) >= 'A' && str.at(i) <= 'Z') {
                    if (stud.Vardas == "")
                        while (str.at(i) != ' ') {
                            stud.Vardas += str.at(i);
                            i++;
                        }
                    else
                        while (str.at(i) != ' ') {
                            stud.Pavarde += str.at(i);
                            i++;
                        }
                }
                else if (isdigit(str.at(i))) {
                    int a = i + 1;
                    if (i == str.length() - 2) {
                        stud.egz = (str.at(i) - '0') * 10 + (str.at(a) - '0');
                        i++;
                    }
                    else if (i == str.length() - 1) {
                        stud.egz = str.at(i) - '0';
                    }
                    else {
                        int paz = 0;
                        if (str.at(a) == ' ') paz = str.at(i) - '0';
                        else {
                            paz = (str.at(i) - '0') * 10 + (str.at(a) - '0');
                            i++;
                        }
                        stud.vid = stud.vid + (float)paz;
                        stud.nd.push_back(paz);
                    }
                }
            }
            if (VidArMed == 1) mediana(stud);
            else stud.galutinis = stud.vid / (float)stud.n;
            stud.galutinis = stud.galutinis * 0.4 + (float)stud.egz * 0.6;
            grupe.push_back(stud);
            stud.nd.clear();
        }
    }
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
    cout << "\n" << i + 1 << " studento atsitiktinai sugeneruoti pazymiai: \n";
    stud.n = autosk(1, 15);
    stud.nd.reserve(stud.n);
    for (int j = 0; j < stud.n; j++) {
        int random;
        random = autosk(1, 10);
        cout << random << " ";
        stud.vid = stud.vid + (float)random;
        stud.nd.push_back(random);
    }
    cout << endl;
    stud.egz = autosk(1, 10);
    cout << "\n" << i + 1 << " studento atsitiktinai sugeneruotas egzamino balas: " << stud.egz << endl;
}

int autosk(int nuo, int iki)
{
    using hrClock = high_resolution_clock;
    std::mt19937 mt(static_cast<long unsigned int>(hrClock::now().time_since_epoch().count()));
    std::uniform_int_distribution<int> dist(nuo, iki);
    int sk = dist(mt);
    return sk;
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

void generavimas(string txt, int sk, int& ndsk)
{
    vector<studentas> grupe;

    const char separator = ' ';
    const int VardSimb = 15;
    const int PavSimb = 15;
    const int NdSimb = 5;

    ofstream f(txt);

    grupe.reserve(sk);
    if (sk <= 1000) ndsk = autosk(1, 15);
    else if (sk <= 100000) ndsk = autosk(1, 10);
    else ndsk = autosk(1, 5);

    for (int i = 0; i < sk; i++) {
        studentas stud;
        stud.n = ndsk;
        stud.nd.reserve(stud.n);
        zmogausVP(stud.Vardas, stud.Pavarde);
        for (int j = 0; j < stud.n; j++) {
            int random;
            random = autosk(1, 10);
            stud.vid = stud.vid + (float)random;
            stud.nd.push_back(random);
        }
        stud.egz = autosk(1, 10);
        grupe.push_back(stud);
        stud.nd.clear();
    }

    f << left << setw(VardSimb) << setfill(separator) << "Vardas";
    f << left << setw(PavSimb) << setfill(separator) << "Pavarde";
    for (int i = 0; i < ndsk; i++) f << left << setw(NdSimb) << setfill(separator) << "ND" + to_string(i + 1);
    f << "Egz." << endl;

    for (auto& tt : grupe) {
        f << left << setw(VardSimb) << setfill(separator) << tt.Vardas;
        f << left << setw(PavSimb) << setfill(separator) << tt.Pavarde;
        for (auto& ss : tt.nd) f << left << setw(NdSimb) << ss;
        f << tt.egz;
        if (&tt != &grupe.back()) f << endl;
    }

    f.close();
    grupe.clear();
}

void zmogausVP(string& vardas, string& pavarde) {

    map<int, string> vardai, pavardes_m, pavardes_v;

    vardai[100] = "Irma";
    vardai[101] = "Alma";
    vardai[102] = "Irena";
    vardai[103] = "Egle";
    vardai[104] = "Jolanta";
    vardai[105] = "Julija";
    vardai[106] = "Goda";
    vardai[107] = "Kotryna";
    vardai[108] = "Ugne";
    vardai[109] = "Saule";
    vardai[110] = "Auguste";
    vardai[111] = "Milda";
    vardai[112] = "Gabija";
    vardai[113] = "Teja";
    vardai[114] = "Orinta";
    vardai[115] = "Emilija";
    vardai[116] = "Ilona";
    vardai[117] = "Sigita";
    vardai[118] = "Evelina";
    vardai[119] = "Aurelija";

    vardai[120] = "Petras";
    vardai[121] = "Jonas";
    vardai[122] = "Ignas";
    vardai[123] = "Darius";
    vardai[124] = "Simas";
    vardai[125] = "Paulius";
    vardai[126] = "Donatas";
    vardai[127] = "Rytis";
    vardai[128] = "Saulius";
    vardai[129] = "Valdas";
    vardai[130] = "Saulius";
    vardai[131] = "Gytis";
    vardai[132] = "Jokubas";
    vardai[133] = "Aurimas";
    vardai[134] = "Gvidas";
    vardai[135] = "Tomas";
    vardai[136] = "Rimas";
    vardai[137] = "Aidas";
    vardai[138] = "Dominykas";
    vardai[139] = "Kipras";

    vardas = vardai[autosk(100, 139)];

    switch (*vardas.rbegin()) {
    case 's':
        pavarde = "Pavardenis" + to_string(autosk(1, 500));
        break;
    default:
        pavarde = "Pavardaite" + to_string(autosk(1, 500));
        break;
    };
}

void test(string txt, int duomsk, int StudSkai, int VidArMed)
{
    vector <studentas> grupe;
    vector <studentas> grupe1;
    vector <studentas> grupe2;
    int ndsk = 0;

    if (remove("neislaike.txt") == 0) remove("neislaike.txt");
    if (remove("islaike.txt") == 0) remove("islaike.txt");
    cout << endl;

    auto start = high_resolution_clock::now(); auto st = start;
    generavimas(txt + ".txt", duomsk, ndsk);
    duration<double> diff = high_resolution_clock::now() - start;
    cout << "Failo is " << duomsk << " irasu (namu darbu skaicius: " << ndsk << ") kurimas uztruko: " << diff.count() << " s\n";

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
