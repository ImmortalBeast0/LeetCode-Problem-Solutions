/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB){
        ListNode i = headA;
        ListNode j = headB;
        while(i != j){
            i = (i == null) ? headB : i.next;
            j = (j == null) ? headA : j.next;
        }

        return i;
    }
}