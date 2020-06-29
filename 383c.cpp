#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 200003

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll start[MAX],en[MAX],level[MAX],a[MAX],u,v;
vll seq,g[MAX];

class fenwickTree
{
	public:
	ll tree[MAX+20];
	ll len;
	fenwickTree(ll n)
	{
		len = n;
		for(int i=1;i<=len+10;i++) tree[i]=0;
	}
	
	void _update(ll pos, ll val)
	{
		for(pos++;pos<=len;pos+=(pos&-pos)) tree[pos]+=val;
	}

	void update(ll l, ll r, ll val)
	{
		_update(l,val);
		_update(r+1,-val);
	}

	ll get(ll pos)
	{
		ll sum=0;
		for(pos++;pos>=1;pos-=(pos&-pos)) sum += tree[pos];
		return sum;
	}
};

void dfs(ll x)
{
	if(start[x]>=0) return; //it means you have visited this node already
	start[x] = seq.size();
	seq.pb(x);
	for(auto it:g[x])
	{
		level[it] = 1^level[x];
		dfs(it);
	}
	en[x] = seq.size()-1;
}

int main()
{
	// #ifndef ONLINE_JUDGE
 //    freopen("input.txt", "r", stdin);
 //    freopen("output.txt", "w", stdout);
	// #endif
	fastread;

	ll n,m,i,tp,x,val;

	cin>>n>>m;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n-1;i++)
	{
		cin>>u>>v;
		u--;v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	
	memset(start,-1,sizeof start);
	memset(en,-1,sizeof en);
	memset(level,0,sizeof level);
	
	//nodes from start[x] to end[x] are the nodes in the subtree of x and x will be at start[x]
	// the fenwick tree is imagined to have this arrangement of nodes
	
	dfs(0); //euler tour
	
	//one fenwick tree for odd levels and one for even levels
	fenwickTree fwt[2] = {fenwickTree(n),fenwickTree(n)};
	
	//update the fenwick tree with starting values
	for(i=0;i<n;i++)
	{
		fwt[level[i]%2].update(start[i],start[i],a[i]);
	}

	for(i=0;i<m;i++)
	{
		cin>>tp>>x;
		x--;
		if(tp==1)
		{
			cin>>val;
			fwt[level[x]%2].update(start[x],en[x],val); //nodes at levels with same parity
			fwt[1-(level[x]%2)].update(start[x],en[x],-val);//nodes at levels with opposite parity
		}
		else
		{
			ll res = fwt[level[x]%2].get(start[x]);
			cout<<res<<"\n";
		}
	}
	return 0;
}