/*
ID: dachen1
LANG: C++
TASK: milk2
*/
#include<fstream>
#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main() {
    ifstream fin("milk2.in");
    ofstream fout("milk2.out");

    int n;
    fin >> n;
    vector<vector<int>> times(n, vector<int>(2, 0));
    for (int i = 0; i < n; ++i) fin >> times[i][0] >> times[i][1];

    sort(times.begin(), times.end(), 
         [](vector<int> a, vector<int> b) { 
            return a[0] < b[0];
         }
    );

    int cont = times[0][1] - times[0][0], dis = 0;
    int cnt = cont, r = times[0][1];
    for (int i = 1; i < n; ++i) {
        if(times[i][0] <= r) {
            cnt += max(0, times[i][1] - r);
            cont = max(cont, cnt);
            r = max(r, times[i][1]);
        } else {
            dis = max(dis, times[i][0] - r);
            cnt = times[i][1] - times[i][0];
            r = times[i][1];
        }
    }

    fout << cont << " " << dis << endl;

    return 0;
}