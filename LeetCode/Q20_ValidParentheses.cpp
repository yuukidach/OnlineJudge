class Solution {
public:
    bool isValid(string s) {
        string b = "";
        map<char, char> m = {
            {']', '['},
            {'}', '{'},
            {')', '('}
        };

        for (char ch : s) {
            if (ch== '(' || ch == '{' || ch== '[') {
                b += ch;
            } else if (b.size() == 0 || b[b.size()-1] != m[ch]) {
                return false;
            } else {
                b.erase(b.begin() + b.size() - 1);
            }
        }

        if (b.size() != 0) return false;

        return true;
    }
};