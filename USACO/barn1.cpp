/*
ID: dachen1
LANG: C++
TASK: barn1
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("barn1.in");
    ofstream fout("barn1.out");

    int m, n, c;
    fin >> m >> n >> c;

    if (m >= c) {
        fout << c << endl;
        return 0;
    }

    vector<int> v(c, 0);
    vector<vector<int>> gap(c-1, vector<int>(2, 0));
    for (int i = 0; i < c; ++i) fin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 1; i < c; ++i) {
        gap[i-1][0] = v[i] - v[i-1];
        gap[i-1][1] = i;
    }

    sort(gap.begin(), gap.end(),
         [](vector<int> a, vector<int> b) {
             return a[0] > b[0];
    });

    int res = v[c-1] - v[0] + 1;
    for (int i = 0; i < m-1; ++i) res -= gap[i][0] - 1;

    fout << res << endl;

    return 0;
}
