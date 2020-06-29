#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define fastread ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

ll tc , ns , nt , flag , i , c[30] , x , l , ans , pos;
string s , t;

int main()
{
	cin>>tc;
	while(tc--)
	{
		cin>>s>>t;
		ns = s.length();
		nt = t.length();

		vector<ll>v[30];
		for(i=0;i<ns;i++)
		{
			x = s[i]-'a';
			v[x].push_back(i);
		}

		l = -1; ans=1; i=0; flag = 1;
		while(i<nt)
		{
			x = t[i]-'a';
			if(v[x].size()==0)
			{
				flag = 0; break;
			}

			auto y = upper_bound(v[x].begin(),v[x].end(),l);
			if(y!=v[x].end())
			{
				l = v[x][y-v[x].begin()];
				i++;
			}
			else			
			{
				l = -1;
				ans++;
			}
		}
		if(!flag) cout<<"-1\n";
		else cout<<ans<<"\n";
	}
	return 0;
}