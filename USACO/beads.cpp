/*
ID: dachen1
LANG: C++
TASK: beads
*/
#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream fin("beads.in");
    ofstream fout("beads.out");

    int n;
    string beads;
    fin >> n >> beads;

    int res = 0;
    for (int i = 0; i < n; ++i) {
        int pos = i, status = 0;
        int cnt = 0;
        while (pos != (i + n - 1) % n) {
            if (status == 0) {
                if (beads[pos] != 'w') status = beads[pos] - 'a';
                cnt++;
                pos = (pos+1) % n;
            } else {
                if (beads[pos] == 'w' || beads[pos] == status + 'a') {
                    cnt++;
                    pos = (pos+1) % n;
                } else {
                    break;
                }
            }
        }

        int pos2 = (i + n - 1) % n;
        status = 0;
        while (pos2 != (pos+n-1) % n) {
            if (status == 0) {
                if (beads[pos2] != 'w') status = beads[pos2] - 'a';
                cnt++;
                pos2 = (pos2+n-1) % n;
            } else {
                if (beads[pos2] == 'w' || beads[pos2] == status + 'a') {
                    cnt++;
                    pos2 = (pos2+n-1) % n;
                } else {
                    break;
                }
            }
        }
        
        res = max(res, cnt);
    }

    fout << res << endl;

    return 0;
}