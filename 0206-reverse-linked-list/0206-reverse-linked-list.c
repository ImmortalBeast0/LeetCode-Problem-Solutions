/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
struct ListNode* reverseList(struct ListNode* head) {

    if(head == NULL || head ->next == NULL)
        return head ;

    struct ListNode * pre = NULL;
    struct ListNode * cur = head ;
    struct ListNode * fwd = NULL ;

    while(cur != NULL){
        fwd = cur ->next ;
        cur -> next = pre ;
        pre = cur ;
        cur  = fwd ;
}

return pre ;

}