class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int len = arr.size();
        int mul[len];

        mul[0] = arr[0];
        for (int i = 1; i < len; ++i) {
            mul[i] = mul[i-1] ^ arr[i];
        }

        int res = 0;
        for (int i = 0; i < len -1; ++i) {
            for (int j = i + 1; j < len; ++j) {
                int a;
                if (i == 0) a = mul[j];
                else a = mul[j] ^ mul[i-1];

                if (a == 0) {
                    res += j - i; 
                }
            }
        }

        return res;
    }
};