#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 100003

ll MOD=1e9+7;
ll visited[MAX],color[MAX],dp[MAX][3],n,i,u;
vll g[MAX];

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
	ll a ,b;
	visited[x]=1;
	dp[x][color[x]]=1;
	for(auto it:g[x])
	{
		// cout<<"it : "<<it<<"\n";
		if(visited[it]) continue;
		dfs(it);
		a = mul(dp[x][0],dp[it][0]);
		b = add(mul(dp[x][0],dp[it][1]),mul(dp[x][1],dp[it][0]));
		//not including edge
		a = add(a,mul(dp[x][0],dp[it][1]));
		b = add(b,mul(dp[x][1],dp[it][1]));

		dp[x][0]=a; dp[x][1]=b;
	}
	// cout<<"x : "<<x<<"\n";
	// cout<<"white :"<<dp[x][0]<<"\tblack : "<<dp[x][1]<<"\n\n";
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
		cin>>u;
		g[u].pb(i+1);
		g[i+1].pb(u);
	}
	for(i=0;i<n;i++)
	{
		cin>>color[i];
	}

	// for(i=0;i<n;i++)
	// {
	// 	for(auto it:g[i]) cout<<it<<" "; cout<<"\n";
	// }
	dfs(0);
	cout<<dp[0][1];
	return 0;
}