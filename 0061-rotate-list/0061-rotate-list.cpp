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
    ListNode* rotateRight(ListNode* head, int k){
        int n = 0;
        ListNode* cur = head;
        while(cur){n += 1; cur = cur->next;}
        if(n == 0)
            return nullptr;
        k %= n;
        cur = head;
        ListNode* kth = head;
        int cnt = 0;
        while(cur->next){
            cnt += 1;
            cur = cur->next;
            if(cnt > k)
                kth = kth->next;
        }
        cur->next = head;
        ListNode* sol = kth->next;
        kth->next = nullptr;
        return sol;
    }
};