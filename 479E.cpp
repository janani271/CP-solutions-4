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

ll n,a,b,k,dp[MAX][MAX],p[MAX],i,j,l,r;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>a>>b>>k;

	dp[0][a] = 1;

	for(i=1;i<=k;i++)
	{
		memset(p,0,sizeof p);
		// cout<<"\nstep "<<i<<" : \n";
		for(j=1;j<=n;j++)
		{
			p[j] = add(dp[i-1][j],p[j-1]); //prefix sum for previous step
			// cout<<p[j]<<" ";
		}
		// cout<<"\n";
		for(j=1;j<=n;j++)
		{
			if(a<b && j<b)
			{
				l = 1; 
				r = j + ((b-j)/2) + ((b-j)%2) - 1; //r's dist from j should be less than dist from b 
				dp[i][j] = sub(p[r],p[l-1]);
				dp[i][j] = sub(dp[i][j],dp[i-1][j]);
			}
			if(a>b && j>b)
			{
				l = j - ((j-b)/2) - ((j-b)%2) + 1; //l's dist from j should be less than dist from b
				r = n;
				dp[i][j] = sub(p[r],p[l-1]);
				dp[i][j] = sub(dp[i][j],dp[i-1][j]);
			}
			// cout<<dp[i][j]<<" ";
		}
		// cout<<"\n";
	}
	ll ans=0;
	for(i=1;i<=n;i++)
	{
		ans = add(ans,dp[k][i]); //all the sequences ending at i in the k-th trip
	}
	cout<<ans;
	return 0;
}