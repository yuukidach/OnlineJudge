class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        int suma = 0, sumb = 0;
        for (auto a : A) suma += a;
        for (auto b : B) sumb += b;
        int aver = (suma + sumb) >> 1;

        vector<int> res;
        for (auto a : A) {
            for (auto b : B) {
                if (a - b == suma - aver) {
                    res.push_back(a);
                    res.push_back(b);
                    return res;
                }
            }
        }

        return res;
    }
};