#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 300003

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll n,m,i,dp[MAX],u,v,w,mx,len,temp[MAX],j;
vector<pairs> edges[MAX];

int main()
{
	//this problem is like LIS. dp[i] stores the length of the longest path that ends at node i
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		edges[w].push_back({u,v});
	}

	for(i=0;i<MAX;i++)
	{
		len = edges[i].size();
		for(j=0;j<len;j++)
		{
			u = edges[i][j].first; v = edges[i][j].second;
			temp[v]=0;
		}
		for(j=0;j<len;j++)
		{
			u = edges[i][j].first; v = edges[i][j].second;
			temp[v]=max(temp[v],dp[u]+1);
		}
		for(j=0;j<len;j++)
		{
			u = edges[i][j].first; v = edges[i][j].second;
			dp[v]=max(dp[v],temp[v]);
			mx = max(mx,dp[v]);
		} 
	}

	cout<<mx;
	return 0;
}