#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
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
		ll min_num=1222232421;
		ll min_idx=-1;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(min_num>v[i]){
				min_num=v[i];
				min_idx=i;
			}
		}
		bool flag=0;
		for(ll i=min_idx+1;i<n-1;++i){
			if(v[i]>v[i+1]){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<-1<<"\n";
			continue;
		}
		cout<<min_idx<<"\n";
		
		
	} 
	return 0;
}