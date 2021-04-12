class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> snums;
        for (auto &num : nums) {
            snums.push_back(to_string(num));
        }

        string res = "";
        sort(snums.begin(), snums.end(), [](string &a, string &b) {
            return (a + b  > b + a);
        });

        for (auto &snum : snums) res += snum;
        if (res[0] == '0') res = "0";

        return res;
    }
};