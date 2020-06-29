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

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	string s;
	cin>>s;

	ll n = s.length();
	ll cnt[5][5]={0},i,even,odd;
	even=0; odd=0;
	
	for(ll i=0;i<n;i++)
	{
		if(i%2)
		{
			cnt[s[i]-'a'][0]++;
			odd += cnt[s[i]-'a'][0];
			even += cnt[s[i]-'a'][1];
		}
		else
		{
			cnt[s[i]-'a'][1]++;
			even += cnt[s[i]-'a'][0];
			odd += cnt[s[i]-'a'][1];
		}
	}
	cout<<even<<" "<<odd;
	return 0;
}