#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
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
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		vector<ll> a;
		a.push_back(0);
		// for(ll i=1;i<n-1;++i){
		// 	if(v[i-1]==v[i+1] && v[i-1]!=v[i]){
		// 		a.push_back(i);
		// 	}
		// }
		int idx=1;
		while(idx<n-1){
			if(v[idx-1]==v[idx+1] && v[idx-1]!=v[idx]){
				a.push_back(idx);
				idx+=2;
			}else{
				++idx;
			}
		}
		if(a.size()==1){
			cout<<-1<<"\n";
			continue;
		}
		
		a.push_back(n-1);
		// for(int i=0;i<a.size();++i){
		// 	cout<<a[i]<<" ";
		// }cout<<endl;
		vector<ll> diff;
		for(ll i=0;i<a.size()-1;++i){
			if(i==0 || i==a.size()-2){
				diff.push_back(a[i+1]-a[i]);	
			}else{
				diff.push_back(a[i+1]-a[i]-1);	
			}
			
		}
		sort(diff.begin(),diff.end());
		// for(int i=0;i<diff.size();++i){
		// 	cout<<diff[i]<<" ";
		// }cout<<endl;
		cout<<diff[0]<<"\n";
	} 
	return 0;
}