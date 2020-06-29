#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define all(x) x.begin(),x.end()
#define MAX 1000003

using namespace std;

ll MOD=1e9+7;
ll INF = 1000000000000000005;

ll add(ll a,ll b) { return ((a%MOD) + (b%MOD))%MOD; }
ll mul(ll a,ll b) { return ((a%MOD) * (b%MOD))%MOD; }
ll sub(ll a,ll b) { return ((a%MOD) - (b%MOD) + MOD)%MOD; }

ll n,m,r,l,mid,a[MAX],pos,cur,rem,flag,i,tot,ans;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>m;
	r=0; pos=0;
	for(i=1;i<=n;i++)
	{
		cin>>a[i];
		r += a[i];
		if(a[i]!=0) pos = i;
	}
	
	r+=(n+1); l=0; a[0]=0;
	ans = r+100;
	while(l<=r)
	{
		mid = (l+r)/2;
		// cout<<"l : "<<l<<"\tr : "<<r<<"\tmid : "<<mid<<"\n";
		cur=pos; rem=a[pos]; flag=0;
		for(i=1;i<=m;i++)
		{
			if(cur==0)
			{
				flag = 1; break;
			}
			tot = mid;
			tot -= cur;
			while(tot>0 && cur>0)
			{
				// cout<<"cur : "<<cur<<"\t i :"<<i<<"\trem : "<<rem<<"\n";
				if(rem<=tot)
				{
					tot -= rem;
					cur--;
					while(cur>0 && a[cur]==0)
					{
						// cout<<"cur : "<<cur<<"\tval : "<<a[cur]<<"\n";
						cur--;
					}
					rem = a[cur];
				}
				else
				{
					rem -= tot;
					tot=0;
				}
			}
			if(cur==0)
			{
				flag = 1; break;
			}
		}
		if(flag)
		{
			ans = min(ans,mid);
			// cout<<"ans : "<<ans<<"\n";
			r = mid-1;
		}
		else l = mid+1;
	}
	cout<<ans;
	return 0;
}