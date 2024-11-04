#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		bool is_odd=0, is_even=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(v[i]%2==0){
				is_even=1;
			}else{
				is_odd=1;
			}
		}
		if(is_even && is_odd){
			cout<<-1<<"\n";
			continue;
		}
		vector<ll> ans;
		for(ll i=29;i>=0;--i){
			ans.push_back(1<<i);
		}
		if(is_even) ans.push_back(1);
		ll as=ans.size();
		cout<<as<<"\n";
		for(ll i=0;i<as;++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
	}
	return 0;
}