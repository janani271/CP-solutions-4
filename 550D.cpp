#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 500

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll k,c,d,m,i,deg[MAX],adj[MAX][MAX];
vll g[MAX];
priority_queue<pairs,vector<pairs>,greater<pairs>>pq;

ll solve(ll a, ll b)
{
	ll cnt=0;
	for(i=a;i<=b;i++)
	{
		pq.push({0,i});
		deg[i] = 0;
		adj[i][i]=1;
	}
	for(i=a;i<b;i++)
	{
		ll cur = k - deg[i];
		while(cur>0)
		{
			auto v = pq.top();
			pq.pop();
			ll x = v.first, y = v.second;
			if(x == k || adj[i][y]) continue;
			g[i].pb(y); deg[y]++; cur--; deg[i]++;
			adj[i][y] = adj[y][i] = 1;
			pq.push({x+1,y}); cnt++;
		}
	}
	return cnt;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>k;
	if(k%2==0)
	{
		cout<<"NO";
		return 0;
	}
	if(k==1)
	{
		cout<<"YES\n";
		cout<<"2 1";
		cout<<"\n1 2";
		return 0;
	}

	ll c = solve(1,k+2);
	ll d = solve(k+3,k+k+4);
	g[k+2].pb(k+k+4);
	m = c+d+1;  

	cout<<"YES\n";
	cout<<(2*(k+2))<<" "<<m<<"\n";
	for(i=1;i<=k+k+4;i++)
	{
		if(g[i].size())
		{
			for(auto it:g[i]) cout<<i<<" "<<it<<"\n";
		}
	}
	return 0;
}