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
    int check(TreeNode *node) {
        int ldep = 0;
        int rdep = 0;
        if (node == NULL) return 0;
        if (node->left != NULL) {
            ldep = check(node->left) + 1;
            if(ldep == 0) return -1;
        }
        if (node->right != NULL) {
            rdep = check(node->right) + 1;
            if (rdep == 0) return -1;
        }
        if (abs(ldep - rdep) > 1) return -1;
        return max(ldep, rdep);
    }

    bool isBalanced(TreeNode* root) {
        if (check(root) == -1) return false;
        return true;
    }
};