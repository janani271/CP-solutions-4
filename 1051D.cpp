#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 1005

ll MOD=998244353;
ll dp[MAX][2*MAX][5];
ll n , k , col , comp , l , sl , i , ans , ncomp;

ll getcomps(ll a,ll b)
{
	if(a==0 || a==3)
	{
		if(b==a) return 0;
		return 1;
	}
	if(a==1)
	{
		if(b==2) return 2;
		return 0;
	}
	if(a==2)
		if(b==1) return 2;
	return 0;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>k;
	
	dp[1][1][0]=1; dp[1][1][3]=1; dp[1][2][1]=1; dp[1][2][2]=1;

	for(col=2;col<=n;col++)
	{
		for(comp=1;comp<=2*n;comp++)
		{
			for(l=0;l<4;l++)
			{
				for(sl=0;sl<4;sl++)
				{
					ncomp = getcomps(sl,l) + comp;
					dp[col][ncomp][l] = (dp[col][ncomp][l] + dp[col-1][comp][sl])%MOD;
				}
			}
		}
	}

	ans=0;
	for(i=0;i<4;i++)
		ans = (ans + dp[n][k][i])%MOD;
	cout<<ans;
	return 0;
}