class Solution {
public:
    int maxDiff(int num) {
        int cbit = 0;
        int cnum = num;
        while (cnum != 0) {
            cnum = cnum / 10;
            cbit++;
        }
        
        int res = 0;
        int l = num, r = num, c = -1;
        for (int i = cbit-1; i >= 0; --i) {
            int k = l / (int)pow(10, i) % 10;
            if (c == -1 && k != 9) {
                c = k;
                l = l + (9 - k) * pow(10, i);
                continue;
            }
            
            if (c == k) {
                l = l + (9 - k) * pow(10, i);
            }
        }
        
        c = -1;
        int d = 1;
        int mark = -1;
        
        for (int i = cbit-1; i >= 0; --i) {
            int k = r / (int)pow(10, i) % 10;
            if (c == -1) {
                if (i == cbit - 1) {
                    if (k == 1) {
                        mark = 1;
                        continue;
                    }
                    c = k;
                    r = r - (k - 1) * pow(10, i);
                    d = 1;
                    continue;
                } else {
                    if (k == 0 || (k == 1 && mark == 1)) continue;
                    c = k;
                    d = 0;
                    r = r - k * pow(10, i);
                    continue;
                }
            }
            
            if (c == k) {
                r = r - (k - d) * pow(10, i);
            }
        }
        return l-r;
    }
};