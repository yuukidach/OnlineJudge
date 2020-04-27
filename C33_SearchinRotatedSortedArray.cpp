class Solution {
public:
    int search(vector<int>& nums, int target) {
        int res = -1;
        int len = nums.size();
        int l = 0, r = len - 1;
        while (l < r) {
            int mid = l + r >> 1;
            if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && nums[mid] >= target) {
                    r = mid;
                    break;
                }
                l = mid + 1;
            } else {
                if (nums[mid] <= target && nums[r] >= target) {
                    l = mid;
                    break;
                }
                r = mid - 1;
            }
        }

        while (l <= r) {
            int mid = l + r >> 1;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) l  = mid + 1;
            else r = mid - 1;
        }

        return res;
    }
};