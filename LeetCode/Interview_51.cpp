class Solution {
public:
    int sort2cnt(vector<int> &nums, vector<int> &s, int l, int r) {
        if (l >= r) return 0;

        int mid = (l + r) >> 1;
        int i = l, j = mid + 1;
        int cnt = sort2cnt(nums, s, l, mid) + sort2cnt(nums, s, j, r);
        int pos = l;
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                s[pos] = nums[i++];
                cnt += j - mid - 1;
            } else {
                s[pos] = nums[j++];
            }
            pos++;
        }
        for (int k = i; k <= mid; ++k) {
            s[pos++] = nums[k];
            cnt += j - mid - 1;
        }
        for (int k = j; k <= r; ++k) {
            s[pos++] = nums[k];
        }

        copy(s.begin()+l, s.begin()+r+1, nums.begin()+l);
        return cnt;
    }

    int reversePairs(vector<int>& nums) {
        int len = nums.size();
        vector<int> s(len);
        return sort2cnt(nums, s, 0, len-1);
    }
};