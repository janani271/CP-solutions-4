#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 100003
#define INF 1000000000000000005

using namespace std;

ll MOD=1e8;

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
ll n,m,k,l;
ll dp[105][105][15][15];

ll calc(ll i,ll j,ll c,ll d)
{
	if(i==0 && j==0) return 1;
	if(dp[i][j][c][d]!=-1) return dp[i][j][c][d];
	ll x=0; //horsemen
	ll y=0; //footmen
	if(c>0 && i>0) x = calc(i-1,j,c-1,l);
	if(d>0 && j>0) y = calc(i,j-1,k,d-1);
	return dp[i][j][c][d] = add(x,y);
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>m>>k>>l;
	memset(dp,-1,sizeof dp);
	cout<<calc(n,m,k,l);
	return 0;
}