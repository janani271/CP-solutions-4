#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 5000005

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll prime[MAX],p[MAX],psum[MAX];
void sieve()
{
	ll i,j;
	for(i=1;i<=MAX;i+=2) prime[i] = i;
	for(i=2;i<=MAX;i+=2) prime[i] = 2;
	for(i=3;i<=MAX;i+=2)
	{
		if(prime[i]!=i) continue;
		for(j=i*i;j<=MAX;j+=i)
		{
			prime[j] = i;
		}
	}
	for(i=1;i<=MAX;i++) if(prime[i]==i) p[i]=1;
	psum[1] = 1;
	for(i=2;i<=MAX;i++)
	{
		if(prime[i]!=i) p[i] = p[i/prime[i]] + 1;
		psum[i] = psum[i-1] + p[i];
	} 
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	ll t,a,b;
	sieve();
	cin>>t;
	while(t--)
	{
		cin>>a>>b;
		cout<<psum[a] - psum[b]<<"\n";
	}
	return 0;
}