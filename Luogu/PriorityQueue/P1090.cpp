#include <queue>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int w[n];
    priority_queue<int, vector<int>, greater<int> > pq;

    for (int i = 0; i < n; ++i) {
        cin >> w[i];
        pq.push(w[i]);
    }

    int cnt = 0;
    while (pq.size() != 1) {
        int w1 = pq.top();
        cnt += w1;
        pq.pop();
        int w2 = pq.top();
        cnt += w2;
        pq.pop();
        pq.push(w1+w2);
        
    }

    cout << cnt << endl;

    return 0;
}