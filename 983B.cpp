#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 5005

ll MOD=1e9+7;

ll n,a[MAX],dp[MAX][MAX],q,l,r; 

void calc_xor()
{
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n-i;j++)
		{
			if(j==i+j)
				dp[j][i+j] = a[j];
			else
				dp[j][i+j] = dp[j][i+j-1]^dp[j+1][i+j];
		}
	}

	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<n-i;j++)
		{
			if(j==i+j) continue;
			dp[j][i+j] = max(dp[j][i+j],max(dp[j][i+j-1],dp[j+1][i+j]));
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
	for(ll i=0;i<n;i++)
	{
		cin>>a[i];
	}
	memset(dp,0,sizeof dp);
	calc_xor();
	// max_xor();

	cin>>q;
	for(ll i=0;i<q;i++)
	{
		cin>>l>>r;
		cout<<dp[l-1][r-1]<<"\n";
	}
	return 0;
}