#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll test , n , m , i , t, h, l, lt , ht , ti ,pt; 
bool flag;
int main()
{
	cin>>test;
	while(test--)
	{
		cin>>n>>m;
		flag = true;

		for(i=0;i<n;i++)
		{
			cin>>t>>l>>h;
			if(i==0)
			{
				ti = t - 0;
				lt = m-ti;
				ht = m+ti;
			}
			else
			{
				ti = t - pt;
				lt = lt - ti;
				ht = ht + ti;
			}
			lt = max(lt,l);
			ht = min(ht,h);
			if(lt>ht)
			{
				flag = false;
			}
			pt = t;
		}

		if(flag) cout<<"YES\n";
		else cout<<"NO\n";
	}
	return 0;
}