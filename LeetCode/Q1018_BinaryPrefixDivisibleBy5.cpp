class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& A) {
        vector<bool> res;
        unsigned int num = 0;
        for (int &a : A) {
            num = ((num << 1) + a) % 10;
            res.push_back(!(num % 5));
        }
        return res;
    }
};