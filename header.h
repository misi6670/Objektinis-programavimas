#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <stdlib.h>
#include <fstream>

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
using std::ifstream;
using std::getline;
using std::ios;
using std::count;
using std::runtime_error;
using std::numeric_limits;
using std::streamsize;

struct studentas {
    string Vardas = "";
    string Pavarde = "";
    vector <int> nd;
    int n = 0;
    int egz = 0;
    float galutinis = 0;
    float vid = 0;
};

void nuskaitymas(vector<studentas>& grupe, int& StudSkai, int VidArMed);
void mediana(studentas& stud);
void ivedimas(vector<studentas>& grupe, int StudSkai, int VidArMed, int AutoGen);
void autogen(studentas& stud, int i);
void pazymiai(studentas& stud, int i);
void isvedimas(vector<studentas> grupe, int StudSkai, int VidArMed);
bool compareTwoStudents(studentas a, studentas b);
void skaitymoKlaidos(int& duomuo);
void skaitymoKlaidosPaz(int& duomuo, int n);
void skaitymoKlaidosStud(int& duomuo);
