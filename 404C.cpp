#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n , k , i , x , flag , p , q, cnt , cur , nxt;
vector<pair<ll,ll>>d;
map<ll,ll>m;

int main()
{
	cin>>n>>k;

	for(i=0;i<n;i++)
	{
		cin>>x;
		d.push_back({x,i});
		m[x]++;
	}

	if(m[0]!=1)
	{
		cout<<"-1";
		return 0;
	}

	flag = 1;
	for(auto it=m.begin();it!=m.end();++it)
	{
		if( it!=m.begin() && (p==0 && q*k < it->second) || (p!=0 && q*(k-1) < it->second))
			flag = 0;
		if(it->first - p > 1)
			flag=0;
		p = it->first;
		q = it->second;
	}
	if(!flag)
	{
		cout<<"-1";
		return 0;
	}

	if(n==1)
	{
		cout<<"0\n";
		return 0;
	}

	sort(d.begin(),d.end());
	cout<<n-1<<"\n";
	cur = 0; nxt = 1; cnt=0;
	while(cur<n && nxt<n)
	{
		if(cnt<k && d[nxt].first==d[cur].first+1)
		{
			cout<<d[cur].second+1<<" "<<d[nxt].second+1<<"\n";
			cnt++;
			nxt++;
		}
		if(cnt==k)
		{
			cur++;
			cnt=1;
		}
		if(d[nxt].first-d[cur].first>1)
		{
			while(d[nxt].first-d[cur].first>1)
				cur++;
			cnt=1;
		}
	}
	return 0;
}