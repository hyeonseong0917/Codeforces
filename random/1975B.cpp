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
		sort(v.begin(),v.end());
		bool flag=0;
		ll idx=-1;
		for(ll i=1;i<n;++i){
			if(v[i]%v[0]!=0){
				idx=i;
				break;
			}
		}
		if(idx==-1){
			cout<<"YES"<<"\n";
		}else{
			// cout<<idx<<endl;
			for(ll i=idx+1;i<n;++i){
				if(v[i]%v[idx]!=0 && v[i]%v[0]!=0){
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
	} 
	return 0;
}