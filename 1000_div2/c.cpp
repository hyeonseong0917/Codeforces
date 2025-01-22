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
	ll o;
	cin>>o;
	while(o--){
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		map<ll,ll> check;
		vector<ll> unique_num;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			if(!check[v[i]]){
				unique_num.push_back(v[i]);
			}
			++check[v[i]];
		}
		sort(unique_num.begin(),unique_num.end());
		ll k_num=0;
		map<ll,ll> visited;
		for(ll i=0;i<unique_num.size();++i){
			ll cur_num=unique_num[i];
			// cout<<cur_num<<endl;
			if(!visited[cur_num] && !visited[k-cur_num]){
				visited[cur_num]=1;
				visited[k-cur_num]=1;
				if(cur_num==k-cur_num){
					k_num+=check[cur_num]/2;
				}else{
					k_num+=min(check[cur_num],check[k-cur_num]);
				}
				// k_num+=check[k-cur_num]*check[cur_num];
			}
		}
		// cout<<k_num<<endl;
		if((n-k_num*2)%2==0){
			cout<<k_num<<"\n";
		}else{
			cout<<max((ll)0,k_num-1)<<"\n";
		}
	}
	return 0;
}