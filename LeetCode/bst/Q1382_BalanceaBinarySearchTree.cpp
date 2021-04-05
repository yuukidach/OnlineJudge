/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    vector<int> nums;

    void getInorder(TreeNode *root) {
        if (root == NULL) return;

        getInorder(root->left);
        nums.push_back(root->val);
        getInorder(root->right);
    }

    TreeNode* createBBST(int l, int r) {
        if (l >= r) return NULL;

        int m = (l + r) >> 1;
        TreeNode *node = new TreeNode(nums[m]);
        node->left = createBBST(l, m);
        node->right = createBBST(m+1, r);
        return node;
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        getInorder(root);
        return createBBST(0, nums.size());
    }
};