/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode *pre = new ListNode(0, head);
        ListNode *p = pre;
        for (int i = 1; i < left; ++i) {
            p = p->next;
        }
        head = p->next;
        for (int i = left; i < right; ++i) {
            ListNode *tmp = head->next;
            head->next = tmp->next; 
            tmp->next = p->next;
            p->next = tmp;
        }

        return pre->next;
    }
};