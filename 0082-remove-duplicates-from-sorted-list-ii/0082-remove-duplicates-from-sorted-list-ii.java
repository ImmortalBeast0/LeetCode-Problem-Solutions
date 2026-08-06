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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode dummy = new ListNode(101,head);
        ListNode temp = dummy;
        while(temp != null){
            int val = 101;
            if(temp.next != null && temp.next.next != null && temp.next.val == temp.next.next.val)
                val = temp.next.val;
            boolean flag = true;
            while(val != 101 && temp.next != null && temp.next.val == val){
                temp.next = temp.next.next;
                flag = false;
            }
            if(flag)
                temp = temp.next;
        }

        return dummy.next;
    }
}