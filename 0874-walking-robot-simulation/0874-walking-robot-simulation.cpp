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
class Solution {
public:


    int dist = 0;
    pi move(int x ,int y ,int c ,int i ,set<pi> &ob){
        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};
        for(int k=0;k<c;k++){
            int nx = x + dx[i-1];
            int ny = y + dy[i-1];
            if(ob.find({nx,ny}) != ob.end())
                break;
            x = nx;
            y = ny;
            dist = max(dist,x*x + y*y);
        }

        return {x,y};
    }

    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {

        dist = 0;
        pi cur = {0,0};
        int i = 1;
        set<pi> ob;
        for(vector<int> v : obstacles){
            ob.insert({v[0],v[1]});
        }
        for(int c : commands){
            if(c >= 1 && c <= 9){
                cur = move(cur.F,cur.S,c,i,ob);
            }else{
                if(c == -2){
                    i -= 1;
                    if(i <= 0)
                        i = 4;
                }else{
                    i += 1;
                    if(i > 4)
                        i = 1;
                }
            }
        }

        return dist;
    }
};