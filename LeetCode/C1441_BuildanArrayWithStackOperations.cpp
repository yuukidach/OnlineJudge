class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        vector<string> res;
        int cnt = 0;
        int len = target.size();
        
        for (int i = 1; i <=n; ++i) {
            if (cnt >= len) break;
            
            res.push_back("Push");
            if (i != target[cnt]) {
                res.push_back("Pop");
                continue;
            }
            cnt++;
        }
        
        return res;
    }
};