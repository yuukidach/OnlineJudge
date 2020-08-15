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
    int countNodes(TreeNode* root) {
        int lv = 1;
        if (root == NULL) return 0;
        queue<TreeNode *> q;
        q.emplace(root);

        while (!q.empty()) {
            TreeNode *node = q.front();
            q.pop();
            if (node->left != NULL) {
                q.emplace(node->left);
                lv++;
            }
            if (node->right != NULL) {
                q.emplace(node->right);
                lv++;
            }
        }

        return lv;
    }
};