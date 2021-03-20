class Solution {
public:
    int s2i(string s) {
        int i = 0, flag = 1;
        for (auto c : s) {
            if (c == '-') {
                flag = -1;
                continue;
            }
            i = i * 10 - '0' + c;
        }
        return i * flag;
    }

    int evalRPN(vector<string>& tokens) {
        stack<int> nums;
        for (auto &token : tokens) {
            if (token == "+") {
                int num = nums.top(); nums.pop();
                nums.top() += num;
            } else if (token == "-") {
                int num = nums.top(); nums.pop();
                nums.top() -= num;
            } else if (token == "*") {
                int num = nums.top(); nums.pop();
                nums.top() *= num;
            } else if (token == "/") {
                int num = nums.top(); nums.pop();
                nums.top() /= num;
            } else {
                nums.push(s2i(token));
            }
        }
        return nums.top();
    }
};