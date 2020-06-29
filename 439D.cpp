#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 100003
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

bool comp(ll x, ll y)
{
	return (x>y);
}

ll n,m,a[MAX],b[MAX],i,j,ans;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>m;
	for(i=0;i<n;i++) cin>>a[i];
	for(i=0;i<m;i++) cin>>b[i];
	sort(a,a+n);
	sort(b,b+m,comp);
	
	for(i=0;i<min(n,m)&&a[i]<b[i];i++)
	{
		ans += (b[i]-a[i]);
	}
	// i=0;
	// while(i<min(n,m))
	// {
	// 	if(a[i]>=b[i]) break;
	// 	ans += (b[i]-a[i]);
	// 	i++; 
	// }	
	cout<<ans;
	return 0;
}