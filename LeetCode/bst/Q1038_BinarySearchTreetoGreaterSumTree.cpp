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
    int calulate(TreeNode *root, int cnt) {
        if (root == nullptr) return cnt;
        
        root->val += calulate(root->right, cnt);
        cnt = root->val;
        return calulate(root->left, cnt);
    }

    TreeNode* bstToGst(TreeNode* root) {
        calulate(root, 0);
        return root;
    }
};