/*
ID: dachen1
LANG: C++
TASK: milk
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ifstream fin("milk.in");
    ofstream fout("milk.out");

    int n, m;
    fin >> n >> m;

    vector<vector<int>> v(m, vector<int>(2, 0));
    for (int i = 0; i < m; ++i) {
        fin >> v[i][0] >> v[i][1];
    }

    sort(v.begin(), v.end(), 
         [](vector<int> a, vector<int> b) {
             return a[0] < b[0];
    });


    int cnt = 0, res = 0;
    for (int i = 0; i < m && cnt < n; ++i) {
        if (v[i][1] > n - cnt) {
            res += v[i][0] * (n - cnt);
            break;
        } else {
            res += v[i][0] * v[i][1];
            cnt += v[i][1];
        }
    }

    fout << res << endl;

    return 0;
}