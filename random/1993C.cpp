#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(n==1){
			cout<<v[0]<<"\n";
			continue;
		}
		sort(v.begin(),v.end());
		ll max_start_num=0;
		ll min_fin_num=-1;
		for(ll i=0;i<n-1;++i){
			ll q=(v[n-1]-(v[i]+k-1)+2*k-1)/(2*k);
			max_start_num=max(max_start_num,v[i]+k*2*q);
			if(min_fin_num==-1){
				min_fin_num=v[i]+k*2*q+k-1;
			}else{
				min_fin_num=min(min_fin_num, v[i]+k*2*q+k-1);
			}
			// cout<<max_start_num<<endl;
		}
		if(max_start_num>v[n-1]+k-1){
			cout<<-1<<"\n";
		}else{
			if(min_fin_num<max_start_num){
				cout<<-1<<"\n";
			}else{
				cout<<max(max_start_num,v[n-1])<<"\n";
			}
		}
	}
	
	return 0;
}