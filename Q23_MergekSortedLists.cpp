/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int len = lists.size();
        vector<int> mid;
        for (int i = 0; i < len; ++i) {
            while(lists[i] != NULL) {
                mid.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
        }

        sort(mid.begin(), mid.end(), [](int a, int b) {
            return a < b;
        });

        ListNode *res, *ans;
        res = new ListNode(0);
        ans = res;
        len = mid.size();
        for (int i = 0; i < len; ++i) {
            ListNode *p = new ListNode(mid[i]);
            res->next = p;
            res = res->next;
        }

        return ans->next;
    }
};