class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        vector<string> ans;
        int len = words.size();
        int mark[101] = {0};
        
        for (int i = 0; i < len-1; ++i) {
            
            if (mark[i]) continue;
            
            for (int j = i+1; j < len; ++j) {
                
                if (mark[j] || mark[i]) continue;
                
                if (words[i].size() < words[j].size()) {
                    size_t p = words[j].find(words[i]);
                    if (p != string::npos) {
                        mark[i] = 1;
                        ans.push_back(words[i]);
                    }
                } else if (words[j].size() < words[i].size()){
                    size_t p = words[i].find(words[j]);
                    if (p != string::npos) {
                        mark[j] = 1;
                        ans.push_back(words[j]);
                    }
                }
            }
        }
        return ans;
    }
};