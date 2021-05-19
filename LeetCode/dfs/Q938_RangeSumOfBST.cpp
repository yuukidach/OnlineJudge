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
public:
    int dfs(TreeNode* root, int l, int r) {
        int sum = 0;

        if (root == NULL) return 0;

        if (root->val >= l && root->val <= r) {
            sum += root->val;
        }

        sum += dfs(root->left, l, r);
        sum += dfs(root->right, l, r);

        return sum;
    }

    int rangeSumBST(TreeNode* root, int L, int R) {
        int sum = dfs(root, L, R);
        return sum;
    }
};