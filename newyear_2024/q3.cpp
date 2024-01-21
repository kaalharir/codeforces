#include <bits/stdc++.h>
using namespace std;
int T,n;
int main() 
{
	cin>>T;
	while(T--){
		cin>>n;
		int ans=0;
		int x,a=INT_MAX, b=INT_MAX;
		for(int i=1;i<=n;i++){
			cin>>x;
			if(b>=x) b=x;
			else if(a>=x) a=x;
			else b=a, a=x, ans++;
		}
		cout<<ans<<endl;
	}
}