class Solution {
public:
    bool checkPalindrome(string &s, int l, int r) {
        for (int i = l; i < (l+r) / 2; ++i) {
            if (s[i] != s[r+l-i-1]) return false;
        }
        return true;
    }

    vector<vector<string>> getList(string &s, int l, int r) {
        vector<vector<string>> mat;
        if (r == l) return mat;

        for (int i = l+1; i <= r; ++i) {
            if (checkPalindrome(s, l, i)) {
                vector<vector<string>> vv = getList(s, i, r);
                if (vv.empty() && i == r) {
                    vector<string> v = {s.substr(l, i-l)};
                    mat.push_back(v);
                }

                for (auto & v : vv) {
                    v.insert(v.begin(), s.substr(l, i-l));
                    mat.push_back(v);
                }
            }
        }

        return mat;
    }

    vector<vector<string>> partition(string s) {
        int len = s.size();
        return getList(s, 0, len);
    }
};