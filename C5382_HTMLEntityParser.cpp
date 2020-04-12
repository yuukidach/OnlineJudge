class Solution {
public:
    string entityParser(string text) {      
        string src[6] = {"&quot;", "&apos;", "&amp;", "&gt;", "&lt;", "&frasl;"};
        char dst[6] = {'\"', '\'', '&', '>', '<', '/'};
        string res = "";
        int len = text.size();
        
        int flag = 0;
        
        for (int i = 0; i < len;) {
            if (text[i] != '&') {
                res += text[i++];
                flag = 0;
                continue;
            }
            
            string sub = "";
            for (int j = 0; j < 6; ++j) {
                int l = src[j].size();
                if (len - i < l) continue;
                sub = text.substr(i, l);
                if (sub.compare(src[j]) == 0) {
                    i += l;
                    res += dst[j];
                    flag = 1;
                    break;
                }
            }
            
            if (flag != 1)
                res += text[i++];
        }
        
        return res;
    }
};