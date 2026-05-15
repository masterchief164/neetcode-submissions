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
    void reorderList(ListNode* head) {
        ListNode* fast = head->next;
        ListNode* slow = head;

        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* l1 = head;
        ListNode* l2 = reverseLL(slow->next);

        slow->next = nullptr;

        while(l2){
            ListNode* t1 = l1->next;
            ListNode* t2 = l2->next;

            l1->next = l2;
            l2->next = t1;

            l1 = t1;
            l2=t2;
        }
    }

    ListNode* reverseLL(ListNode* start){
        ListNode* curr = start;
        ListNode* prev = nullptr;
        while(curr){
            ListNode* next = curr ->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
};
