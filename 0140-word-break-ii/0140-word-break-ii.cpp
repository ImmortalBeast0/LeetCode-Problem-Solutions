class Solution {
public:
    vector<string> sols;
    set<string> ss;

    bool isExist(string& s){
        return ss.find(s) != ss.end();
    }

    void rec(int i ,string substring ,string sol ,string& s){

        if(i >= s.length()){
            if(isExist(substring)){
                sols.push_back(sol + substring);
            }
            return ;
        }

        rec(i+1,substring + s[i],sol,s);
        if(isExist(substring)){
            rec(i+1,string (1,s[i]),sol + substring + " ",s);
        }

    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {
        
        for(string w : wordDict)
            ss.insert(w);
        cout << s + 'a' << endl;
        rec(0,"","",s);
    
        return sols;
    }
};