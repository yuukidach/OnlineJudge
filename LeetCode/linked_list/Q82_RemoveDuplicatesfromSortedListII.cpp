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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *res = new ListNode(101, head);
        head = res;
        ListNode *left, *right;
        int pre = 101;

        while (head->next != nullptr) {
            left = head->next;
            right = left;
            while (right->next != nullptr && right->next->val == left->val) {
                right = right->next;
            }
            if (left == right) head = head->next;
            else {
                head->next = right->next;
            }
        }

        return res->next;
    }
};