#include<bits/stdc++.h>
using namespace std;

#define mod (int)1e9+7
#define ll long long

#define vi vector<int>
#define vii vector<vi>
#define pi pair<int,int>
#define vpi vector<pi>

#define pb push_back
#define bp pop_back
#define mp make_pair

#define F first
#define S second 

#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()

#include<bits/stdc++.h>
using namespace std;

#define mod (int)1e9+7
#define ll long long

#define vi vector<int>
#define vii vector<vi>
#define pi pair<int,int>
#define vpi vector<pi>

#define pb push_back
#define bp pop_back
#define mp make_pair

#define F first
#define S second 

#define all(x) x.begin(),x.end()
#define sz(x) (int)x.size()
// struct ListNode {
//      int val;
//      ListNode *next;
//      ListNode() : val(0), next(nullptr) {}
//      ListNode(int x) : val(x), next(nullptr) {}
//      ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

class Solution {
public:

    ListNode* reverseBetween(ListNode* head, int left, int right){
        ListNode* rt = NULL;
        ListNode* lt = NULL;
        ListNode* ltPre = NULL;

        int cnt = 1;
        ListNode* cur = head;
        while(cnt < left && cur->next != nullptr){
            ltPre = cur;
            cur = cur->next;
            cnt += 1;
        }

        lt = cur;
        

        ListNode* pre = ltPre ,*nxt;
        while(cnt <= right && cur != nullptr){
            rt = cur;
            nxt = cur->next;
            cur->next = pre;
            pre = cur;
            cur = nxt;
            cnt += 1;
        }


        lt->next = cur;
        if(ltPre != nullptr)
            ltPre->next = rt;
        else
            head = rt;

        return head;
    }   
};