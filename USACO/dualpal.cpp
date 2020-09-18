/*
ID: dachen1
LANG: C++
TASK: dualpal
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
    ifstream fin("dualpal.in");
    ofstream fout("dualpal.out");

    int n, s, cnt = 0;
    fin >> n >> s;
    s++;

    while (cnt < n) {
        string snum;
        int flag = 0;
        for (int i = 2; i < 11; i++) {
            snum = int2string(s, i);
            if (check_palindrome (snum)) flag++;
            if (flag >= 2) break;
        }
        if (flag >= 2) {
            cnt++;
            fout << s << endl;
        }
        s++;
    }

    return 0;
}