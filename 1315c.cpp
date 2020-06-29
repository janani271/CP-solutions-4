#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 100003

ll MOD=1e9+7;
ll t , n , visited[250] , b[250] , i , x , j;
bool flag;
vector<ll>v;

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
		cin>>n;
		memset(visited,0,sizeof visited);
		for(i=1;i<=n;i++)
		{
			cin>>b[i];
			visited[b[i]] = 1;
		}
		flag = true; v.clear();
		for(i=1;i<=n;i++)
		{
			v.pb(b[i]);
			x = -1;
			for(j=b[i]+1;j<=(2*n);j++)
			{
				if(!visited[j])
				{
					visited[j] = 1;
					x = j;
					break;
				}
			}
			if(x == -1)
			{
				cout<<"-1";
				flag = false;
				break;
			}
			v.pb(x);
		}

		if(flag)
			for(auto it:v)cout<<it<<" ";
		cout<<"\n";
	}
	return 0;
}