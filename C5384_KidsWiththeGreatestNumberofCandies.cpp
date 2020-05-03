class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int len = candies.size();
        int tar = 0;
        vector<bool> res;
        for (int i = 0; i < len; ++i) {
            tar = max(tar, candies[i]);
        }
        
        for (int i = 0; i < len; ++i) {
            if (candies[i] + extraCandies >= tar) res.push_back(true);
            else res.push_back(false);
        }
        
        return res;
    }
};