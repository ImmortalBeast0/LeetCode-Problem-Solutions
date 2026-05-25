#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define mod ((int)1e9+7)
#define endl '\n'

#define vi vector<int>
#define vii vector<vi>
#define pi pair<int,int>
#define vpi vector<pi>

#define F first
#define S second
#define pb push_back
#define bp pop_back
#define mp make_pair
#define all(x) x.begin(),x.end()

class Solution {
public:
    int n;
	int static const N = 1e5*2;
	int BIT[N];

	void update(int idx ,int val){
        idx += 1;
		int i = idx;
		while(i < N){
			BIT[i] += val;
			i += (i & (-i));
		}
	}

	int get(int idx){
		int i = idx;
		int ans = 0;
		while(i > 0){
			ans += BIT[i];
			i -= (i & (-i));
		}
		return ans;
	}

	int getRange(int l ,int r){
        l += 1;
        r += 1;
		if(l > r)
			return 0;
		int ans = get(r);
		ans -= get(l-1);
        return ans;
	}

    bool canReach(string s, int minn, int maxx) {
		n = s.length();
        if(s[n-1] != '0')
            return false;
		update(n-1,1);
		for(int i=n-2;i>=0;i--){
            if(s[i] != '0')
                continue;
			int l = i + minn ,r = min(i + maxx,n-1);
			int val = getRange(l,r);
			if(val > 0)
				update(i,1);
		}

		return getRange(0,0) > 0;
    }
};