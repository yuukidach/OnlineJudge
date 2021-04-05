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
    TreeNode* convertBiNode(TreeNode* root) {
        if (root == NULL) return NULL;
        
        TreeNode *head = convertBiNode(root->left);
        if (head == NULL) head = root;
        else {
            TreeNode *node = head;
            while (node->right != NULL) node = node->right;
            node->right = root;
        }
        root->left = NULL;
        root->right = convertBiNode(root->right);

        return head;
    }
};