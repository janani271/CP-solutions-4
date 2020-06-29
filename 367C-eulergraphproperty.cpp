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

ll n,m,i,x,w[MAX],l,r,mid,cur,ans;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>x>>w[i];
	}
	sort(w,w+m,greater<ll>());
	l = 1; r = m;
	//binary search to find the max no.of vertices with diff values that can be used
	ans = 1;
	while(l<=r)
	{
		mid = (l+r)/2;
		
		if(mid%2==1)
		{
			//complete graph  -> each vertex has even deg => eulerian
			cur = (mid*(mid-1))/2;
		}
		else
		{
			//all vertices have odd degree. so except 2, (n-2) vertices get +1 deg => (n/2)-1 edges extra
			// makes it eulerian
			cur = ((mid*(mid-1))/2) + (mid/2) - 1; 
		}

		//no.of vertices = no.of edges+1. so max n-1 vertices
		if(cur<n)
		{
			ans = max(ans,mid);
			l = mid+1;
		}
		else r = mid-1;
	}
	// cout<<ans<<"\n";
	ll sum=0;
	for(i=0;i<ans;i++) sum += w[i];
	cout<<sum;
	return 0;
}