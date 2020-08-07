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
    ListNode* reverseKGroup(ListNode* head, int k) {
        int len = 0;
        ListNode *p = head;
        while (p != NULL) {
            len++;
            p = p->next;
        }

        ListNode a(0);
        a.next = head;

        p = head;
        ListNode *h, *t = &a;
        
        while (len >= k) {
            len -= k;
            h = p;
            for (int i = 0; i < k-1; ++i) {
                ListNode *tmp = p->next;
                p->next = p->next->next;
                tmp->next = h;
                h = tmp;
            }
            t->next = h;
            t = p;
            p = p->next;
        }

        return a.next;
    }
};