#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define MAX 5005

ll MOD=1e9+7;
ll tree[4*MAX], a[MAX], i , n;

void build(ll node, ll l , ll r)
{
	if(l==r)
	{
		tree[node] = l;
		return;
	}
	if(l>r) return;

	ll mid =(l+r)/2;
	build(2*node,l,mid);
	build(2*node+1,mid+1,r);
	tree[node] = a[tree[2*node]]<=a[tree[2*node+1]]?tree[2*node]:tree[2*node+1];
	// cout<<"l : "<<l<<"\tr : "<<r<<"\tval : "<<tree[node]<<"\n";
}

ll query(ll node, ll l , ll r , ll s , ll e)
{
	if(l>r || s>r || e<l) return -1;
	if(s<=l && r<=e) return tree[node];
	ll mid = (l+r)/2;
	ll f = query(2*node,l,mid,s,e);
	ll se = query(2*node+1,mid+1,r,s,e);
	ll ans;
	if(f==-1)
		return se;
	if(se==-1)
		 return f;
	return (a[f]<=a[se])?f:se;
}

ll paint(ll l, ll r, ll h)
{
	if(l>r) return 0;
	// if(l==r) return 1;

	ll v = (r-l+1);
	ll cost=0;
	ll mix = query(1,0,n-1,l,r); 
	ll mi=a[mix];
	cost = mi - h + paint(l,mix-1,mi) + paint(mix+1,r,mi);
	// cout<<"l : "<<l<<"\tr : "<<r<<"\t h : "<<h<<"\t idx : "<<mix<<"\tval : "<<cost<<"\n";
	return min(cost,v);
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
		cin>>a[i];
	}
	build(1,0,n-1);
	cout<<paint(0,n-1,0);
	return 0;
}