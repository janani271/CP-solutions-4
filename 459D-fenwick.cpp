#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 1000003
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

ll n,val[MAX],a[MAX],b[MAX],i,ans;
unordered_map<ll,ll>m;
ll tree[MAX+5];

void update(ll pos,ll val)
{
	//MAX is the range of input numbers. 
	for(ll j=pos; j<=MAX; j+= j&(-j)) tree[j] = tree[j]+val;
}

ll query(ll r)
{
	ll cur=0;
	for(ll j=r; j>0; j -= j&(-j)) cur += tree[j];
	return cur;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>val[i];
		m[val[i]]++;
		a[i] = m[val[i]];
	}
	m.clear();
	for(i=n-1;i>=0;i--)
	{
		m[val[i]]+=1;
		b[i]=m[val[i]];
	}
	ans=0;
	for(i=n-2;i>=0;i--)
	{
		update(b[i+1],1);
		ans += query(a[i]-1);
	}
	cout<<ans;
	return 0;
}