#pragma once

#include <iostream>
#include <string>
#include <fstream>

using std::cout;
using std::cin;
using std::string;
using std::endl;
using std::ifstream;
using std::ios;
using std::runtime_error;
using std::numeric_limits;
using std::streamsize;

void skaitymoKlaidos(int& duomuo);
void skaitymoKlaidosPaz(int& duomuo, int n);
void skaitymoKlaidosStud(int& duomuo);
void skaitymoKlaidosFailas(ifstream& file, string& name);
