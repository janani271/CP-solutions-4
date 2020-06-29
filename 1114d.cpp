#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 5005

ll MOD=1e9+7;

ll dp[MAX][MAX],a[MAX],n,i,ans,j,b;

ll color(ll l,ll r)
{
	if(dp[l][r]!=-1)
		return dp[l][r];
	if(l>=r)
		return dp[l][r]=0;

	if(a[l]==a[r]) dp[l][r] = color(l+1,r-1)+1;
	else dp[l][r] = min(color(l,r-1),color(l+1,r))+1;
	
	return dp[l][r];
}


int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n;
	j=0;
	for(i=1;i<=n;i++)
	{
		cin>>b;
		if(i==1 || b!=a[j])
			a[++j] = b;
	}
	n=j;
	memset(dp,-1,sizeof dp);
	ans = color(1,n);
	cout<<ans;

	return 0;
}