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
    vector<int> interval_rob(TreeNode *root) {
        vector<int> cnt(2, 0);
        if (root == NULL) return cnt;

        vector<int> a = interval_rob(root->left);
        vector<int> b = interval_rob(root->right);

        cnt[0] = max(a[0], a[1]) + max(b[0], b[1]);
        cnt[1] = root->val + a[0] + b[0];

        return cnt;
    }

    int rob(TreeNode* root) {
        int res = 0;
        vector<int> cnt;

        cnt = interval_rob(root);

        return max(cnt[0],cnt[1]);
    }
};