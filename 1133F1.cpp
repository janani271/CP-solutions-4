#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 300009

ll MOD=1e9+7;
ll par[MAX] , s[MAX] , n , m , mx , x , y , deg[MAX] ,i;
vector<pair<ll,ll>>v,ans;

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
	// cout<<"x : "<<a<<"\ty : "<<b<<"\n";
	a = parent(a); 
	b = parent(b); 
	// cout<<"parx : "<<a<<"\ty : "<<b<<"\n";
	if(a == b) 
		return true;
	else 
	{
		add_comp(a,b);
		return false;
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>m;
	mx = 1;
	for(i=1;i<=n;i++)
	{
		par[i] = i; s[i] = 1;
	}

	for(i=0;i<m;i++)
	{
		cin>>x>>y;
		v.pb({x,y});
		deg[x]++; deg[y]++;
		if(deg[x]>deg[mx])
			mx = x;
		if(deg[y]>deg[mx])
			mx = y;
	}
	
	for(i=0;i<m;i++)
	{
		x = v[i].first;
		y = v[i].second;
		if(x==mx || y==mx)
		{
			if(!check_comp(x,y))
				ans.pb(v[i]);
		}
	}

	for(i=0;i<m;i++)
	{
		x = v[i].first;
		y = v[i].second;
		// cout<<"x :"<<x<<"\ty : "<<y<<"\n";
		if(x==mx || y==mx) continue;
		if(!check_comp(x,y))
			ans.pb(v[i]);
	}

	for(auto it:ans)
		cout<<it.first<<" "<<it.second<<"\n";

	return 0;
}