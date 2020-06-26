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
    ListNode* removeDuplicateNodes(ListNode* head) {
        if (head == NULL) return head;

        unordered_set<int> s;
        ListNode *pre = head;
        ListNode *p = head->next;
        s.insert(pre->val);

        while (p != NULL) {
            if (s.count(p->val) == 0) {
                s.insert(p->val);
                pre = p;
                p = p->next;
            } else {
                pre->next = p->next;
                p = p->next;
            }
        }

        return head;
    }
};