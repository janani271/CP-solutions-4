#include<bits/stdc++.h>
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 100003
#define INF 1000000000000000005

using namespace std;

ll MOD=1e9+7;

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

ll n,m,w,i,a[MAX],l,r,res,mid,ans,req,cover[MAX],diff,st[MAX];
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>m>>w;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
		if(i==0) r=a[i];
		r = max(r,a[i]);
	}

	l=0; r+=(m+2); res=0;

	while(l<=r)
	{
		mid = (l+r)/2;
		ans=0;
		for(i=0;i<n;i++)
		{ 
			req = max((ll)0,mid-a[i]);
			if(i==0)
			{
				 cover[i] = req;
				 ans += cover[i];
				 st[i] = cover[i];
			}
			else
			{
				cover[i] = cover[i-1];
				st[i] = 0;
				if(i>=w) cover[i] -= st[i-w];
				if(cover[i]<req)
				{
					diff = req-cover[i];
					// cout<<"less!! I : "<<i<<"\tcover : "<<cover[i]<<"\tdiff : "<<diff<<"\n";
					cover[i] += diff;
					st[i] = diff;
					ans += diff;
				}
			}
			// cout<<"I : "<<i<<"\tans : "<<ans<<"\n";
		}
		// cout<<"mid : "<<mid<<"\tans : "<<ans<<"\n----------------------------\n";
		if(ans>m) r = mid-1;
		else
		{
			l = mid+1;
			res = max(res,mid);
		}
	}
	cout<<res;
	return 0;
}