#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 100003
#define logn 20
#define INF 1000000000000000005

using namespace std;

ll MOD=1e9+7;

ll n, i, x, y, q, u, v, a,b,k, h[100009], visited[100009], visited1[100009];
ll lastnodeatlevel[100009], parent[100009][21];
ll d1,d2,res;
vll g[100009];

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


//dfs for heights -> O(n)
void find_heights(long long p , long long ht)
{
	h[p] = ht+1;
	visited[p]=1;
	for(auto it = g[p].begin();it!=g[p].end();++it)
	{
		if(!visited[*it])
		{
			parent[*it][0] = p;
			find_heights(*it,h[p]);
		}
	}
}
//dfs and finding the parents for each node which takes log n so -> O(nlogn)
//cl-current level 
//finding the parents at levels 2^0 to logn for each node
void parents_find(long long a ,long long cl) 
{
	visited1[a]=1;
	lastnodeatlevel[cl] = a; // the last node seen at cl-th level in a particular path
	for(k=0;k<=logn;k++)
	{
		if((1<<k)<cl)
			parent[a][k] = lastnodeatlevel[cl - (1<<k)];
	}
	for(auto it = g[a].begin();it!=g[a].end();++it)
	{
		if(!visited1[*it])
		{
			parents_find(*it,cl+1);
		}
	}
}


long long lca(long long a , long long b)
{
	ll bin,in,common,p,temp;
	//make level of both the nodes equal   =>logn
	if(h[a]!=h[b])
	{
		if(h[a]>h[b])
			swap(a,b);
		
		p=b;
		temp = h[b]-h[a]; 

		for(in=0;in<=logn;in++)
		{
			bin = temp%2;
			temp = temp/2;
			if(bin==1)
				p = parent[p][in];
		}
		b = p;
	}

	//lca  => taking jumps in powers of 2 =>logn
	if(a==b) 
		return a;
	for(in=logn;in>=0;in--)
	{
		if(parent[a][in] != parent[b][in])
		{
			a = parent[a][in];
			b = parent[b][in]; 
		}
		else
			common = parent[a][in];
	}
	return common;
}


ll find_pathlen(ll a , ll b)
{
	ll c = lca(a,b);
	ll len = h[a] + h[b] - (2*h[c]);
	return len;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n;
	for(i=1;i<n;i++)
	{
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}

	find_heights(1,0);
	parents_find(1,1);
	for(i=1;i<=logn;i++)
		parent[1][i]=1;

	cin>>q;
	while(q--)
	{
		cin>>x>>y>>a>>b>>k;
		
		d1 = find_pathlen(a,b);
		d2 = 1 + min(find_pathlen(a,x)+find_pathlen(y,b), find_pathlen(a,y)+find_pathlen(x,b));
		
		res = 0;
		if((d1<=k && (k%2==d1%2))||(d2<=k && k%2==d2%2)) res = 1;

		if(res) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}
