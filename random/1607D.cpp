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
		ll n;
		cin>>n;
		vector<ll> a(n,0);
		vector<char> b(n,'a');
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<n;++i){
			cin>>b[i];
		}
		vector<ll> R;
		vector<ll> B;
		for(ll i=0;i<n;++i){
			if(b[i]=='R'){
				R.push_back(a[i]);
			}else{
				B.push_back(a[i]);
			}
		}
		sort(R.begin(),R.end());
		sort(B.begin(),B.end());
		ll cur_num=1;
		bool flag=0;
		for(ll i=0;i<B.size();++i){
			if(cur_num<=B[i]){
				++cur_num;
			}else{
				flag=1;
				break;
			}
		}
		for(ll i=0;i<R.size();++i){
			if(cur_num>=R[i]){
				++cur_num;
			}else{
				flag=1;
				break;
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