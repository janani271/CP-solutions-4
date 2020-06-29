#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 200005
#define INF 1000000000000000005

using namespace std;

ll n,lis,i,a[MAX],f[MAX],tree[MAX];

void update(ll pos,ll val)
{
	//MAX is the range of input numbers. 
	for(ll j=pos; j<=MAX; j+= j&(-j)) tree[j] = max(tree[j],val);
}

ll query(ll r)
{
	ll cur=0;
	for(ll j=r; j>0; j -= j&(-j)) cur = max(cur,tree[j]);
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
	lis = -1;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		f[i] = query(a[i]-1) + 1; //returns the max value in the range 0 to a[i]-1 inclusive
		update(a[i],f[i]); //updating the tree with value f[i] in position a[i]
		lis = max(lis,f[i]);
	}
	cout<<lis;

	return 0;
}