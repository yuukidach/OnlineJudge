class Solution {
public:
    string removeDuplicates(string S) {
        int flag = 1;
        while(!S.empty() && flag) {
            flag = 0;
            for (int i = 1; i < S.size(); ++i) {
                if (S[i] == S[i-1]) {
                    flag = 1;
                    S.erase(i-1, 1);
                    S.erase(i-1, 1);
                }
            }
        }
        return S;
    }
};
