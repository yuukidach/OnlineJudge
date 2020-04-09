class Solution {
public:
    void gen_str(vector<string>& sv, int l, int r, string s) {
        if (l < 0 || r < 0) return;

        if (l == 0 && r == 0) {
            sv.push_back(s);
            return;
        }

        if (l > r) return ;

        if (l == r) {
            gen_str(sv, l-1, r, s+'(');
            return;
        }

        gen_str(sv, l-1, r, s+'(');
        gen_str(sv, l, r-1, s+')');
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        gen_str(res, n, n, "");
        return res;
    }
};