#include<bits/stdc++.h>
using namespace std;
long long n , t , i , sum, odd , s[3005];
string str; 
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		cin>>str;
		sum=0; odd=0;
		for(i=0;i<n;i++)
		{
			s[i] = str[i]-'0';
			sum += s[i];
			if(s[i]&1)
				odd++;
		}
		if(odd==0)
			cout<<"-1";
		else
		{
			//last pos odd number
			for(i=n-1;i>=0;i--)
			{
				if(s[i]&1)
					break;
				else
				{
					sum -= s[i];
					s[i] = -1;
				}
			}

			// cout<<"\nnumber after last pos odd: ";
			// for(i=0;i<n;i++)
			// {
			// 	cout<<s[i];
			// }
			// cout<<"\n";

			if(sum%2==1)
			{
				if(odd>1)
				{
					for(i=0;i<n-1;i++)
					{
						if(s[i]&1)
						{	
							sum -= s[i];
							s[i] = -1;
							break;
						}
					}
				}
			}

			if(sum>0 && sum%2==0)
			{
				for(i=0;i<n;i++)
				{
					if(s[i]>0)
						cout<<s[i];
				}
			}
			else cout<<"-1";
		}
		cout<<"\n";
	}
	return 0;
}