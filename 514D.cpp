#include<bits/stdc++.h>

#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define vll vector<ll>
#define MAX 100003
#define INF 1000000000000000005
#define logn 20

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

ll n,m,cnt,a[MAX][7];
ll lg[MAX+3];
ll mx[MAX][logn][7];
vll ans,v;

void calc_log()
{
	lg[1]=0;
	for(ll i=2;i<=MAX;i++) lg[i] = lg[i/2] + 1;
}

void calc_max()
{
	//m[x][y][z] x-droid no, y-2^j droids from x, z-detail no. of xth droid
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
		{
			mx[i][0][j] = a[i][j];
		}
	}

	for(ll j=1;j<=lg[n]+1;j++)
	{
		for(ll i=0;i+(1<<j)<=n;i++)
		{
			for(ll c=0;c<m;c++)
			{
				mx[i][j][c] = max(mx[i][j-1][c],mx[i+(1<<(j-1))][j-1][c]);
			}
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

	cin>>n>>m>>cnt;
	for(ll i=0;i<n;i++)
	{
		for(ll j=0;j<m;j++)
		{
			cin>>a[i][j];
		}
	}

	calc_log();
	calc_max();

	ll l=1, r=n, len=0;
	while(l<=r)
	{
		ll mid = (l+r)/2;
		
		ll f=0;
		ll k = lg[mid];

		for(ll i=0;i+mid<=n;i++)
		{
			ll sum=0;
			v.clear();
			for(ll j=0;j<m;j++)
			{
				ll cur = max(mx[i][k][j],mx[i+mid-(1<<k)][k][j]);
				v.pb(cur);
				sum += cur;
			}
			if(sum<=cnt)
			{
				f = 1;
				if(len<mid)
				{
					len = mid;
					ans = v;
				}
				l = mid+1; break;
			}
		}
		if(!f) r = mid-1;
	}

	for(auto it : ans) cout<<it<<" ";
	if(ans.size()==0) for(ll i=0;i<m;i++) cout<<"0 ";
	return 0;
}