class Solution {
public:
    int min(int a, int b) {
        return a < b ? a : b;
    }
    
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            vector<int> res(2, -1);
            return res;
        }

        int left = -1, right = -1;
        int l = 0, r = nums.size();

        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) {
                r = mid;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        if (nums[min(l, nums.size()-1)] != target) left = -1;
        else left = l;

        l = 0; 
        r = nums.size();
        while (l < r) {
            int mid = (l + r) >> 1;
            if (nums[mid] == target) {
                l = mid + 1;
            } else if (nums[mid] < target) {
                l = mid + 1;
            } else {
                r = mid;
            }
        }

        if (nums[max(r-1, 0)] != target) right = -1;
        else right = r-1;

        vector<int> res;
        res.push_back(left);
        res.push_back(right);
        
        return res;
    }
};