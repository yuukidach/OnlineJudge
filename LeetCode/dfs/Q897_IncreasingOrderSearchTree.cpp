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
public:
    TreeNode *res;

    TreeNode* increasingBST(TreeNode* root) {
        res = new TreeNode();
        TreeNode *ans = res;
        dfs(root);
        return ans->right;
    }

    void dfs(TreeNode *node) {
        if (node == nullptr) return;

        dfs(node->left);

        node->left = nullptr;
        res->right = node;
        res = node;

        dfs(node->right);
    }
};