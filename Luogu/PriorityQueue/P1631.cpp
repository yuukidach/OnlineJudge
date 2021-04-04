#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main() {
    int n, tmp;
    cin >> n;
    vector<int> a, b;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        a.push_back(tmp);
    }
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        b.push_back(tmp);
    }

    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; ++j) {
            int num = a[i] + b[j];
            if (pq.size() < n) {
                pq.push(num);
            } else if (pq.top() <= num) {
                break;
            } else {
                pq.pop();
                pq.push(num);
            }
        }
    }

    int c[n];
    for (int i = n-1; i >= 0; --i) {
        c[i] = pq.top();
        pq.pop();
    }
    for (int i = 0; i < n; i++) {
        cout << c[i] << " ";
    }

    return 0;
}