#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 1000003

using namespace std;

struct nod
{
	ll a,b,c;
};

nod tree[4*MAX];

string s;

void build(ll node, ll start, ll end)
{
	// cerr<<"node : "<<node<<"\tstart : "<<start<<"\tend : "<<end<<"\n";
	if(start == end)
	{
		tree[node].a = tree[node].b = tree[node].c = 0;
		if(s[start]=='(') tree[node].b = 1;
		else tree[node].c = 1;
		return;
	}

	ll mid = (start+end)/2;
	build(2*node,start,mid);
	build(2*node+1,mid+1,end);

	ll x = min(tree[2*node].b,tree[2*node+1].c);
	tree[node].a = tree[2*node].a + tree[2*node+1].a + (2*x);
	tree[node].b = tree[2*node].b + tree[2*node+1].b - x;
	tree[node].c = tree[2*node].c + tree[2*node+1].c - x;
}

nod query(ll node, ll start, ll end, ll l , ll r)
{
	if(l>end || r<start || start>end)
	{
		nod temp;
		temp.a = 0; temp.b = 0; temp.c = 0;
		return temp;
	}

	if(l<=start && end<=r) return tree[node];

	ll mid = (start+end)/2;
	nod g = query(2*node,start,mid,l,r);
	nod h = query(2*node+1,mid+1,end,l,r);
	ll x = min(g.b,h.c);
	nod temp;
	temp.a = g.a + h.a + (2*x);
	temp.b = g.b + h.b - x;
	temp.c = g.c + h.c - x;
	return temp;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	ll n,m,l,r;
	cin>>s;
	n = s.length();
	build(1,0,n-1);
	cin>>m;
	for(ll i=0;i<m;i++)
	{
		cin>>l>>r;
		cout<<query(1,0,n-1,l-1,r-1).a<<"\n";
	}
	return 0;
}