#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 100003

ll MOD=1e9+7;
ll t , n , m , i , sum , a;
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
		cin>>n>>m;
		sum=0;
		for(i=0;i<n;i++)
		{
			cin>>a;
			sum += a;
		}
		cout<<min(m,sum)<<"\n";
	}
	return 0;
}