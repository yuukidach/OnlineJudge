lass Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int m = INT_MIN;
        vector<bool> res;

        for (int can : candies) {
            m = max(m, can);
        }

        for (int can : candies) {
            if (can + extraCandies < m) res.push_back(false);
            else res.push_back(true);
        }

        return res;
    }
};