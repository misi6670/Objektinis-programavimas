#pragma once

#include "klaidos.h"
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <fstream>
#include <chrono>
#include <random>
#include <map>

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
using std::ofstream;
using std::getline;
using std::ios;
using std::count;
using std::to_string;
using std::chrono::high_resolution_clock;
using std::chrono::duration;
using std::map;

struct studentas {
    string Vardas = "";
    string Pavarde = "";
    vector <int> nd;
    int n = 0;
    int egz = 0;
    float galutinis = 0;
    float vid = 0;
};

void nuskaitymas(string txtname, vector<studentas>& grupe, int& StudSkai, int VidArMed);
void mediana(studentas& stud);
void ivedimas(vector<studentas>& grupe, int StudSkai, int VidArMed, int AutoGen);
void autogen(studentas& stud, int i);
int autosk(int nuo, int iki);
void pazymiai(studentas& stud, int i);
void isvedimas(vector<studentas> grupe, int VidArMed);
bool compareTwoStudents(studentas a, studentas b);
void irasymas(string name, vector<studentas> grupe, int VidArMed);
void padalinimas(vector<studentas> grupe, vector<studentas>& grupe1, vector<studentas>& grupe2);
void generavimas(string txt, int sk, int& ndsk);
void zmogausVP(string& vardas, string& pavarde);
void test(string txt, int duomsk, int StudSkai, int VidArMed);
