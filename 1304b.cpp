#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll n , c , i , mn;

bool flag;

string s[103] , r[103] , ans1 , ans2, pal;

map<string,long long>m;

int main()
{
	cin>>n>>mn;
	c=0;
	for(i=0;i<n;i++)
	{
		cin>>s[i];
		r[i] = s[i];
		reverse(r[i].begin(),r[i].end());
		
		m[s[i]]++;

		if(m[r[i]]!=0 && s[i]!=r[i])
			m[r[i]]++;
		
		if(m[r[i]]==2)
		{
			c += 2;
			ans1 += s[i];
			ans2 += s[i];
		}
		if(s[i]==r[i] && !flag)
		{
			c++;
			pal = s[i];
			flag = true;
		}	
	}

	if(flag)
		ans1 += pal;

	reverse(ans2.begin(),ans2.end());
	ans1 += ans2;

	cout<<c*mn<<"\n";
	cout<<ans1<<"\n";

	return 0;
}