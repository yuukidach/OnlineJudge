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
    void dfs(TreeNode *root, vector<int> &res, int cnt) {
        if (root == NULL) return;
        if (cnt > res.size()) {
            res.push_back(root->val);
        }

        cnt++;
        dfs(root->right, res, cnt);
        dfs(root->left, res, cnt);
    }

    vector<int> rightSideView(TreeNode* root) {
        TreeNode *p;
        vector<int> res;
        
        dfs(root, res, 1);

        return res;
    }
};