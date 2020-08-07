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
    bool checkEqual(TreeNode* s, TreeNode* t) {
        if (s == NULL && t == NULL) return true;
        if (s == NULL || t == NULL) return false;
        if (s->val == t->val) {
            return checkEqual(s->left, t->left) && checkEqual(s->right, t->right);
        }
        return false;
    }

    bool isSubtree(TreeNode* s, TreeNode* t) {
        bool res = false;

        if (s == NULL && t == NULL) return true;
        if (s == NULL || t == NULL) return false;
        
        if (s->val == t->val) {
            res = checkEqual(s, t);
        } 
        
        if (res) return res;
    
        res = isSubtree(s->left, t) || isSubtree(s->right, t);
        
        return res;
    }
};