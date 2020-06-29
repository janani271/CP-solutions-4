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

ll n,c[5][MAX],i,u,v,pos,co[10],ans,res[10][MAX],visited[MAX];
vll g[MAX];

ll calc_cost(ll f, ll s, ll x)
{
	vll v; queue<ll>q;
	v.pb(f); v.pb(s); 
	ll cnt=1,sum=0,nxt,cur;

	res[x][pos] = f;
	nxt = g[pos][0];
	res[x][nxt] = s;

	memset(visited,0,sizeof visited);
	visited[pos] = visited[nxt] = 1;

	for(auto it:g[nxt]) if(!visited[it]) q.push(it);
	visited[q.front()]=1;

	while(!q.empty())
	{
		cur = q.front();
		q.pop();
		cnt++;
		if(cnt<3) res[x][cur] = 3-(f+s);
		else res[x][cur] = v[cnt-3];
		v.pb(res[x][cur]);
		for(auto it:g[cur])
		{
			if(!visited[it])
			{
				q.push(it); visited[it]=true;	
			}
		}
	}

	for(i=0;i<n;i++)
	{
		sum += c[res[x][i]][i];
	}
	return sum;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n;
	for(i=0;i<n;i++) cin>>c[0][i];
	for(i=0;i<n;i++) cin>>c[1][i];
	for(i=0;i<n;i++) cin>>c[2][i];
	for(i=1;i<n;i++)
	{
		cin>>u>>v;
		u--; v--;
		g[u].pb(v);
		g[v].pb(u);
	}
	for(i=0;i<n;i++)
	{
		if(g[i].size()>2)
		{
			cout<<"-1";
			return 0;
		}
		if(g[i].size()==1)
		{
			pos = i;
		}
	}

	co[0] = calc_cost(0,1,0);
	co[1] = calc_cost(0,2,1);
	co[2] = calc_cost(1,0,2);
	co[3] = calc_cost(1,2,3);
	co[4] = calc_cost(2,0,4);
	co[5] = calc_cost(2,1,5);
	
	ans = 0;
	for(i=1;i<6;i++)
	{
		if(co[i]<co[ans])
		{
			ans = i;
		}
	}
	cout<<co[ans]<<"\n";
	for(i=0;i<n;i++) cout<<res[ans][i]+1<<" ";
	return 0;
}