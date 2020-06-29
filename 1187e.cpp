#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 200003

ll n,i,u,v,visited[MAX],dp[MAX],sub[MAX],ans;
vll g[MAX];

void dfs(ll x)
{
	visited[x] = 1;
	sub[x] = 1;
	dp[x] = 0;
	for(auto it : g[x])
	{
		if(!visited[it])
		{
			dfs(it);
			sub[x] += sub[it];
			dp[x] += dp[it];
		}
	}
	dp[x] += sub[x];
	// cout<<"x : "<<x+1<<"\n"<<"dp : "<<dp[x]<<"\n"<<"sub : "<<sub[x]<<"\n";
}


void dfs1(ll x)
{
	visited[x] = 1;
	for(auto it:g[x])
	{
		if(visited[it])
		{
			// dp[it] = dp[it] ;
			dp[x] += (dp[it]-dp[x]-sub[x]) + (sub[it]-sub[x]);
			// sub[it] -= sub[x];
			sub[x] += (sub[it]-sub[x]);
		}
	}

	// cout<<"x : "<<x+1<<"\n"<<"dp : "<<dp[x]<<"\n"<<"sub : "<<sub[x]<<"\n----------\n";

	ans = max(ans,dp[x]);
	
	for(auto it:g[x])
	{
		if(!visited[it])
		{
			dfs1(it);
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n;
	for(i=0;i<n-1;i++)
	{
		cin>>u>>v;
		--u; --v;
		g[u].pb(v); g[v].pb(u);
	}
	dfs(0);
	memset(visited,0,sizeof visited);
	ans = dp[0];
	dfs1(0);
	cout<<ans;
	return 0;
}