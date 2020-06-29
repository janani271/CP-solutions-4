#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 200003

ll MOD=1e9+7;
ll n , i , u , v, dp[MAX],visited[MAX],mi;
vector<pairs> g[MAX];

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
	dp[x]=0;
	for(auto it:g[x])
	{
		if(!visited[it.first])
		{
			dfs(it.first);
			dp[x] += (dp[it.first] + it.second);
		}
	}
}

void dfs1(ll x)
{
	visited[x]=1;
	for(auto it:g[x])
	{
		if(visited[it.first])
		{
			ll temp = dp[it.first];
			temp -= dp[x];
			temp -= (1-it.second);
			temp += it.second;
			dp[x] += temp;
		}
	}
	for(auto it:g[x])
	{
		if(!visited[it.first])
			dfs1(it.first);
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
		u--; v--;
		g[u].pb({v,0});
		g[v].pb({u,1});
	}
	
	dfs(0);
	memset(visited,0,sizeof visited);
	dfs1(0);
	
	mi = dp[0];
	for(i=1;i<n;i++)
		mi = min(mi,dp[i]);

	cout<<mi<<"\n";
	for(i=0;i<n;i++)
	{
		if(dp[i]==mi)
			cout<<i+1<<" ";
	}
	return 0;
}