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
    ListNode* partition(ListNode* head, int x) {
        ListNode *shead, *lhead, *sp, *lp;
        shead = new ListNode(0);
        lhead = new ListNode(0);
        sp = shead;
        lp = lhead;

        while (head != NULL) {
            if (head->val < x) {
                sp->next = head;
                sp = sp->next;
            } else {
                lp->next = head;
                lp = lp->next;
            }

            head = head->next;
        }

        sp->next = lhead->next;
        lp->next = NULL;
        return shead->next;
    }
};