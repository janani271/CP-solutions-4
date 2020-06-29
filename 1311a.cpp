#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 100003

ll MOD=1e9+7;
ll t , a , b , ans;
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
		cin>>a>>b;
		if(a==b)
		{
			ans = 0;
		}
		else if(a<b)
		{
			if(abs(a-b)%2==1)
				ans = 1;
			else ans = 2;
		}
		else
		{
			if((a-b)%2==0)
				ans = 1;
			else ans = 2;
		}
		cout<<ans<<"\n";
	}
	return 0;
}