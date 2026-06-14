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
    int pairSum(ListNode* head) {
        
        vector<int> nums;
        for(ListNode* i = head;i;i=i->next){
            nums.push_back(i->val);
        }

        int n = nums.size();
        int ans = 0;
        for(int i=0;i<n/2;i++){
            ans = max(ans,nums[i] + nums[n-i-1]);
        }

        return ans;
    }
};