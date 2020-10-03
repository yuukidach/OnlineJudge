/*
ID: dachen1
LANG: C++
TASK: milk3
*/

#include <bits/stdc++.h>

using namespace std;

set<int> res;
int mark[21][21][21];

void dfs(vector<int> &a, vector<int> b, int src, int dst) {
    if (b[dst] != a[dst] && b[src] != 0) {
        int gap = a[dst] - b[dst];
        gap = min(gap, b[src]);
        b[src] -= gap;
        b[dst] += gap;
    }

    if (mark[b[0]][b[1]][b[2]] == 1) return;
    mark[b[0]][b[1]][b[2]] = 1;

    if (b[0] == 0) res.emplace(b[2]);

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (i == j) continue;
            dfs(a, b, i, j);
        }
    }
}


int main() {
    ifstream fin("milk3.in");
    ofstream fout("milk3.out");

    vector<int> a(3, 0); fin >> a[0] >> a[1] >> a[2];
    vector<int> b(3, 0);
    b[0] = 0; b[1] = 0; b[2] = a[2];
    res.emplace(a[2]);

    dfs(a, b, 2, 0);
    dfs(a, b, 2, 1);

    for (auto it = res.begin(); it != res.end(); ++it) {
        fout << *it;
        auto it2 = ++it++;
        if (it2 != res.end()) fout << " ";
        it----;
    } 
    fout << endl;

    return 0;
}