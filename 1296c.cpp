#include<bits/stdc++.h>
using namespace std;
long long t , n , i , x , y , l , r , len;
bool flag;
pair<long long,long long>p[200009];
map<pair<long long, long long>,long long>m; 
string str;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>str;
		m.clear();
		p[0] = {0,0};
		m[p[0]] = 0;
		for(i=0;i<n;i++)
		{
			x = 0; y=0;
			if(str[i]=='L')
				x = 1;
			else if(str[i]=='R')
				x = -1;
			else if(str[i]=='U')
				y = 1;
			else if(str[i]=='D')
				y = -1;
			p[i+1] = {p[i].first + x , p[i].second+y};
		}


		// for(i=1;i<=n;i++)
		// {
		// 	cout<<i<<" "<<p[i].first<<" "<<p[i].second<<"\n";
		// }
		// cout<<"\n";

		l = 0; r = 1000000006; flag = false;
		for(i=1;i<=n;i++)
		{
			if(m.find(p[i])!=m.end())
			{
				flag = true;
				len = i - m[p[i]];
				if(len < r-l+1)
				{
					r = i;
					l = m[p[i]] + 1;
				}
			}
			m[p[i]] = i;
		}

		if(flag)
		cout<<l<<" "<<r<<"\n";
		else cout<<"-1\n";
	}
	return 0;
}