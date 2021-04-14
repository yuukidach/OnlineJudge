/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    vector<int> nums;

    void dfs(TreeNode *root) {
        if (root == nullptr) return;
        
        nums.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }

public:
    int minDiffInBST(TreeNode* root) {
        int res = INT_MAX;
        dfs(root);
        sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i) {
            res = min(res, nums[i] - nums[i-1]);
        }

        return res;
    }
};