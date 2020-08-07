class Solution {
public:
    int findBestValue(vector<int>& arr, int target) {
        sort(arr.begin(), arr.end());
        int len = arr.size();
        int cnt = 0;
        int res = 0;
        int flag = 0;

        for (int i = 0; i < len; ++i) {
            int val = cnt + arr[i] * (len - i);
            
            if (val == target) {
                return arr[i];
            } else if (val > target) {
                double div = (target - cnt) * 1.0 / (len - i);
                res = div;
                if (div - res > 0.5) res += 1;
                flag = 1;
                break;  
            }

            cnt += arr[i];
        }

        if (flag == 0) res = arr[len - 1];

        return res;
    }
};