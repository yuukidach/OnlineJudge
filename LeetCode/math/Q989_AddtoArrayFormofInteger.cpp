class Solution {
public:
    vector<int> addToArrayForm(vector<int>& A, int K) {
        vector<int> res, b;
        reverse(A.begin(), A.end());
        while (K != 0) {
            b.push_back(K % 10);
            K /= 10;
        }
        int lena = A.size(), lenb = b.size();
        if (lena < lenb) {
            swap(A, b);
            swap(lena, lenb);
        }
        int inc = 0;
        for (int i = 0; i < lenb; ++i) {
            int s = A[i] + b[i] + inc;
            inc = s / 10;
            res.push_back(s % 10);
        }
        for (int i = lenb; i < lena; ++i) {
            int s = A[i] + inc;
            inc = s / 10;
            res.push_back(s % 10);
        }
        if (inc) res.push_back(inc);

        reverse(res.begin(), res.end());
        return res;
    }
};