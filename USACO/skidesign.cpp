/*
ID: dachen1
LANG: C++
TASK: skidesign
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ifstream fin("skidesign.in");
    ofstream fout("skidesign.out");

    int n; fin >> n;
    int hills[1001];
    for (int i = 0; i < n; ++i) {
        fin >> hills[i];
    }
    sort(hills, hills+n);

    int res = INT_MAX;
    for (int i = hills[0]; i <= hills[n-1] - 17; ++i) {
        int cost = 0;
        for (int j = 0; j < n; ++j) {
            if (hills[j] >= i && hills[j]-i <= 17) continue;
            int s = (hills[j]-i) * (hills[j]-i);
            s = min(s, (hills[j]-i-17)*(hills[j]-i-17));
            cost += s;
        }
        res = min(res, cost);
    }

    fout << res << endl;

    return 0;
}