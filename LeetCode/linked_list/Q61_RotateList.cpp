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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *p = head, *pre;
        int len = 0;

        while (p != nullptr) {
            len++;
            p = p->next;
        }
        
        if (len <= 1 || k % len == 0) return head;
        k = len - k % len;

        p = head;
        for (int i =0; i < k; ++i) {
            pre = p;
            p = p->next;
        } 
        pre->next = nullptr;
        ListNode *res = p;
        while (p->next != nullptr) p = p->next;
        p->next = head;

        return res;
    }
};