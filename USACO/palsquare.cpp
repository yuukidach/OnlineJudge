/*
ID: dachen1
LANG: C++
TASK: palsquare
*/
#include<iostream>
#include<fstream>

using namespace std;

bool check_palindrome (string s) {
    int len = s.size();
    for (int i = 0; i < len/2; ++i) {
        if (s[i] == s[len-i-1]) continue;
        else return false;
    }
    return true;
}


string int2string (int n, int base) {
    string s;
    while (n != 0) {
        int b = n % base;
        n /= base;
        if (b < 10) s += '0' + b;
        else s += 'A' + b - 10;
    }
    for (int i = 0; i < s.size()/2; i++)  {
        swap(s[i], s[s.size()-1-i]);
    } 
    return s;
}

int main() {
    ifstream fin("palsquare.in");
    ofstream fout("palsquare.out");

    int base;
    fin >> base;
    fout << "1 1\n";

    string num, snum;

    for (int i = 2; i <= 300; ++i) {
        int ii = i * i;
        snum = int2string(ii, base);
        if(check_palindrome(snum)) {
            num = int2string(i, base);
            fout << num << " " << snum << endl;
        }
    }

    return 0;
}