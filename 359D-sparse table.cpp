#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 300003
#define INF 1000000000000000005
#define logn 30

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

ll n,a[MAX],i,l,r,ans_len,k,f,lg[MAX];
ll mi[MAX][logn+5], mg[MAX][logn+5];
vll v,ans;

void calc_log()
{
	lg[1]=0;
	for(ll j=2;j<=MAX;j++)
	{
		lg[j] = lg[j/2]+1;
	}
}

void calc_min()
{
	for(ll i=0;i<n;i++)
	{
		mi[i][0] = a[i];
	}
	for(ll j=1;j<=lg[n]+1;j++)
	{
		for(ll i=0;(i+(1<<j))<=n;i++)
		{
			mi[i][j] = min(mi[i][j-1],mi[i+(1<<(j-1))][j-1]);
		}
	}
}

void calc_gcd()
{
	for(ll i=0;i<n;i++)
	{
		mg[i][0] = a[i];
	}
	for(ll j=1;j<=lg[n]+1;j++)
	{
		for(ll i=0;i+(1<<j)<=n;i++)
		{
			mg[i][j] = __gcd(mg[i][j-1],mg[i+(1<<(j-1))][j-1]);
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}

	calc_log();
	calc_min();
	calc_gcd();
	
	l=1; r=n; ans_len=0;
	while(l<=r)
	{
		ll mid = (l+r)/2;
		f=0; ans.clear();

		k = lg[mid];
		for(i=0;i+mid-1<n;i++)
		{
			ll cur_min = min(mi[i][k],mi[i+mid-(1<<k)][k]);
			ll cur_gcd = __gcd(mg[i][k],mg[i+mid-(1<<k)][k]);
			if(cur_gcd==cur_min)
			{
				f=1;
				ans.pb(i+1);
			}
		}

		if(f)
		{
			if(ans_len<=mid)
			{
				ans_len = mid;
				v = ans;
			}
			l = mid+1;
		}
		else r=mid-1;
	}

	cout<<v.size()<<" "<<ans_len-1<<"\n";
	for(auto it:v) cout<<it<<" ";
	
	return 0;
}