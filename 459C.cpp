#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 1003
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

ll n,k,d;
vll v[MAX];
ll i,temp,j,cnt;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>k>>d;
	
	if(n>pow(k,d))
	{
		cout<<"-1";
		return 0;
	}

	if(k==1 && n==1)
	{
		for(i=1;i<=d;i++) cout<<"1\n";
		return 0;
	}

	for(i=1;i<=n;i++)
	{
		temp = i; cnt=0;
		while(temp>0)
		{
			v[i].pb(temp%k);
			temp = temp/k;
			cnt++;
		}
		while(cnt<=d)
		{
			v[i].pb(0); cnt++;
		}
	}

	for(i=0;i<d;i++)
	{
		for(j=1;j<=n;j++)
		{
			cout<<v[j][i]+1<<" ";
		}
		cout<<"\n";
	}
	return 0;
}