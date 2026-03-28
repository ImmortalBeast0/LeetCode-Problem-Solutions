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

class Solution {
public:
    int n;

    string findTheString(vector<vector<int>>& lcp){
        
        n = lcp.size();
        string word(n,'\0');

        char cur = 'a';

        for(int i=0;i<n;i++){
            if(word[i] == '\0'){

                if(cur > 'z')
                    return "";

                word[i] = cur;
                for(int j=i+1;j<n;j++){
                    if(lcp[i][j] > 0)
                        word[j] = word[i];
                }

                cur++;
            }
        }

        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){

                if(word[i] != word[j]){
                    if(lcp[i][j])
                        return "";
                }
                else{
                    if(i == n-1 || j == n-1){
                        if(lcp[i][j] != 1)
                            return "";
                    }else
                        if(lcp[i][j] != lcp[i+1][j+1] + 1)
                            return "";
                }
            }
        }

        return word;
    }
};