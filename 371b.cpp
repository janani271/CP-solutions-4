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

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	ll a,b,c,res;

	cin>>a>>b;
	c = __gcd(a,b);
	a = a/c;  b = b/c; res=0;
	while(a%2==0)
	{
		a/=2; res++;
	}
	while(a%3==0)
	{
		a=a/3; res++;
	}
	while(a%5==0)
	{
		a=a/5; res++;
	}
	while(b%2==0)
	{
		b=b/2; res++;
	}
	while(b%3==0)
	{
		b=b/3; res++;
	}
	while(b%5==0)
	{
		b=b/5; res++;
	}
	if(a==1 && b==1) cout<<res;
	else cout<<"-1";

	return 0;
}