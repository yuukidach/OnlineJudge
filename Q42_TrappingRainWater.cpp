class Solution {
public:
    int findMax(vector<int>& height, int l, int r) {
        int k = height[l];
        int idx = l;
        for (int i = l; i <= r; ++i) {
            if (height[i] > k) {
                k = height[i];
                idx = i;
            }
        }
        return idx;
    }

    int getTrap(vector<int>& height, int l, int r) {
        int lh = height[l];
        int rh = height[r];

        if (l >= r-1) return 0;

        int idx = findMax(height, l+1, r-1);
        int h = height[idx];
        if (h < lh && h < rh) {
            h = min(lh, rh);
            int res = 0;
            for (int i = l+1; i < r; ++i) {
                res += h - height[i];
            }
            return res;
        }
        
        int res = 0;
        res += getTrap(height, l, idx);
        res += getTrap(height, idx, r);

        return res;
    }

    int trap(vector<int>& height) {
        int len = height.size();

        if (len == 0) return 0;
        
        int idx = findMax(height, 0, len-1);
        int res = getTrap(height, 0, idx);
        res += getTrap(height, idx, len-1);
        return res;
    }
};