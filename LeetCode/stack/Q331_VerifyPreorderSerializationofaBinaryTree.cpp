class Solution {
public:
    bool isValidSerialization(string preorder) {
        stack<int> s; s.push(1);
        int len = preorder.size();

        for (int i = 0; i < len;) {
            if (s.empty()) return false;
            int flag = 0;
            while (preorder[i] >= '0' && preorder[i] <= '9') {
                ++i;
                flag = 1;
            }

            if (flag) {
                s.top()--;
                if (s.top() == 0) s.pop();
                else if (s.top() < 0) return false;
                s.push(2);
                continue;
            }
            
            if (preorder[i] == '#') {
                s.top()--;
                if (s.top() == 0) s.pop();
                else if (s.top() < 0) return false;
            }
            ++i;
        }

        if (!s.empty()) return false;

        return true;
    }
};