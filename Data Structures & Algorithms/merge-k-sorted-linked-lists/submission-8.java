/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length == 0) return null;

        PriorityQueue<ListNode> minHeap = new PriorityQueue<> ((a,b)-> a.val - b.val);

        for(ListNode ele: lists) {
            if(ele != null){
                minHeap.offer(ele);
            }
        }

        ListNode ans = new ListNode(0);
        ListNode curr = ans;

        while(!minHeap.isEmpty()) {
            ListNode top = minHeap.poll();
            curr.next = top;
            curr = curr.next;

            top = top.next;
            if(top!=null) {
                minHeap.offer(top);
            }
        }
        return ans.next;
    }
}
