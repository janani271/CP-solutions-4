#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 205

ll MOD=1e9+7;

ll n,c,i,dp[MAX],visited[MAX];
string s , d , t;
vll g[MAX];
map<string,ll>m;

ll add(ll a,ll b)
{
	return ((a%MOD) + (b%MOD))%MOD;
}
ll mul(ll a,ll b)
{
	return ((a%MOD) * (b%MOD))%MOD;
}
ll sub(ll a,ll b)
{
	return ((a%MOD) - (b%MOD) + MOD)%MOD;
}

void dfs(ll x)
{
	visited[x]=1;
	for(auto it : g[x])
	{
		if(!visited[it])
		{
			dfs(it);
			dp[x] = max(dp[x],dp[it]);
		}
	}
	dp[x] += 1;	
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n;
	c=1;
	for(i=0;i<n;i++)
	{
		cin>>s;
		cin>>d;
		cin>>t;
		transform(s.begin(), s.end(), s.begin(), ::tolower);
		// s = tolower(s);
		// t = tolower(t);
		transform(t.begin(), t.end(), t.begin(), ::tolower);
		if(m[t]==0) m[t] = c++;
		if(m[s]==0) m[s] = c++;
		g[m[t]].pb(m[s]);
	}

	// for(auto it:m)
	// {
	// 	cout<<it.first<<" : "<<it.second<<"\n";
	// }

	// for(i=1;i<=n+1;i++)
	// {
	// 	for(auto it:g[i]) cout<<it<<" "; cout<<"\n";
	// }
	dfs(1);
	cout<<dp[1];
	return 0;
}