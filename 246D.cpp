#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 100003
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

ll n,edges,i,c[MAX],u,v,visited[MAX];
vll g[MAX];
map<ll,set<ll>>m;

void dfs(ll x)
{
	visited[x]=1;
	for(auto it:g[x])
	{
		if(c[it]!=c[x]) m[c[x]].insert(c[it]);
		if(!visited[it]) dfs(it);
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>edges;
	for(i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	for(i=0;i<edges;i++)
	{
		cin>>u>>v;
		g[u].pb(v); g[v].pb(u);
	}
	for(i=1;i<=n;i++)
	{
		if(!visited[i]) dfs(i);
	}
	ll color = c[1];
	for(i=1;i<=n;i++)
	{	
		if(m[c[i]].size() > m[color].size())
		{
			color = c[i];
		}
		else if(m[c[i]].size()==m[color].size() && c[i]<color)
		{
			color = c[i];
		}
	}
	cout<<color;
	return 0;
}