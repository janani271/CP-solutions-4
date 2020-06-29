#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define MAX 100003

ll MOD=1e9+7;
ll n , cost[MAX], h , a , r , d , i;
string s;
int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n>>s;
	for(i=0;i<n;i++)
	{
		cin>>cost[i];
		if(s[i]=='h') h += cost[i];
		if(s[i]=='a') a = min(h,a+cost[i]);
		if(s[i]=='r') r = min(a,r+cost[i]);
		if(s[i]=='d') d = min(r,d+cost[i]); 
	}
	cout<<d;
	return 0;
}