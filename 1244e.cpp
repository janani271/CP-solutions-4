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

ll n,k,i,p[MAX],l,r,mid,ans,mi,mx,pos,u,d;
vll a;

ll valid(ll mi, ll mx)
{
	auto it = upper_bound(a.begin(),a.end(),mx);
	if(it==a.end()) u=0;
	else
	{
		pos = it-a.begin();
		u = p[n] - p[pos-1] - ((n-pos+1)*mx);
		u = max((ll)0,u);
	}

	mi = max(mi,(ll)1);
	it = lower_bound(a.begin(),a.end(),mi);
	pos = it-a.begin();
	d = ((pos-1)*mi) - p[pos-1];
	d = max((ll)0,d);

	if(u+d<=k) return 1;
	return 0;
} 

ll check(ll x)
{
	for(i=1;i<=n;i++)
	{
		if(valid(a[i]-x,a[i])) return 1;
		if(valid(a[i],a[i]+x)) return 1;
	}
	return 0;
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	ll x;
	cin>>n>>k;
	a.pb(0);
	for(i=1;i<=n;i++)
	{
		cin>>x;
		a.pb(x);
	}

	sort(a.begin(),a.end());
	p[0]=0;
	for(i=1;i<=n;i++) p[i] = p[i-1] + a[i];

	l = 0; r = a[n]-a[1]; ans=r;
	while(l<=r)
	{
		mid = (l+r)/2;
		if(check(mid))
		{
			ans =  min(ans,mid);
			r = mid-1;
		}
		else l = mid+1;
	}
	cout<<ans;
	return 0;
}