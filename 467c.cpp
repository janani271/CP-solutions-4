#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 5003
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

ll n,m,k,p[MAX],a,dp[MAX][MAX],i;
ll calc(ll i, ll j)
{
	if(i+m-1 > n) return 0;
	if(dp[i][j]!=-1) return dp[i][j];

	ll x = calc(i+1,j);
	ll y=0;
	if(j>0) y = p[i+m-1]-p[i-1] + calc(i+m,j-1);
	dp[i][j] = max(x,y);
	return dp[i][j];
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;
	
	cin>>n>>m>>k;
	p[0]=0;
	for(i=1;i<=n;i++)
	{
		cin>>a;
		p[i] = p[i-1]+a;
	}
	memset(dp,-1,sizeof dp);
	cout<<calc(1,k);
	return 0;
}