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

const ll maxp = (1<<16);
vll primes;
ll dp[105][maxp+5], val[105][maxp+5];
ll a[105],n;
ll mask[65];
ll p[65];

void sieve()
{
	// primes from 1 to 60
	memset(p,1,sizeof p);
	ll cnt=0;
	for(ll i=2;i<=58;i++)
	{
		if(!p[i]) continue;
		primes.pb(i); cnt++;
		for(ll j=i*i;j<=58;j+=i) p[j] = 0;
	}
	
	//masks for each num from 1 to 60
	for(ll i=1;i<=58;i++)
	{
		mask[i] = 0;
		for(ll j=0;j<cnt;j++)  if(i%primes[j]==0) mask[i] |= (1<<j);
		// cout<<mask[i]<<"\n";
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	sieve();
	cin>>n;
	for(ll i=1;i<=n;i++) cin>>a[i];


	//dp[i][j] -> min sum of difference upto i elements using j as mask;
	for(ll i=1;i<=n;i++)
	{
		for(ll j=0;j<maxp;j++)
		{
			dp[i][j] = dp[i-1][j] + abs(a[i]-1);
			val[i][j] = 1;
			for(ll k=2;k<=58;k++)
			{
				if((mask[k]&j)!=mask[k]) continue;
				//previous state where this part of mask wasn't used
				// cout<<"hellp";
				if(dp[i-1][j^mask[k]] + abs(a[i]-k) < dp[i][j])
				{
					dp[i][j] = dp[i-1][j^mask[k]] + abs(a[i]-k);
					val[i][j] = k;
				}
			}
		}
	}

	//backtrack
	ll pos = maxp-1;
	ll min_val = dp[n][pos];
	for(ll j=0;j<maxp;j++)
	{
		if(dp[n][j]<min_val)
		{
			min_val = dp[n][j];
			pos = j;
		}
	}

	vector<ll> ans;
	ll cur;
	cur = val[n][pos];
	ans.pb(cur); 
	for(ll i=n-1;i>=1;i--)
	{
		pos = mask[cur]^pos;
		cur = val[i][pos];
		ans.pb(cur);
	}
	reverse(ans.begin(),ans.end());
	for(auto it:ans) cout<<it<<" ";
	return 0;
}