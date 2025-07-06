#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	
	ll t=1;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		ll max_odd=-1;
		bool flag=0;
		for(ll i=0;i<n;++i){
			if(v[i]%2==1){
				max_odd=v[i];
			}
		}
		if(max_odd==-1){
			cout<<v[n-1]<<"\n";
			continue;
		}
		vector<ll> tmp;
		for(ll i=0;i<n;++i){
			if(v[i]==max_odd && !flag){
				flag=1;
			}else{
				tmp.push_back(v[i]);
			}
		}
		vector<ll> odd_vec, even_vec;
		for(ll i=0;i<n-1;++i){
			if(tmp[i]%2==0){
				even_vec.push_back(tmp[i]);
			}else{
				odd_vec.push_back(tmp[i]);
			}
		}
		if(even_vec.empty()){
			cout<<max_odd<<"\n";
		}else{
			for(ll i=0;i<even_vec.size();++i){
				max_odd+=even_vec[i];
			}
			for(ll i=0;i<odd_vec.size();++i){
				max_odd+=odd_vec[i]-1;
			}
			cout<<max_odd<<"\n";
		}
	}
	return 0;
}