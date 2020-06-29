#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define MAX 100003

ll MOD=1e9+7;
ll t , a , b , p , n , len , c , i , sum , pos;
vector<pair<ll,ll>>v;
bool flag; 
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
		cin>>a>>b>>p;
		cin>>s;
		n = s.length();
		len = 0;
		v.clear();
		for(i=0;i<n;i++)
		{
			if(i==0 || s[i]!=s[i-1])
			{
				c = (s[i]=='A')?a:b;
				v.push_back({c,i});
				len++;
			}
		}
		flag = true;
		sum = 0; pos = n-1;
		for(i=len-1;i>=0;i--)
		{
			if(v[i].second==n-1) continue;
			sum += v[i].first;
			if(sum>p)
			{
				cout<<pos+1<<"\n";
				flag = false;
				break;
			}
			pos = v[i].second;
		}

		if(flag) cout<<pos+1<<"\n";
	}
	return 0;
}