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
	while(t--){
		ll n;
		cin>>n;
		string s;
		cin>>s;
		if(n==1){
			cout<<0<<"\n";
			continue;
		}
		ll idx=0;
		ll zero_cnt=0;
		ll one_cnt=0;
		while(idx+1<n){
			while(idx+1<n && s[idx]==s[idx+1]){
				if(s[idx]=='0'){
					++zero_cnt;
				}else{
					++one_cnt;
				}
				++idx;
			}
			++idx;
		}
		// cout<<zero_cnt<<" "<<one_cnt<<"\n";
		// 양끝의 수들 필요시쓸수있음
		ll diff=abs(zero_cnt-one_cnt);
		ll one_plus=0;
		ll zero_plus=0;
		if(s[0]=='0'){
			++zero_plus;
		}else{
			++one_plus;
		}
		if(s[n-1]=='0'){
			++zero_plus;
		}else{
			++one_plus;
		}

		if(diff>1){
			if(diff>=4){
				cout<<-1<<"\n";
			}else{
				// 1<diff<=3
				if(diff==3){
					if(zero_cnt<one_cnt){
						if(zero_plus==2){
							cout<<one_cnt*2-1<<"\n";
						}else{
							cout<<-1<<"\n";
						}
					}else{
						if(one_plus==2){
							cout<<zero_cnt*2-1<<"\n";
						}else{
							cout<<-1<<"\n";
						}
					}
				}else{
					if(zero_cnt<one_cnt){
						if(zero_plus>=1){
							cout<<one_cnt*2-1<<"\n";
						}else{
							cout<<-1<<"\n";
						}
					}else{
						if(one_plus>=1){
							cout<<zero_cnt*2-1<<"\n";
						}else{
							cout<<-1<<"\n";
						}
					}
				}
			}
		}else{
			cout<<zero_cnt+one_cnt<<"\n";
		}
	} 	

	return 0;
}