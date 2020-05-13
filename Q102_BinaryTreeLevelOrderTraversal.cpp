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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        queue<pair<int, TreeNode *>> q;
        vector<int> a;

        int last = 0;
        q.push(make_pair(0, root));
        while (!q.empty()) {
            auto tmp = q.front();
            auto n = tmp.second;
            q.pop();

            if (tmp.first == last) {
                a.push_back(n->val);
            } else {
                res.push_back(a);
                a.clear();
                last = tmp.first;
                a.push_back(n->val);
            }

            if (n->left != NULL) q.push(make_pair(tmp.first+1, n->left));
            if (n->right != NULL) q.push(make_pair(tmp.first+1, n->right));
        }  

        res.push_back(a);

        return res;
    }
};