#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 1003
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

ll n,k,x,pos[MAX][10],i,j,f,len[MAX],visited[MAX],lcs;
vll g[MAX];

void dfs(ll x)
{
	visited[x]=1;
	len[x]=0;
	for(auto it:g[x])
	{
		if(!visited[it]) dfs(it);
		len[x] = max(len[x],len[it]);
	}
	len[x]+=1;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>k;
	for(i=1;i<=k;i++)
	{
		for(j=1;j<=n;j++)
		{
			cin>>x;
			pos[x][i] = j;
		}
	}

	for(i=1;i<=n;i++)
	{
		for(j=1;j<=n;j++)
		{
			if(i==j) continue;
			f=1;
			for(x=1;x<=k;x++)
			{
				if(pos[i][x] > pos[j][x])
				{ f=0; break; }
			}
			if(f) g[i].pb(j);
		}
	}

	lcs=0;
	for(i=1;i<=n;i++)
	{
		if(!visited[i]) dfs(i);
		lcs = max(lcs,len[i]);
	}
	cout<<lcs;
	return 0;
}