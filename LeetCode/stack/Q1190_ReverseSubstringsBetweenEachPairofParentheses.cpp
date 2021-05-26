class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> left;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == '(') left.push(i);
            else if (s[i] == ')') {
                int l = left.top();
                left.pop();
                reverse(s.begin()+l+1, s.begin()+i);
            }
        }

        int i = 0;
        while (i < s.size()) {
            if (s[i] == '(' || s[i] == ')') {
                s.erase(s.begin()+i);
            } else ++i;
        }
        return s;
    }
};