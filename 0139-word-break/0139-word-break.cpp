class Solution {
public:

    struct node{
        int isEnd;
        node* child[26];
        node(){
            isEnd = 0;
            for(int i=0;i<26;i++)
                child[i] = nullptr;
        }
    };

    struct Trie{
        map<pair<int,node*>,bool> dp;
        node* root;
        Trie(){
            root = new node();
        }
        void insert(string& s){
            node* cur = root;
            for(char c : s){
                int id = c - 'a';
                if(cur->child[id] == nullptr)
                    cur->child[id] = new node();
                cur = cur->child[id];
            }
            cur->isEnd++;
        }
        
        bool rec(string& s){
            return rec(0,root,s);
        }
        bool rec(int i ,node* cur ,string& s){
            int id = s[i] - 'a';
            if(i == s.length()-1){
                if(cur->child[id] != nullptr && cur->child[id]->isEnd)
                    return true;
                return false;
            }

            if(dp.find(make_pair(i,cur)) != dp.end())
                return dp[make_pair(i,cur)];

            if(cur->child[id] != nullptr){
                if(cur->child[id]->isEnd){
                    if(rec(i+1,root,s))
                        return true;
                }
                if(rec(i+1,cur->child[id],s))
                    return true;
            }

            return dp[make_pair(i,cur)] = false;
        }

    };

    bool wordBreak(string s, vector<string>& wordDict) {
        Trie t =  Trie();
        for(string s : wordDict)
            t.insert(s);
        return t.rec(s);
    }
};