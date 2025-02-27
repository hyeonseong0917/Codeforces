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
		string s;
		cin>>s;
		vector<ll> v(n,0);
		// 000111010이면 
		// 00001
		// 55111
		for(ll i=0;i<n;++i){
			cin>>v[i];	
		}
		if(n==1){
			if(s[0]=='1'){
				cout<<v[0]<<"\n";
			}else{
				cout<<0<<"\n";
			}
			continue;
		}
		// 0 1 1 1에서 최솟값 idx찾는다
		// 5 4 5 1

		// 0 1 1 1
		// 5 1 4 5

		ll idx=0;
		ll ans=0;
		while(idx<n){
			if(s[idx]=='0' && idx+1<n && s[idx+1]=='1'){
				ll next_idx=idx+1;
				ll min_num=min(v[idx],v[idx+1]);
				ll sum=v[idx]+v[idx+1];
				while(next_idx+1<n){
					if(s[next_idx+1]=='1'){
						++next_idx;
						if(v[next_idx]<min_num){
							min_num=v[next_idx];
						}
						sum+=v[next_idx];
					}else{
						break;
					}
				}
				sum-=min_num;
				ans+=sum;
				idx=next_idx+1;
			}else{
				if(s[idx]=='1'){
					ans+=v[idx];
				}
				++idx;
			}
		}
		
		
		
		cout<<ans<<"\n";
	} 
	return 0;
}