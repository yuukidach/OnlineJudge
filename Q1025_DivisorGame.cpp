class Solution {
public:
    bool divisorGame(int N) {
        if ((N & 1) == 0) {
            return true;
        }
        return false;
    }
};