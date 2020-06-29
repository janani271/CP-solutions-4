#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 2003
#define INF 1000000000000000005

using namespace std;

ll MOD=1e9+7;

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

ll d,n,i,a[MAX],u,v,visited[MAX],dp[MAX],res;
vll g[MAX];

void dfs(ll root, ll x)
{
	visited[x] = 1;
	dp[x] = 1;
	for(auto it:g[x])
	{
		if(visited[it]) continue;
		if(!(a[root]<=a[it] && a[it]<=a[root]+d)) continue;
		if(a[root]==a[it] && it<root) continue;
		dfs(root,it);
		dp[x] = mul(dp[x],dp[it]+1);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>d>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	res=0;
	for(i=1;i<=n;i++)
	{
		memset(dp,0,sizeof dp);
		memset(visited,0,sizeof visited);
		dfs(i,i);
		// cout<<" i : "<<i<<"\tdp : "<<dp[i]<<"\n";
		res = add(res,dp[i]);
	}
	cout<<res;

	return 0;
}
