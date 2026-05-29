class Solution {
public:

    struct node{
        int child[10];
        bool isEnd;
        node(){
            isEnd = 0;
            memset(child,-1,sizeof(child));
        }
    };

    vector<node> trie;
    void insert(string s){
        if(trie.size() <= 0)
            trie.push_back(node());

        int cur = 0;
        for(int i=0;i<s.length();i++){
            int id = s[i] - '0';
            if(trie[cur].child[id] == -1){
                trie[cur].child[id] = trie.size();
                trie.push_back(node());
            }
            cur = trie[cur].child[id];
        }
        trie[cur].isEnd = true;
    }
    
    int commonPrefix(string t){
        int cur = 0 ,i;
        for(i=0;i<t.length();i++){
            int id = t[i] - '0';
            if(trie[cur].child[id] == -1){
                break;
            }
            cur = trie[cur].child[id];
        }

        return i;
    }

    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        for(int x : arr1)
            insert(to_string(x));
        int sol_len = 0;
        for(int x : arr2)
            sol_len = max(sol_len,commonPrefix(to_string(x)));
        
        return sol_len;
    }
};