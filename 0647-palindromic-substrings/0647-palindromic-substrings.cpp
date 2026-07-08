class Solution {
public:

    struct Manacher{
        vector<int> p;
        void init(string s){
            string t;
            for(char c : s)
                t += '#' ,t += c;
            t += '#';
            build(t);
        }
        void build(string t){
            int n = t.size();
            p.resize(n,1);
            int l = 1 ,r = 1;
            for(int i=1;i<n;i++){
                if(i < r)
                    p[i] = max(0,min(r-i,p[l + (r - i)]));
                while(i - p[i] >= 0 && i + p[i] < n && t[i-p[i]] == t[i+p[i]])
                    p[i] += 1;
                if(i + p[i] > r){
                    l = i - p[i];
                    r = i + p[i];
                }
            }
        }

        int get(){
            int sol = 0;
            for(int i=0;i<p.size();i+=1){
                sol += (p[i])/2;
            }

            return sol;
        }
    }m;

    int countSubstrings(string s) {
        m.init(s);
        return m.get();
    }
};