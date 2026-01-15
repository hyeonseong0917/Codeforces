#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long
#define pb push_back

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
		vector<ll> odd_vec, even_vec;
		ll max_num=0;
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			max_num=max(max_num,a);
			if(a%2==0){
				even_vec.pb(a);
			}else{
				odd_vec.pb(a);
			}
		}
		if(even_vec.empty() || odd_vec.empty()){
			cout<<max_num<<"\n";
			continue;
		}
		sort(even_vec.begin(),even_vec.end());
		sort(odd_vec.begin(),odd_vec.end());
		max_num=odd_vec[odd_vec.size()-1];
		for(ll i=0;i<even_vec.size();++i){
			max_num+=even_vec[i];
		}
		for(ll i=0;i<odd_vec.size()-1;++i){
			max_num+=odd_vec[i]-1;
		}
		cout<<max_num<<"\n";
	}
	return 0;
}