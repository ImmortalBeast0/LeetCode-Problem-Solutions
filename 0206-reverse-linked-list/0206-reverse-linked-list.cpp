#include <bits/stdc++.h>
using namespace std;

#define vi vector<int>
#define vii vector<vi>
#define pi pair<int, int>
#define vpi vector<pi>

#define pb push_back
#define bp pop_back
#define mp make_pair

#define F first
#define S second

#define all(x) x.begin(), x.end()
#define sz(x) x.size()

#define mod (1e9) + 7
#define inf 1e9

using ll = long long;


//  struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
//  };
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        ListNode* pre = nullptr;
        ListNode* nxt = nullptr;
        ListNode* curr = head;

        while(curr){
            nxt = curr->next;
            curr->next = pre;
            pre = curr;
            curr = nxt;
        }

        return pre;
    }
};