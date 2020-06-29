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
ll INF = 100000000000000005;

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

ll par[MAX] , s[MAX];
ll n,m,k;
ll t[MAX],c[505],res[505][505] , cs[505];
vector<pair<ll,pairs>> v;
ll x,y,cost;

ll parent(ll a)
{
 	while(a!=par[a])
 	{
 		par[a] = par[par[a]];
 		a = par[a];
 	}
 	return a;
}

void add_comp(ll a , ll b)
{
	if(s[a]<s[b])
	{
		par[a] = b;
		s[b]+=s[a];
	}
	else
	{
		par[b] = a;
		s[a] += s[b];
	}
}

bool check_comp(ll a , ll b)
{
	ll ta = a;
	ll tb = b;
	a = parent(a); 
	b = parent(b); 
	if(a == b) 
		return false;
	else 
	{
		add_comp(a,b);
		return true;
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>m>>k;
	
	ll cur=1;
	for(ll i=1;i<=k;i++)
	{
		cin>>c[i];
		for(ll j=cur;j<cur+c[i];j++)
		{
			t[j] = i;
		}
		cur += c[i];
	}
	
	for(ll i=1;i<=m;i++)
	{
		cin>>x>>y>>cost;
		v.pb({cost,{x,y}});
	}

	sort(all(v));
	for(ll i=1;i<=n;i++)
	{
		par[i]=i; s[i]=1;
	}
	for(auto it:v)
	{
		if(it.first>0) break;
		bool f = check_comp(it.second.first,it.second.second);
	}

	cur=1;
	for(ll i=1;i<=k;i++)
	{
		ll f=1;
		for(ll j=cur+1;j<cur+c[i];j++)
		{	
			if(parent(j)!=parent(j-1))
			{
				f=0; break;
			}
		}
		if(!f)
		{
			cout<<"No\n"; return 0;
		}
		cur += c[i];
	}

	cout<<"Yes\n";
	for(ll i=1;i<=k;i++) for(ll j=1;j<=k;j++) res[i][j]=INF;
	for(auto it:v)
	{
		x = it.second.first;
		y = it.second.second;
		cost = it.first;
		res[t[x]][t[y]] = res[t[y]][t[x]] = min(res[t[x]][t[y]],cost);
	}

	for(ll z=1;z<=k;z++)
	{
		for(ll i=1;i<=k;i++)
		{
			for(ll j=1;j<=k;j++)
			{
				res[i][j] = min(res[i][j],res[i][z]+res[z][j]);
			}
		}
	}

	for(ll i=1;i<=k;i++)
	{
		for(ll j=1;j<=k;j++)
		{
			if(i==j) cout<<"0 ";
			else
			{
				if(res[i][j]==INF) cout<<"-1 ";
				else cout<<res[i][j]<<" ";
			}
		}
		cout<<"\n";
	}
	return 0;
}