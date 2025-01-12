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
		ll n,m,k;
		cin>>n>>m>>k;
		vector<ll> v(m,0), q(k,0);
		for(ll i=0;i<m;++i){
			cin>>v[i];
		}
		map<ll,ll> check;
		for(ll i =0;i<k;++i){
			cin>>q[i];
			++check[q[i]];
		}
		// 1에서 n까지의 질문에 답해야함
		// v[i]값에 해당하는 질문은 답 안해도 ok
		// 현재 q배열에 해당하는 값들만을 알고 있을 때
		// i번째 값 알아도 1~n까지 답할 수 있는지??
		vector<ll> need;
		for(ll i=1;i<=n;++i){
			if(!check[i]){
				need.push_back(i);
			}
		}
		if(need.empty()){
			for(ll i=0;i<m;++i){
				cout<<1;
			}cout<<"\n";
		}else{
			if(need.size()>=2){
				for(ll i=0;i<m;++i){
					cout<<0;
				}cout<<"\n";
			}else{
				for(ll i=0;i<m;++i){
					if(need[0]==v[i]){
						cout<<1;
					}else{
						cout<<0;
					}
				}cout<<"\n";

			}
		}
		
	} 
	return 0;
}