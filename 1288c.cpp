#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll MOD = 1e9+7;

ll n , m , i , j , dp[1005][25];

int main()
{
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	fastread;

	cin>>n>>m;
	for(i=1;i<=n;i++)
	{
		dp[i][1] = i;
	}
	m *= 2;
	for(i=1;i<=m;i++)
	{
		dp[1][i]=1;
	}
	for(i=2;i<=n;i++)
	{
		for(j=2;j<=m;j++)
		{
			// cout<<dp[i][j-1]<<" "<<dp[i-1][j]<<"\n";
			dp[i][j] = (dp[i][j-1] + dp[i-1][j])%MOD;
		}
	}
	cout<<dp[n][m];
	return 0;
}