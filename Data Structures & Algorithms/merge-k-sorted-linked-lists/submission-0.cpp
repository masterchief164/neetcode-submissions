#include <vector>
#include <limits> // Required for INT_MAX

/**
 * Definition for singly-linked list.
 * struct ListNode {
 * int val;
 * ListNode *next;
 * ListNode() : val(0), next(nullptr) {}
 * ListNode(int x) : val(x), next(nullptr) {}
 * ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        // Dummy head to simplify adding the first node.
        ListNode* head = new ListNode(0);
        // Tail pointer to build the new list.
        ListNode* tail = head;

        while (true) {
            int minVal = INT_MAX;
            int minIndex = -1; // Index of the list with the minimum node.

            // 1. Find the node with the smallest value among all list heads.
            for (int i = 0; i < lists.size(); ++i) {
                if (lists[i] != nullptr && lists[i]->val < minVal) {
                    minVal = lists[i]->val;
                    minIndex = i;
                }
            }

            // 2. If no node was found, all lists are empty, so we're done.
            if (minIndex == -1) {
                break;
            }

            // 3. Append the minimum node to the result list.
            tail->next = lists[minIndex];
            tail = tail->next;

            // 4. IMPORTANT: Advance the head of the list from which we took the node.
            lists[minIndex] = lists[minIndex]->next;
        }

        ListNode* result = head->next;
        delete head; // Clean up the dummy node.
        return result;
    }
};