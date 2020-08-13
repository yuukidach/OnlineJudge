class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") return "0";
        
        int len1 = num1.size();
        int len2 = num2.size();
        vector<int> inter(len1+len2);
        string res = "";

        for (int i = len1-1; i >=0; --i) {
            int a = num1[i] - '0';
            for (int j = len2-1; j >= 0 ; --j) {
                int b = num2[j] - '0';
                inter[i+j+1] += a * b;
                inter[i+j] += inter[i+j+1] / 10;
                inter[i+j+1] %= 10;
            }
        }

        for (int i = 0; i < len1+len2; ++i) {
            res += inter[i] + '0';
        }

        if (res[0] == '0') res.erase(res.begin());

        return res;
    }
};