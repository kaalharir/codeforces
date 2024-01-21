#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		if(n==1)
			cout<<1<<'\n';
		else{
			for(int i=0;i<n/2;i++){
				cout<<1<<string(i, '0') <<6 << string(i, '0') <<9<< string(n-3-i*2,'0')<<'\n';
				cout<<9<<string(i, '0') <<6 << string(i, '0') <<1<< string(n-3-i*2, '0')<<'\n';
			}
			cout<<196<< string(n-3, '0')<<'\n';
		}
	}
	return 0;
}