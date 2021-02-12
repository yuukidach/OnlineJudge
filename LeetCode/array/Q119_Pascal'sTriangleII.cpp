class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> s = {0, 1, 0};
        for (int m = 0; m < rowIndex; ++m) {
            for (int i = 0; i < s.size()-1; ++i) {
                s[i] = s[i] + s[i+1];  
            }
            s.insert(s.begin(), 0);
        }

        s.erase(s.begin());
        s.erase(s.end()-1);

        return s;     
    }
};