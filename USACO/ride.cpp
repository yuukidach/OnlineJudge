/*
ID: dachen1
LANG: C++
TASK: ride
*/
#include <cstdio>
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("ride.in");
    ofstream fout("ride.out");

    string a, b;
    int aa = 1, bb = 1;
    fin >> a >> b;
    for (char ch : a) {
        aa = aa * (ch - 'A' + 1) % 47;
    }
    for (char ch : b) {
        bb = bb * (ch - 'A' + 1) % 47;
    }

    if (aa == bb) {
        fout << "GO" << endl;
    } else {
        fout << "STAY" << endl;
    }

    return 0;
}