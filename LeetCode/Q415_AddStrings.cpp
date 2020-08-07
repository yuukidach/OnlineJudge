class Solution {
public:
    string addStrings(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int len = min(len1, len2);
        string s = "";
        
        int add_one = 0;
        for (int i = 0; i < len; ++i) {
            int sum = num1[len1-1-i] - '0' + num2[len2-1-i] - '0' + add_one;
            add_one = sum / 10;
            sum %= 10;
            s += sum + '0';
        }

        if (len1 >= len2) {
            for (int i = 0; i < len1-len2; ++i) {
                int sum = num1[len1-len2-1-i] - '0' + add_one;
                add_one = sum / 10;
                sum %= 10;
                s += sum + '0';
            }
        } else {
            for (int i = 0; i < len2-len1; ++i) {
                int sum = num2[len2-len1-1-i] - '0' + add_one;
                add_one = sum / 10;
                sum %= 10;
                s += sum + '0';
            }
        }

        if (add_one) s += "1";

        len = s.size();
        string res = "";
        for (int i = 0; i < len; ++i) {
            res += s[len-1-i];
        }

        return res;
    }
};