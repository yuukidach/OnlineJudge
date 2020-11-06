class Solution {
public:
    int cnt1(int num) {
        int cnt = 0;
        while (num != 0) {
            cnt = cnt + (1 & num);
            num >>= 1;
        }
        return cnt;
    }

    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [this](int a, int b) {
            int a1 = cnt1(a), b1 = cnt1(b);
            if (a1 < b1) return true;
            else if (a1 == b1 && a < b) return true;
            return false;
        });

        return arr;
    }
};