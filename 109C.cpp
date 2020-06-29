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

ll visited[MAX],n,i,u,v,w,cur,flag;
vector<pairs>g[MAX];
ll cnt1[MAX],sum[MAX],cnt2[MAX];
vll h[MAX];

void dfs(ll x)
{
	visited[x] = 1;
	cnt1[x] = 0;
	cnt2[x] = 1;
	ll cur;
	for(auto it:g[x])
	{
		if(!visited[it.first])
		{
			dfs(it.first);
			if(it.second==1) cur = cnt2[it.first];
			else cur = cnt1[it.first];
			if(cur) h[x].pb(cur);
			cnt1[x] += cur;
			cnt2[x] += cnt2[it.first];
		}
	}
	// cout<<"x : "<<x<<"\tcnt1 : "<<cnt1[x]<<"\tcnt2 : "<<cnt2[x]<<"\n";
}

void dfs1(ll x)
{
	visited[x] = 1;
	ll cur;
	for(auto it : g[x])
	{
		if(visited[it.first])
		{
			if(it.second==1) cur = cnt2[it.first]-cnt2[x]; 
			else  cur = cnt1[it.first] - cnt1[x];
			cnt1[x] += cur;
			if(cur) h[x].pb(cur);
			cnt2[x] = cnt2[x] + (cnt2[it.first] - cnt2[x]);
		}
	}
	for(auto it : g[x])
	{
		if(!visited[it.first]) dfs1(it.first);
	}
	// cout<<"x : "<<x<<"\tcnt1 : "<<cnt1[x]<<"\tcnt2 : "<<cnt2[x]<<"\n";
	// cout<<"x : "<<x<<"\n";
	for(auto it:h[x])
	{
		// cout<<it<<" ";
		sum[x] += it;
	}
	// cout<<"\nsum : "<<sum[x]<<"\n";
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
		cin>>u>>v>>w;
		flag=1;
		while(w!=0)
		{
			cur = w%10;
			if(cur!=4 && cur!=7)
			{
				flag = 0; break;
			}
			w /= 10;
		}
		g[u].pb({v,flag});
		g[v].pb({u,flag});
	}
	dfs(1);
	memset(visited,0,sizeof visited);
	dfs1(1);

	ll tot,res=0;
	for(i=1;i<=n;i++)
	{
		tot=0;
		for(auto it:h[i])
		{
			sum[i] -= it;
			tot += (it*(it-1))/2;
			tot += (it*sum[i]);
		}
		tot *= 2;
		res += tot;
		// cout<<"i : "<<i<<"\ttot : "<<tot<<"\n";
	}
	cout<<res;
	return 0;
}