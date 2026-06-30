#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod ((int)1e9+7)


#define vi vector<int>
#define vii vector<vi>
#define pi pair<ll,ll>
#define vpi vector<pi>

#define pb push_back
#define bp pop_back
#define F first
#define S second 
#define all(x) x.begin(),x.end()

struct node{
    int child[26];
    int endVal;
    node(){
        for(int i=0;i<26;i++)
            child[i] = -1;
        endVal = 0;
    }
};

struct Trie{
    vector<node> root;
    Trie(){
        root.push_back(node());
    }
    void insert(string& s ,int val){
        int idx = 0;
        for(char c : s){
            int id = c - 'a';
            if(root[idx].child[id] == -1){
                root[idx].child[id] = root.size();
                root.push_back(node());
            }
            idx = root[idx].child[id];
        }
        root[idx].endVal = val;
    }

    int dfs(int u){
        
        int ans = root[u].endVal;
        for(int i=0;i<26;i++){
            if(root[u].child[i] != -1)
                ans += dfs(root[u].child[i]);
        }

        return ans;
    }

    int prefixVal(string& s){

        int idx = 0;
        for(char c : s){
            int id = c - 'a';
            if(root[idx].child[id] == -1)
                return 0;
            idx = root[idx].child[id];
        }

        return dfs(idx);
    }
};

class MapSum {
public:
    Trie trie;
    MapSum() {
        trie = Trie();
    }
    
    void insert(string key, int val) {
        trie.insert(key,val);
    }
    
    int sum(string prefix) {
        return trie.prefixVal(prefix);
    }
};