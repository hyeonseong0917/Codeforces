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
		string a,b;
		cin>>a;
		cin>>b;
		ll zero_cnt=0;
		ll one_cnt=0;
		vector<bool> is_change(n,0);
		for(ll i=0;i<n;++i){
			if(a[i]=='0'){
				++zero_cnt;
			}else{
				++one_cnt;
			}
			if(zero_cnt==one_cnt){
				is_change[i]=1;
			}
		}
		bool flag=0;
		ll cnt=0;
		for(ll i=n-1;i>=0;--i){
			char c=a[i];
			if(cnt%2==1){
				if(c=='0'){
					c='1';
				}else{
					c='0';
				}
			}
			if(c!=b[i]){
				if(!is_change[i]){
					flag=1;
					break;
				}
				++cnt;
			}
		}
		if(flag){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
		}
	} 

	return 0;
}