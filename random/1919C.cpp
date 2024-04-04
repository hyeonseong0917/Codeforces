#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		vector<ll> a,b;
		ll cnt=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		a.push_back(v[0]);
		for(ll i=1;i<n;++i){
			ll cur_num=v[i];
			if(b.empty()){
				// cout<<i<<endl;
				if(cur_num>a[a.size()-1]){
					b.push_back(cur_num);
				}else{
					// cout<<cur_num<<" "<<i<<" "<<a[i]<<endl;
					a.push_back(cur_num);

				}
			}else{
				if(a[a.size()-1]<cur_num && b[b.size()-1]<cur_num){
					// cout<<i<<endl;
					++cnt;
					if(a[a.size()-1]<b[b.size()-1]){
						a.push_back(cur_num);
					}else{
						b.push_back(cur_num);
					}
					continue;
				}
				if(a[a.size()-1]>cur_num && b[b.size()-1]>cur_num){
					if(a[a.size()-1]<b[b.size()-1]){
						a.push_back(cur_num);
					}else{
						b.push_back(cur_num);
					}
					continue;	
				}
				if(a[a.size()-1]>cur_num && b[b.size()-1]<cur_num){
					a.push_back(cur_num);
					continue;	
				}
				if(a[a.size()-1]<cur_num && b[b.size()-1]>cur_num){
					b.push_back(cur_num);
					continue;	
				}
			}
		}
		cout<<cnt<<"\n";
	}
	
	return 0;
}