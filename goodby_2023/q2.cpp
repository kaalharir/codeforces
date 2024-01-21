#include<bits/stdc++.h>
using namespace std;
long long t,a,b;
int main()
{
	cin>>t;
	while(t--){
		cin>>a>>b;
		if(b%a==0)
			cout<<a/__gcd(a,b)*b*(b/a)<<endl;
		else
			cout<<a/__gcd(a,b)*b<<endl;
	}
	return 0;
}