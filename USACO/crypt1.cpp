/*
ID: dachen1
LANG: C++
TASK: crypt1
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>

using namespace std;

bool is_valid(int flag, int num,  int type) {
    int mark = 0;

    if (type == 4 && (num <= 999 || num >= 10000)) return false;
    if (type == 3 && (num <= 99 || num >= 1000)) return false;
    if (type == 2 && (num <= 9 || num >= 100)) return false;

    while (num != 0) {
        mark |= 1 << num % 10;
        num /= 10;
    }
    if ((mark | flag) == flag) {
        return true;
    }

    return false;
}


int main() {
    ifstream fin("crypt1.in");
    ofstream fout("crypt1.out");

    int n;
    fin >> n;
    int b[n] = {0}, flag = 0;
    for (int i = 0; i < n; ++i) {
        fin >> b[i];
        flag |= 1 << b[i];
    }

    int res = 0;

    for (int i = 100; i <= 999; ++i) {
        if (!is_valid(flag, i, 3)) continue;
        for (int j = 10; j <= 99; ++j) {
            if (!is_valid(flag, j, 2)) continue;

            int a1 = i * (j % 10);
            if (!is_valid(flag, a1, 3)) continue;
            int a2 = i * (j / 10);
            if (!is_valid(flag, a2, 3)) continue;
            int a3 = i * j;
            if (!is_valid(flag, a3, 4)) continue;

            res++;
        }
    }

    fout << res << endl;

    return 0;
}
