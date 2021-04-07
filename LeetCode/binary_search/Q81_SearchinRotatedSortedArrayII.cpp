class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int len = nums.size();
        int pos;
        for (pos = 1; pos < len; ++pos) {
            if (nums[pos] < nums[pos-1]) break;
        }

        int l = 0, r = pos;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) return true;
            else if (nums[mid] > target) r = mid;
            else l = mid + 1;
        }

        l = pos;
        r = len;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) return true;
            else if (nums[mid] > target) r = mid;
            else l = mid + 1;
        }

        return false;
    }
};