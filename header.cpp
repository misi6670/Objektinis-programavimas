#include "header.h"

void nuskaitymas(vector<studentas>& grupe, int& StudSkai, int VidArMed)
{
    ifstream f;
    string title;
    char delimeter(' ');
    int NamuDarbuSk;
    string txtname;

    cout << "\n Iveskite norimo nuskaityti tekstinio failo pavadinima ('.txt' vesti nereikia)" << endl;
    cin >> txtname;
    f.open(txtname + ".txt", ios::in);
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
    cout << "\n" << i + 1 << " studento atsitiktinai sugeneruoti pazymiai: \n";
    stud.n = rand() % 20 + 1;
    stud.nd.reserve(stud.n);
    for (int j = 0; j < stud.n; j++) {
        int random;
        random = rand() % 10 + 1;
        cout << random << " ";
        stud.vid = stud.vid + (float)random;
        stud.nd.push_back(random);
    }
    cout << endl;
    stud.egz = rand() % 10 + 1;
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
        if (paz == 0) {
            if (stud.n == 0) {
                skaitymoKlaidosPaz(paz, stud.n);
                stud.vid = stud.vid + (float)paz;
            }
            nulis = 0;
        }
        else {
            stud.nd.push_back(paz);
            stud.n++;
            stud.nd.reserve(stud.n);
            cout << "Ivedete " << stud.n << " pazymi(-ius)" << endl;
        }
    }
    cout << "\n Iveskite " << i + 1 << " studento egzamino rezultata \n";
    cin >> stud.egz;
    skaitymoKlaidosPaz(stud.egz, stud.n);
}

void isvedimas(vector<studentas> grupe, int StudSkai, int VidArMed)
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

void skaitymoKlaidos(int& duomuo) {
    do {
        try {
            if (cin.fail()) throw runtime_error("Ivedete netinkama duomeni\n");
        }
        catch (const std::runtime_error& e) {
            cout << e.what();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Veskite duomeni dar karta: ";
            cin >> duomuo;
        }
    } while (cin.fail() == true);
}

void skaitymoKlaidosPaz(int& duomuo, int n) {
    do {
        try {
            if (cin.fail()) throw runtime_error("Ivedete netinkama duomeni\n");
            else if (duomuo > 10) throw runtime_error("Ivestas pazymys virsija 10\n");
            else if (duomuo < 0) throw runtime_error("Pazymys negali buti neigiamas\n");
            else if (duomuo == 0 && n == 0) throw runtime_error("Privalote ivesti bent viena pazymi\n");
        }
        catch (const std::runtime_error& e) {
            cout << e.what();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Veskite duomeni dar karta: ";
            cin >> duomuo;
        }
    } while (cin.fail() == true || duomuo > 10 || duomuo < 0 || (duomuo == 0 && n==0));
}

void skaitymoKlaidosStud(int& duomuo) {
    do {
        try {
            if (cin.fail()) throw runtime_error("Ivedete netinkama duomeni\n");
            else if (duomuo <= 0) throw runtime_error("Studentu skaicius negali buti neigiamas arba lygus 0\n");
        }
        catch (const std::runtime_error& e) {
            cout << e.what();
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Veskite duomeni dar karta: ";
            cin >> duomuo;
        }
    } while (cin.fail() == true || duomuo <= 0);
}
