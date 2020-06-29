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
ll f[MAX],i,n,j;
map<ll,ll>m;
string s;
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>s;
	n = s.length();
	//kmp
	f[0]=0;
	for(i=1;i<n;i++)
	{
		j = f[i-1];
		while(j>0 && s[j]!=s[i]) j = f[j-1];
		if(s[i] == s[j]) j++;
		f[i] = j;
		if(i<n-1) m[f[i]] = 1;
	}
	if(f[n-1]!=0 && m[f[n-1]]>0)
	{
		cout<<s.substr(0,f[n-1]);
	}
	else if(f[f[n-1]-1]!=0)
	{
		cout<<s.substr(0,f[f[n-1]-1]);
	}
	else cout<<"Just a legend";
	return 0;
}