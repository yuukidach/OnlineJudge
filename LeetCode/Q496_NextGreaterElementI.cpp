class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> res(len1);

        for (int i = 0; i < len1; ++i) {
            int mark = 0;
            for (int j = 0; j < len2; ++j) {
                if (mark && nums2[j] > nums1[i]) {
                    res[i] = nums2[j];
                    break;
                }
                if (nums1[i] == nums2[j]) mark = 1;
            }
            if (res[i] == 0) res[i] = -1;
        }

        return res;
    }
};