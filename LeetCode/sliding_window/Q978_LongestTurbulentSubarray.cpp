class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int len = arr.size();
        int l = 0, r = 0, res = 1;
        int pre = -1, flag = 1;
        while (r < len) {
            while (r < len && (arr[r] - pre) * flag > 0) {
                flag = -flag;
                pre = arr[r];
                r++;
            }
            res = max(res, r - l);
            l = r - 1;
            flag = -flag;
            if(r >= len) break;
            if(arr[l] == arr[r]) {
                l++;
                r++;
            }
        }

        return res;
    }
};