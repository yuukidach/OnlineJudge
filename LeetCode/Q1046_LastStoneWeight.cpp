class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end(), greater());
            int des = abs(stones[0] - stones[1]);
            stones.erase(stones.begin());
            stones.erase(stones.begin());
            if (des != 0) stones.emplace_back(des);
        }

        if (stones.size() == 0) return 0;
        return stones[0];
    }
};