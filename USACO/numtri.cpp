/*
ID: dachen1
LANG: C++
TASK: numtri
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("numtri.in");
    ofstream fout("numtri.out");

    int n; fin >> n;
    int tri[n][n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < i+1; ++j) {
            fin >> tri[i][j];
        }
    }

    int res[n][n];
    memset(res, 0, sizeof(res));
    for (int i = 0; i < n; ++i) {
        res[n-1][i] = tri[n-1][i];
    }

    for (int i = n-2; i >= 0; --i) {
        for (int j = 0; j < i+1; ++j) {
            res[i][j] = max(res[i][j], tri[i][j] + res[i+1][j]);
            res[i][j] = max(res[i][j], tri[i][j] + res[i+1][j+1]);
        }
    }

    fout << res[0][0] << endl;

    return 0;
}