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

struct trie
{
	trie* ch[2];
};

trie* new_node()
{
	trie* node = new trie;
	for(ll i=0;i<2;i++) node->ch[i] = NULL;
	return node;
}

void insert(trie* root, ll x)
{
	if(root==NULL) root = new_node();
	trie* head = root;
	for(ll i=30;i>=0;i--)
	{
		ll val = ((1<<i)&x)/(1<<i);
		if(root->ch[val]==NULL)
			root->ch[val] = new_node();
		root = root->ch[val];
	}
}

ll query(trie* head, ll d)
{
	if(head==NULL || d<0) return 0;

	ll z_val = query(head->ch[0],d-1);
	ll o_val = query(head->ch[1],d-1);

	ll l,r;
	if(head->ch[0]==NULL) l=0; else l=1;
	if(head->ch[1]==NULL) r=0; else r=1;

	if(l && r) return (1<<d) + min(z_val,o_val);
	if(l==0) return o_val;
	if(r==0) return z_val;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	ll n,i,a;
	trie* root = new_node();
	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a;
		insert(root,a);
	}
	cout<<query(root,30);

	return 0;
}