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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* prev = nullptr;
        ListNode* curr = head;
        int cnt = 0;
        int len = 0;
        while(curr){
            curr = curr ->next;
            len++;
        }
        curr = head;
        n = len - n;
        if(n == 0) return head->next;
        while(cnt !=n){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        return head;
    }
};
