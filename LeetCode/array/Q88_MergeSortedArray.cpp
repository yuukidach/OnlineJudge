class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> nums3 = nums1;
        int l = 0, r = 0, cnt = 0;
        while (l < m && r < n) {
            if (nums3[l] < nums2[r]) {
                nums1[cnt++] = nums3[l++];
            } else {
                nums1[cnt++] = nums2[r++];
            }
        }

        while (l < m) nums1[cnt++] = nums3[l++];
        while (r < n) nums1[cnt++] = nums2[r++];
    }
};