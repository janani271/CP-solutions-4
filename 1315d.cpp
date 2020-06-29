#include<bits/stdc++.h>
using namespace std;
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb push_back
#define pairs pair<ll,ll>
#define MAX 200003

// bool comp(pairs x, pairs y)
// {
// 	if(y.second>x.second)
// 		return true;
// 	if(y.second==x.second)
// 	{
// 		if(x.first<=y.first)
// 			return true;
// 	}
// 	return false;
// }

ll MOD=1e9+7;
ll n , a[MAX] , t[MAX] , i , j , ans , cur;
priority_queue<pairs>pq;
pairs p; 
vector<pairs>v;

int main()
{
	#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	#endif
	fastread;

	cin>>n;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	for(i=0;i<n;i++)
	{
		cin>>t[i];
		v.pb({a[i],t[i]});
	}
	
	sort(a,a+n);
	for(i=1;i<n;i++)
	{
		if(a[i]<=a[i-1])
			a[i]=a[i-1]+1;
	}

	sort(v.begin(),v.end());

	i=0;j=0;ans=0;
	while(i<n)
	{
		cur = a[i];
		while(v[j].first<=cur && j<n)
		{
			pq.push({v[j].second,v[j].first});
			j++;
		}
		p = pq.top();
		pq.pop();
		ans += (cur-p.second)*p.first;
		i++;
	}
	cout<<ans<<"\n";
	return 0;
}