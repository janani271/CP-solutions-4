#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 100003

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

priority_queue<pairs,vector<pairs>,greater<pairs>>pq;
ll dist[MAX],visited[MAX];
ll u,v,weight;
ll n,m,s,l;
ll a[MAX],b[MAX],w[MAX];
vector<pairs>g[MAX];

void shortest(ll x)
{
	for(ll i=0;i<=MAX-2;i++) dist[i]=INF;
	
	pq.push({0,x});
	dist[x] = 0;
	
	while(!pq.empty())
	{
		u = pq.top().second;
		pq.pop();
		visited[u] = 1;
		for(auto it:g[u])
		{
			v = it.first;
			weight = it.second;
			if(!visited[v] && dist[v]>dist[u]+weight)
			{
				dist[v] = dist[u] + weight;
				pq.push({dist[v],v});
			}
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>m>>s;
	for(ll i=0;i<m;i++)
	{
		cin>>a[i]>>b[i]>>w[i];
		g[a[i]].pb({b[i],w[i]});
		g[b[i]].pb({a[i],w[i]});
	}
	cin>>l;
	
	shortest(s);
	
	ll cnt=0,x,y,l1,l2,r1,r2;
	//vertices at distance l
	for(ll i=1;i<=n;i++)
	{
		if(dist[i]==l) cnt++;
	}
	//edges at distance l
	for(ll i=0;i<m;i++)
	{
		x = dist[a[i]];
		y = dist[b[i]];
		if(x<l && l<x+w[i] && x+y+w[i]>(2*l)) cnt++;
		if(y<l && l<y+w[i] && x+y+w[i]>(2*l)) cnt++;
		if(x<l && y<l && x+y+w[i]==(2*l)) cnt++;
	}
	
	cout<<cnt;
	
	return 0;
}