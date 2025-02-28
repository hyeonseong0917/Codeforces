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
		ll l,r;
		cin>>l>>r;
		ll c=0;
		// l,r에서 가장 큰 2의 거듭제곱
		for(ll i=1;i<=1000;++i){
			ll cur_num=(ll)pow(2,i);
			if(r<cur_num){
				break;
			}
			if(l<=cur_num && cur_num<=r){
				c=max(c,i);
			}
		}
		cout<<c<<"\n";
	} 
	return 0;
}