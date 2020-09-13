/*
ID: dachen1
LANG: C++
TASK: friday
*/

#include <iostream>
#include <fstream>

using namespace std;

const int base_year = 1900;

bool is_leap_year(int year) {
    if (year % 4 != 0) return false;
    if (year % 100 == 0 && year % 400 != 0) return false;
    return true;
}


int main() {
    ifstream fin("friday.in");
    ofstream fout("friday.out");

    int n, cnt = 13;
    int res[7] = {0};
    fin >> n;

    for (int i = 0; i < n; ++i) {
        res[cnt % 7]++;
        cnt += 31;
        res[cnt % 7]++;
        if (is_leap_year(base_year + i)) {
            cnt += 29;
        } else {
            cnt += 28;
        }
        res[cnt % 7]++;
        cnt += 31;
        res[cnt % 7]++;
        cnt += 30;
        res[cnt % 7]++;
        cnt += 31;
        res[cnt % 7]++;
        cnt += 30;
        res[cnt % 7]++;
        cnt += 31;
        res[cnt % 7]++;
        cnt += 31;
        res[cnt % 7]++;
        cnt += 30;
        res[cnt % 7]++;
        cnt += 31;
        res[cnt % 7]++;
        cnt += 30;
        res[cnt % 7]++;
        cnt += 31;
    }

    fout << res[6] << " " << res[0] << " ";
    for (int i = 1; i < 5; ++i) {
        fout << res[i] << " ";
    }
    fout << res[5] << endl;

    return 0;
}