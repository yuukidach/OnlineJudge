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
    bool isValidBST(TreeNode* root) {
        if (root == NULL) return true;

        stack<TreeNode*> q;
        q.push(root);
        int b = INT_MIN;
        int m = 0;
        while (!q.empty()) {
            TreeNode *t= q.top();
            if (t->left != NULL) {
                q.push(t->left);
                t->left = NULL;
                continue;
            }

            if (!m) {
                b = t->val;
                m = 1;
            } else {
                if (t->val <= b) return false;
                b = t->val;
            }
            q.pop();

            if (t->right != NULL) {
                q.push(t->right);
                t->right = NULL;
                continue;
            }
        }

        return true;
    }
};