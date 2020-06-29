#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll int
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 200003
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

ll r,g,sum,h,tot,dp[3][MAX],i,j,res;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>r>>g;
	if(r>g) swap(r,g);

	while(2*(r+g)>=(h*(h+1))) h++;
	h--;
	tot = (h*(h+1))/2;
	
	//dp(i,j) -> no.of ways construct pyramid of height i using j red blocks
	dp[0][0]=1;
	for(i=1;i<=h;i++)
	{
		for(j=0;j<=r;j++)
		{
			dp[i%2][j] = dp[1-(i%2)][j];
			// i%2,j ->using green blocks
			// i%2,j-i ->using red blocks
			if(j>=i) dp[i%2][j] = add(dp[i%2][j],dp[1-(i%2)][j-i]);
		}
	}
	//adding the valid no.of ways of using the red blocks
	res=0;
	for(j=0;j<=r;j++)
	{
		//if out of total blocks needed, j red blocks are used, can the remaining be filled with green
		if(tot-j>g) continue; //if no, not added to answer
		res = add(res,dp[h%2][j]); //if yes, added
	}
	cout<<res;
	return 0;
}