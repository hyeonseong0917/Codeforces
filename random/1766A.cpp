#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		// 1<=x<=n인 extreme 구하기
		ll n;
		cin>>n;
		ll ans=0;
		ans+=min(n,9ll);
		ll cur_num=10;
		while(cur_num<=n){
			ans+=min(n/cur_num,9ll);
			cur_num*=10;
		}
		cout<<ans<<"\n";
	} 
	return 0;
}