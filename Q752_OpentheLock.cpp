class Solution {
public:
    string stradd1(string str,int i) {
        if(str[i]=='9') {
            str[i]='0';
        } else{
            str[i]=str[i]+1;
        } 
        return str;
    }

    string strmin1(string str,int i) {
        if(str[i]=='0') {
            str[i]='9';
        } else {
            str[i]=str[i]-1;
        }
        return  str;
    }

    int openLock(vector<string>& deadends, string target) {
        int len = target.size();
        string lock(len, '0');
        unordered_set<string> dead;
        unordered_set<string> checked;
        for (auto i : deadends) dead.insert(i);

        if (dead.count(lock)) return -1;

        int res = 0;

        queue<string> q;
        q.push(lock);
        checked.insert(lock);

        while (!q.empty()) {
            int len = q.size();
            for (; len > 0; --len) {
                string code = q.front();
                q.pop();
                if (dead.count(code)) continue;

                if (code == target) {
                    return res;
                }

                for (int i = 0; i < 4; ++i) {
                    string nxt;
                    nxt = stradd1(code, i);
                    if (!checked.count(nxt)) {
                        q.push(nxt);
                        checked.insert(nxt);
                    }
                    nxt = strmin1(code, i);
                    if (!checked.count(nxt)) {
                        q.push(nxt);
                        checked.insert(nxt);
                    }
                }
            }
            
            res++;         
        }

        return -1;
    }
};