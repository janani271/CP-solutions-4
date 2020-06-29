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
ll t,n,i,x,sum,temp,k,c,ans,cur;
vll v;
map<ll,ll>m;
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		sum=0;
		m.clear();
		v.clear();
		for(i=1;i<=k;i++)
		{
			cin>>x;
			sum += x;
			m[x]++;
		}
		if(sum<n)
		{
			cout<<"-1\n";
			continue;
		}
		temp = n; c=0;
		while(temp>0)
		{
			v.pb(temp%2);
			temp/=2;
			c++;
		}
		cur = 1; ans=0;
		for(i=0;i<c;i++)
		{
			if(v[i]==0)
			{
				m[cur*2] += m[cur]/2;
				cur = cur*2;
			}
			else
			{
				temp = cur;
				// cout<<"Cur : "<<cur<<"\tm : "<<m[cur]<<"\n";
				while(m[temp]==0)
				{
					temp = temp*2;
				}
				m[temp]--;
				while(temp!=cur)
				{
					temp/=2;
					m[temp]++;
					ans++;
				}
				m[temp]++;
				m[cur*2] += (m[cur]-1)/2;
				cur = cur*2;
				// cout<<"ans : "<<ans<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}