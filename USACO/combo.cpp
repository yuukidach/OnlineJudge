/*
ID: dachen1
LANG: C++
TASK: combo
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

bool cal_gap(int a, int n, int i) {
    int min_n = min(a, i);
    int max_n = max(a, i);
    int gap1 = max_n - min_n;
    int gap2 = min_n + n - max_n;
    return (gap1 <= 2 || gap2 <= 2);
}

int main() {
    ifstream fin("combo.in");
    ofstream fout("combo.out");

    int n, a[3], b[3], res = 0;
    fin >> n;
    fin >> a[0] >> a[1] >> a[2];
    fin >> b[0] >> b[1] >> b[2];

    int gap;
    for (int i = 1; i <= n; ++i) {
        int flag = 0;
        if (cal_gap(a[0], n, i)) flag = 1;
        if (cal_gap(b[0], n, i)) flag |= 2;
        if (!flag) continue;
        for (int j = 1; j <= n; ++j) {
            int flag1 = flag;
            if (!cal_gap(a[1], n, j)) flag1 &= 2;
            if (!cal_gap(b[1], n, j)) flag1 &= 1;
            if (!flag1) continue;
            for (int k = 1; k <= n; ++k) {
                int flag2 = flag1;
                if (!cal_gap(a[2], n, k)) flag2 &= 2;
                if (!cal_gap(b[2], n, k)) flag2 &= 1;
                if (!flag2) continue;
                res++;
                if (res == 250) {
                    fout << res << endl;
                    return 0;
                }
            }
        }
    }

    fout << res << endl;

    return 0;
}