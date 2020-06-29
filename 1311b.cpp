#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 100003

ll MOD=1e9+7;
ll t , n , m , a[200] , b[200] , p[200] , s[200] , flag , i , j;
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
		for(i=1;i<=n;i++)
		{
			cin>>a[i];
			// b[i] = a[i];
		}
		memset(s,0,sizeof s);
		for(i=0;i<m;i++)
		{
			cin>>p[i];
			s[p[i]] = 1;
		}
		flag = 1;
		for(i=1;i<n;i++)
		{
			for(j=1;j<n;j++)
			{
				if(a[j]>a[j+1])
				{
					if(s[j]!=1)
					{
						flag = 0;
						break;
					}
					swap(a[j],a[j+1]);
				}
			}
		}
		if(flag)cout<<"YES\n";
		else cout<<"NO\n";

	}
	return 0;
}