#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 100003

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

string s,t;
ll f[MAX],lps[MAX],dp[MAX],p1[MAX],p2[MAX];

void lpsCompute(string a, string b)
{
	ll j,i;
	ll len = b.length();
	
	f[0]=0;
	for(i=1;i<len;i++)
	{
		j = f[i-1];
		while(j>0 && b[j]!=b[i]) j = f[j-1];
		if(b[i]==b[j]) j+=1;
		f[i]=j;
	}

	len = a.length();
	j=f[0];
	for(i=0;i<len;i++)
	{
		while(j>0 && b[j]!=a[i]) j=f[j-1];
		if(a[i]==b[j]) j++;
		lps[i]=j;
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>s>>t;

	ll n = s.length();
	ll m = t.length();

	lpsCompute(s,t);

	dp[0]=0;
	p1[0]=0;//prefix sum over dp
	p2[0]=0;//prefix sum over p1
	ll ans=0;
	
	for(ll i=1;i<=n;i++)
	{
		if(lps[i-1]!=m) dp[i] = dp[i-1];
		else dp[i] = add((i-m+1),p2[i-m]);
		
		p1[i] = add(p1[i-1] , dp[i]);
		p2[i] = add(p2[i-1] , p1[i]);
		
		// cout<<"i : "<<i<<"\tdp : "<<dp[i]<<"\n";
		// cout<<"lps : "<<lps[i-1]<<"\n";
		ans = add(ans,dp[i]);
	}

	cout<<ans;
	return 0;
}