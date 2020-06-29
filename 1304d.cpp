#include<bits/stdc++.h>
using namespace std;
#define ll long long

ll t , n , i , j , ans[200009];
string s;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n>>s;
		for(i=0;i<n;i++)
			ans[i] = n-i;
		i = 0;
		while(i<n)
		{
			j = i;
			while(s[j]=='<') j++;
				reverse(ans+i,ans+j+1);
			i = j; i++; 
		}
		for(i=0;i<n;i++)
			cout<<ans[i]<<" ";
		cout<<"\n";

		for(i=0;i<n;i++)
			ans[i] = i+1;
		i = 0;
		while(i<n)
		{
			j = i;
			while(s[j]=='>') j++;
				reverse(ans+i,ans+j+1);
			i = j; i++; 
		}
		for(i=0;i<n;i++)
			cout<<ans[i]<<" ";
		cout<<"\n";			
	}
	return 0;
}