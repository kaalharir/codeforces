#include <bits/stdc++.h>
using namespace std;
int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,sum=0;
		cin>>n;
		string s;
		cin>>s;
		for(int i=0;i<n;i++)
		{
			if(s[i]=='+')
				sum++;
			else
				sum--;
		}
		cout<<abs(sum)<<endl;
	}
	return 0;
}