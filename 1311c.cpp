#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 200009

ll MOD=1e9+7;
ll t , n , m , res[MAX] , cnt[30] , p , i;
string s;
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
		cin>>s;
		memset(res,0,sizeof res);
		memset(cnt,0,sizeof cnt);
		for(i=0;i<m;i++)
		{
			cin>>p;
			res[0] += 1;
			res[p] -= 1;
		}
		res[0] += 1;
		for(i=0;i<=n;i++)
		{
			if(i!=0)
				res[i] += res[i-1];
			if(i<n)
			{
				cnt[s[i]-'a'] += res[i];
			}
			// cout<<"res : "<<res[i]<<"\ts[i] : "<<s[i]<<"\n";
		}
		for(i=0;i<26;i++)
			cout<<cnt[i]<<" ";
		cout<<"\n";
	}
	return 0;
}