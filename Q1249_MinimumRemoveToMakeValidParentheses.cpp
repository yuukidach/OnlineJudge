class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int len  = s.size();
        stack<int> par;
        int cnt = 0;

        for (int i = 0; i < len; ++i) {
            if (s[i-cnt] == '(') {
                par.push(i-cnt);
            } else if (s[i-cnt] == ')'){
                if (!par.empty()) {
                    par.pop();
                } else {
                    s.erase(i - cnt, 1);
                    cnt++;
                }
            }
        }

        while (!par.empty()) {
            int idx = par.top();
            par.pop();
            s.erase(idx, 1);
        }

        return s;
    }
};