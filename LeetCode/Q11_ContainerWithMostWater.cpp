class Solution {
public:
    int maxArea(vector<int>& height) {
        int len = height.size();
        int res = 0;

        int l = 0, r = len - 1;
        while(l < r) {
            int hl = height[l], hr = height[r];
            int h = min(hl, hr);
            res = max((r-l) * h, res);

            if (hl < hr) {
                while(height[l] <= hl && l < r) ++l;
            } else {
                while(height[r] <= hr && r > l) --r;
            }
        }

        return res;
    }
};