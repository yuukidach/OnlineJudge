class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int len = tasks.size();

        vector<int> state(26);
        for(auto &task : tasks) state[task-'A']++;
        sort(state.begin(), state.end(), greater<>());

        int cnt = 0;
        for(int i = 0; i < 25; ++i) {
            if (state[i] != state[0]) break;
            cnt++;
        }

        return max((state[0]-1)*(n+1) + cnt, len);
    }
};