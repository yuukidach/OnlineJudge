class Solution {
public:
    int calculate(string s) {
        stack<long> nums;
        stack<char> ops;

        int i = 0, n = s.size();
        while (i < n) {
            long num = 0;
            int flag = 0;
            while (i < n && s[i] >= '0' && s[i] <= '9') {
                num = num * 10 + s[i] - '0';
                i++;
                flag = 1;
            }

            if (flag) {
                if (!ops.empty() && ops.top() == '*') {
                    num = num * nums.top(); nums.pop();
                    ops.pop();
                } else if (!ops.empty() && ops.top() == '/') {
                    num = nums.top() / num; nums.pop();
                    ops.pop();
                } else if (!ops.empty() && ops.top() == '-') {
                    num = -num;
                    ops.pop();
                    ops.push('+');
                }
                nums.push(num);
                continue;
            }

            if (s[i] != ' ') {
                ops.push(s[i]);
            }
            ++i;
        }

        int res = 0;
        while (!nums.empty()) {
            res += nums.top();
            nums.pop();
        }

        return res;
    }
};