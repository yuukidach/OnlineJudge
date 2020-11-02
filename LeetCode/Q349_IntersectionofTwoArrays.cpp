class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> map;
        set<int> s;
        for (auto x : nums1) {
            map[x] = 1;
        }

        for (auto x : nums2) {
            if (map.count(x)) s.emplace(x);
        }

        vector<int> res;
        for (auto x : s) res.emplace_back(x);

        return res;
    }
};