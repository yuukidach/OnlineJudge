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
    TreeNode* consTree(vector<int> &pre, vector<int> &mid, int l, int r) {
        if (l > r) return NULL;
        if (pre.empty()) return NULL;

        TreeNode *p;

        p = new TreeNode(pre[0]);
        int idx;
        for (idx = l; idx <= r; ++idx) {
            if (mid[idx] == pre[0]) break; 
        }
        pre.erase(pre.begin());
        p->left = consTree(pre, mid, l, idx-1);
        p->right = consTree(pre, mid, idx+1, r);

        return p;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        TreeNode *res;

        res = consTree(preorder, inorder, 0, inorder.size()-1);

        return res;
    }
};
