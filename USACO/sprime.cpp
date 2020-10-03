/*
ID: dachen1
LANG: C++
TASK: sprime
*/

#include <bits/stdc++.h>

using namespace std;
queue<int> q;

bool is_prime(int n) {
    for (int i = 2; i <= sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}


int main(){
    ifstream fin("sprime.in");
    ofstream fout("sprime.out");

    int n; fin >> n;
    q.push(2); q.push(3); q.push(5); q.push(7);

    int div = pow(10, n-1);

    if (n != 1) {
        while (!q.empty()) {
            int num = q.front();
            q.pop();
            if (num / div > 0) {
                fout << num << endl;
                continue;
            } 
            for (int i = 1; i <= 9; i += 2) {
                int tmp = num * 10 + i;
                if (is_prime(tmp)) q.push(tmp);
            }
        }
    } else {
        fout << 2 << endl;
        fout << 3 << endl;
        fout << 5 << endl;
        fout << 7 << endl;
    }

    return 0;
}