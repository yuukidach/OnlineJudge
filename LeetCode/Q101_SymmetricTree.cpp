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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode *> l, r;
        if (root == NULL) return true;
        
        l.push(root->left);
        r.push(root->right);
        if (root->left == NULL && root->right == NULL) return true;
        else if (root->left == NULL || root->right == NULL) return false;
        while (!l.empty()) {
            auto ln = l.front();
            auto rn = r.front();
            l.pop();
            r.pop();

            if (ln->val != rn->val) return false;
            if (ln->left != NULL && rn->right != NULL) {
                l.push(ln->left);
                r.push(rn->right);
            } else if (!(ln->left == NULL && rn->right == NULL)) return false;
            if (ln->right != NULL && rn->left != NULL) {
                l.push(ln->right);
                r.push(rn->left);
            } else if (!(ln->right == NULL && rn->left == NULL)) return false;
        }

        return true;
    }
};