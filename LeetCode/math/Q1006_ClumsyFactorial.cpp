class Solution {
public:
    const char *OP = "*/+-";

    int clumsy(int N) {
        if (N == 1) return 1;

        stack<int> nums;
        stack<char> ops;
        int cnt = 0;

        for (int i = N; i >= 1; --i) {
            if (!ops.empty() && ops.top() == '*') {
                nums.top() *= i;
                ops.pop();
            } else if (!ops.empty() && ops.top() == '/') {
                nums.top() /= i;
                ops.pop();
            } else if (!ops.empty() && ops.top() == '-') {
                nums.push(-i);
                ops.top() = '+';
            } else {
                nums.push(i);
            }
            ops.push(OP[cnt & 0b11]);
            cnt++;
        }

        ops.pop();

        while (nums.size() > 1) {
            int num = nums.top();
            nums.pop();
            nums.top() += num;
        }

        return nums.top();
    }
};