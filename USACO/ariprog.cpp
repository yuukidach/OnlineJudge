/*
ID: dachen1
LANG: C++
TASK: ariprog
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("ariprog.in");
    ofstream fout("ariprog.out");

    int n; fin >> n;
    int m; fin >> m;
    int table[250*250*2+1] = {0};
    vector<vector<int>> res;

    for (int i = 0; i <= m; ++i) {
        for (int j = 0; j <= m; ++j) {
            table[i*i+j*j] = 1;
        }
    }

    int maxm = m*m*2;
    for (int a = 0; a < maxm; ++a) {
        if (table[a] != 1) continue;
        for (int b = 1; b <= (maxm-a)/(n-1); ++b) {
            int flag = 1;
            for (int k = 1; k < n; ++k) {
                if (table[a+k*b] != 1) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                vector<int> v = {a, b};
                res.emplace_back(v);
            }
        }
    }

    sort(res.begin(), res.end(),
         [](vector<int> a, vector<int> b) {
             if (a[1] < b[1]) return true;
             else if (a[1] > b[1]) return false;
             else if (a[0] < b[0]) return true;
             return false;
         }
    );

    if (res.empty()) {
        fout << "NONE" << endl;
        return 0;
    }

    for (auto v : res) {
        fout << v[0] << " " << v[1] << endl;
    }

    return 0;
}