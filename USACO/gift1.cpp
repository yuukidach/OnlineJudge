/*
ID: dachen1
LANG: C++
TASK: gift1
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <map>

using namespace std;

int main() {
    ifstream fin("gift1.in");
    ofstream fout("gift1.out");

    int n;
    fin >> n;
    map<string, int> m;
    vector<string> v;
    for (int i = 0; i < n; ++i) {
        string name;
        fin >> name;
        m[name] = 0;
        v.emplace_back(name);
    }

    int amount, cnt;
    for (int i = 0; i < n; ++i) {
        string name;
        fin >> name;
        fin >> amount >> cnt;
        if (cnt == 0) {
            m[name] += amount;
            continue;
        }
        int given = amount / cnt;
        int left = amount % cnt;
        m[name] += left - amount;
        for (int j = 0; j < cnt; ++j) {
            fin >> name;
            m[name] += given;
        }
    }

    for (auto x : v) {
        fout << x << " " << m[x] << endl;
    }
    
    return 0;
}