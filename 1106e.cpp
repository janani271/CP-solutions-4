#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 100003
#define INF 1000000000000000005

using namespace std;

ll n,m,k,i,ss,tt,dd,ww,dp[250][MAX];

struct st
{
	ll d,w;
	bool operator< (const st a) const{
		return (w>a.w || (w==a.w && d>a.d));
	}
}
t[MAX];

map<st,ll>mx;

vector<st> add_eve[MAX], rem_eve[MAX];

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>m>>k;
	for(i=0;i<k;i++)
	{
		cin>>ss>>tt>>dd>>ww;
		add_eve[ss].pb({dd,ww});
		rem_eve[tt+1].pb({dd,ww});
	}

	for(i=1;i<=n;i++)
	{
		for(auto it:add_eve[i])  mx[it]++;
		for(auto it:rem_eve[i])
		{
			mx[it]--;
			if(mx[it]<=0) mx.erase(it);
		}
		if(!mx.empty()) t[i] = (mx.begin()->first);
		else t[i] = {0,0};
	}
	
	for(ll j=0;j<=m;j++)
	{
		for(i=n;i>=1;i--)
		{
			//if not disturbed
			ll d=i, w=0;
			if(t[i].w) w = t[i].w;
			if(t[i].d) d = t[i].d;
			dp[j][i] = w + dp[j][d+1];
			//if disturbed
			if(j) dp[j][i] = min(dp[j][i],dp[j-1][i+1]);
		}
	}
	cout<<dp[m][1];

	return 0;
}