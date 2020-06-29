#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 100005

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll t,k,dp[MAX+10],a,b,p[MAX];

void solve()
{
	dp[0]=1;
	p[0]=0;
	for(ll i=1;i<=MAX+5;i++)
	{
		if(i<k) dp[i] = dp[i-1];
		else dp[i] = add(dp[i-1],dp[i-k]);
		p[i] = add(p[i-1],dp[i]);
		// cout<<"I : "<<i<<"\tp : "<<p[i]<<"\n";
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>t>>k;
	solve();
	while(t--)
	{
		cin>>a>>b;
		cout<<sub(p[b],p[a-1])<<"\n";
	}
	return 0;
}