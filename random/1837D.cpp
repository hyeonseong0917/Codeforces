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
		// 1553
		// 모든 괄호는 한 가지 색
		// 적어도 하나 이상의 괄호가 사용된 색 있어야
		// 같은 색 괄호들만 모았을 때
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		ll max_idx;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(v[i]==n){
				max_idx=i;
			}
		}
		if(n==1){
			cout<<1<<"\n";
			continue;
		}
		if(n==2){
			if(v[0]==2){
				cout<<1<<" "<<2<<"\n";
			}else{
				cout<<2<<" "<<1<<"\n";
			}
			continue;
		}
		vector<ll> ans;
		if(max_idx==0){
			for(ll i=0;i<n;++i){
				if(v[i]==n-1){
					max_idx=i;
				}
			}
		}
		for(ll i=max_idx;i<n;++i){
			ans.push_back(v[i]);
		}
		ll c=0;
		if(max_idx!=n-1){
			ans.push_back(v[max_idx-1]);
			++c;
		}
		
		for(ll i=max_idx-1-c;i>=0;--i){
			if(v[0]<v[i]){
				ans.push_back(v[i]);
			}else{
				for(ll j=0;j<=i;++j){
					ans.push_back(v[j]);
				}
				break;
			}
		}
		for(ll i=0;i<ans.size();++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
	} 
	return 0;
}