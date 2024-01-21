#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>> t;
	while (t--){
		int n;
		cin>>n;
		int cnt[2] = {};
		long long sum =0;
		for(int i=1;i<=n;i++){
			int a;
			cin>>a;
			cnt[a%2]++;
			sum += a;
			cout<<sum-cnt[1]/3-(i>1 && cnt[1]%3==1) << ' ';
		}
		cout<<'\n';
	}
	return 0;
}

