#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	int t=1;
	cin>>t;
	// 1053
	while(t--){
		// a와 b
		// 1. a의 prefix 선택해서 invert하고 reverse
		// a를 b로 최대 3n번 선택해서 바꾸기
		ll n;
		cin>>n;
		string a,b;
		cin>>a;
		cin>>b;
		vector<ll> ans;
		for(ll i=n-1;i>=0;--i){
			if(a[i]!=b[i]){
				// i번째 수가 다름
				if(a[0]!=b[i]){
					// invert후 리버스 하면 그냥 만족
					ans.push_back(i+1);
				}else{
					ans.push_back(1);
					if(a[0]=='1'){
						a[0]='0';
					}else{
						a[0]='1';
					}
					ans.push_back(i+1);
				}
				// [0,i]에 oper 수행
				string k=a.substr(0,i+1);
				for(ll j=0;j<=i;++j){
					if(k[j]=='0'){
						k[j]='1';
					}else{
						k[j]='0';
					}
				}
				reverse(k.begin(),k.end());
				for(ll j=0;j<=i;++j){
					a[j]=k[j];
				}
			}
		}
		if(ans.empty()){
			cout<<0<<"\n";
		}else{
			ll as=ans.size();
			cout<<as<<" ";
			for(ll i=0;i<as;++i){
				cout<<ans[i]<<" ";
			}cout<<"\n";
		}
	} 	

	return 0;
}