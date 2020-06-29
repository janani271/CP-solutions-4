#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 200010

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll n,w,i;
ll a[MAX],b[MAX],res[2*MAX];
ll f[MAX]; 

ll lps(ll s[], ll len)
{
	f[0]=0; ll cnt=0;
	for(i=1;i<n+w-1;i++)
	{
		ll j = f[i-1];
		while(j>0 && s[i]!=s[j])
		{
			j = f[j-1];
		}
		if(s[i]==s[j]) j++;
		f[i] = j;
		if(f[i]==len) cnt++;
		// cout<<"i : "<<i<<"\tf : "<<f[i]<<"\n";
	}
	return cnt;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>w;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<w;i++)
	{
		cin>>b[i];
	}
	if(n==1 && w==1)
	{
		cout<<"1"; return 0;
	}
	if(w==1)
	{
		cout<<n; return 0;
	}
	if(n==1)
	{
		cout<<"0";
		return 0;
	}

	for(i=0;i<w-1;i++)
	{
		res[i] = b[i] - b[i+1];
	}
	res[i] = 1e18;
	for(i=w;i<w+n-1;i++)
	{
		res[i] = a[i-w] - a[i+1-w];
	}
	ll cnt = lps(res,w-1);
	cout<<cnt;
	return 0;
}