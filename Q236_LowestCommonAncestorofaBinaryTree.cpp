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
    bool findNode(TreeNode* root, TreeNode* p, vector<TreeNode*> &v) {
        if (root == p) {
            v.push_back(p);
            return true;
        } else if (root == NULL) return false;

        bool res = findNode(root->left, p, v) || findNode(root->right, p, v);
        if (res) {
            v.push_back(root);
            return true;
        }

        return false;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> vp, vq;
        findNode(root, p, vp);
        findNode(root, q, vq);
        reverse(vp.begin(), vp.end());
        reverse(vq.begin(), vq.end());

        int len = min(vp.size(), vq.size());
        TreeNode* last = root;
        for (int i = 1; i < len; ++i) {
            if (vp[i] == vq[i]) last = vp[i];
            else break;
        }

        return last;
    }
};