#include<bits/stdc++.h>
using namespace std;
long long  a , t , n , sum , i; 
bool even, odd;
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		sum = 0;
		odd=false; even=false;
		for(i=0;i<n;i++)
		{
			cin>>a;
			sum += a;
			if(a&1)
				odd=true;
			else even=true;
		}
		if(sum&1 || (even&&odd))
		{
			cout<<"YES";
		}
		else cout<<"NO";
		cout<<"\n";
	}
	return 0;
}