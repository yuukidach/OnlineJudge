class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n < 3) return 0;
        int l = 1, r = n-2;
        int lmax = height[0], rmax = height[n-1];
        int res = 0;
        while (l <= r) {
            int val = min(lmax, rmax);
            if (val == lmax) {
                int gap = val - height[l];
                if (gap > 0) res += gap;
                lmax = max(lmax, height[l]);
                l++;
            } else {
                int gap = val - height[r];
                if(gap > 0) res += gap;
                rmax = max(rmax, height[r]);
                r--;
            }
        }

        return res;
    }
};