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
    int max_val = INT_MIN;

    int path_sum(TreeNode *n) {
        if (n == NULL) return 0;

        int root_val = n->val;
        int left_val = path_sum(n->left);
        int right_val = path_sum(n->right);

        int sum = 0;
        if (left_val > 0) sum += left_val;
        if (right_val > 0) sum += right_val;
        sum += root_val;

        max_val = max(max_val, sum);
        int ret_val = right_val > left_val ? right_val : left_val;
        if (ret_val < 0) ret_val = root_val;
        else ret_val += root_val;
        return ret_val;
    }

    int maxPathSum(TreeNode* root) {
        path_sum(root);
        return max_val;
    }
};