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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        int flag = 0;

        if (root == NULL) return res;

        queue<TreeNode *> q, p;
        q.push(root);
        vector<int> v;

        while (!q.empty() || !p.empty()) {
            if (q.empty()) {
                res.push_back(v);
                v.clear();
                swap(q, p);
                continue;
            }

            TreeNode* node = q.front();
            q.pop();
            if (node->left != NULL) p.push(node->left);
            if (node->right != NULL) p.push(node->right);
            v.push_back(node->val);
        }

        res.push_back(v);

        for (int i = 0; i < res.size(); ++i) {
            if (!flag) {
                flag = 1 - flag;
                continue;
            }

            reverse(res[i].begin(), res[i].end());

            flag = 1 - flag;
        }
        
        return res;
    }
};