class Solution {
public:
    void reverse_str(string &str) {
        int len = str.size();
        long long ret = 0;
        for (int i = 0; i < len / 2; ++i) {
            swap(str[i], str[len-1-i]);
        }
    }

    string addBinary(string a, string b) {
        string res = "";

        reverse_str(a);
        reverse_str(b);

        int lena = a.size();
        int lenb = b.size();
        if (lena < lenb) swap(a, b); 
        int cnt = 0;
        
        for(int i = 0; i < b.size(); ++i) {
            int sum = a[i] - '0' + b[i] - '0' + cnt;
            res += (sum & 1) ? '1' : '0';
            cnt = (sum & 2) ? 1 : 0;
        }

        for (int i = b.size(); i < a.size(); ++i) {
            int sum = a[i] - '0' + cnt;
            res += (sum & 1) ? '1' : '0';
            cnt = (sum & 2) ? 1 : 0;
        }

        if (cnt != 0) res += '1';

        reverse_str(res);

        return res;
    }
};