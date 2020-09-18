/*
ID: dachen1
LANG: C++
TASK: namenum
*/
#include<iostream>
#include<fstream>

using namespace std;

int main() {
    ifstream fin("namenum.in");
    ofstream fout("namenum.out");

    long long num, flag = 0;
    fin >> num;

    fin.close();
    fin.open("dict.txt");
    string name;
    while(fin >> name) {
        long long trans = 0;
        for (char ch : name) {
            if (ch < 'Q') trans = trans * 10 + (ch - 'A') / 3 + 2;
            else trans = trans * 10 + (ch - 'Q') / 3 + 7;
        }
        if (trans == num) {
            fout << name << endl;
            flag = 1;
        }
    }
    
    if (!flag) fout << "NONE\n";

    return 0;
}