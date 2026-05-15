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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ansHead = new ListNode();
        ListNode* curr = ansHead;
        int carry = 0;
        while(l1 && l2) {
            int res = l1->val + l2->val + carry;
            carry = res / 10;
            res %= 10;
            l1 = l1->next;
            l2 = l2->next;
            ListNode* val = new ListNode(res);
            curr->next = val;
            curr = curr ->next;
        }
        while(l1) {
            int res = l1->val + carry;
            carry = res / 10;
            res %= 10;
            l1 = l1->next;
            ListNode* val = new ListNode(res);
            curr->next = val;
            curr = curr ->next;
        }
        while(l2) {
            int res = l2->val + carry;
            carry = res / 10;
            res %= 10;
            l2 = l2->next;
            ListNode* val = new ListNode(res);
            curr->next = val;
            curr = curr ->next;
        }
        if(carry) {
            ListNode* val = new ListNode(carry);
            curr->next = val;
            curr = curr ->next;
        }
        return ansHead->next;
    }
};
