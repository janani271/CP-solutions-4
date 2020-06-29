#include<bits/stdc++.h>
using namespace std;
long long t , n , s , k , ans , i , a[1005], flag,x ,y;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>s>>k;
		ans=1000000009;
		flag=0;
		for(i=0;i<k;i++)
		{
			cin>>a[i];
			if(a[i]==s)
				flag=1;
		}
		if(!flag)
		{
			cout<<"0\n";
			continue;
		}
		sort(a,a+k);
		for(i=1;i<k;i++)
		{
			x = a[i-1];
			y = a[i];
			if(x<=s && y<=s && y-x > 1)
			{
				ans = min(ans,abs(s - (y-1)));
			}
			if(x>=s && y>=s && y-x>1)
			{
				ans = min(ans,abs(s - (x+1)));		
			}
		}
			if(a[0]>1 && a[0]<=s)
				ans = min(ans,abs(s-(a[0]-1)));
			if(a[k-1]<n && a[k-1]>=s)
				ans = min(ans,abs(s-(a[k-1]+1)));
		cout<<ans<<"\n";
	}
	return 0;
}