#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 505
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

ll n,i,j,k,d[MAX][MAX],x[MAX],sum,ans[MAX],a[MAX][MAX];

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n;
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) cin>>d[i][j];
	for(i=1;i<=n;i++) cin>>x[i];

	for(i=1;i<=n;i++) for(j=1;j<=n;j++) a[i][j] = d[x[i]][x[j]];
	for(i=1;i<=n;i++) for(j=1;j<=n;j++) d[i][j] = a[i][j];

	for(k=n;k>=1;k--)
	{
		sum=0;
		for(i=1;i<=n;i++)
		{
			for(j=1;j<=n;j++)
			{
				d[i][j] = min(d[i][j],d[i][k]+d[k][j]);
			}
		}
		for(i=k;i<=n;i++)
		{
			for(j=k;j<=n;j++)
			{
				sum += d[i][j];
			}
		}
		ans[k] = sum;
	}
	for(i=1;i<=n;i++) cout<<ans[i]<<" ";
	return 0;
}