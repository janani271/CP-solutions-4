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

ll b,p[MAX],cost[7],buy[7],i,cur,cnt,it,n;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n;
	for(i=0;i<n;i++) cin>>p[i];
	for(i=0;i<5;i++) cin>> cost[i];
	
	cur=0;
	for(i=0;i<n;i++)
	{
		cur += p[i];
		while(cur>=cost[0])
		{
			it = upper_bound(cost,cost+5,cur) - cost;
			it--;
			cnt = cur/cost[it];
			buy[it] += cnt;
			cur -= (cost[it]*cnt);
		}
	}
	
	for(i=0;i<5;i++) cout<<buy[i]<<" ";
	cout<<"\n"<<cur;
	
	return 0;
}