class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        vector<int> p;
        vector<int> res;
        for (int i = m; i >= 1; --i) p.push_back(i);
        
        int len = queries.size();
        for (int i = 0; i < len; ++i) {
            int num = queries[i];
            for (int j = 0; j < m; ++j) {
                if (p[j] == num) {
                    p.push_back(num);
                    p.erase(p.begin() + j);
                    res.push_back(m-1-j);
                    break;
                }
            }
        }
        
        return res;
    }
};