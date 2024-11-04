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
	int o=1;
	while(o--){
		ll n;
		cin>>n;
		if(n==1){
			cout<<"권병장님, 중대장님이 찾으십니다";
			break;
		}
		vector<ll> a(n,0), b(n-1,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<n-1;++i){
			cin>>b[i];
		}
		ll last_pos=a[n-1];
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n-1;++i){
			v.push_back({a[i],b[i]});
		}
		ll cur_pos=v[0].second;
		bool flag=0;
		for(ll i=1;i<n-1;++i){
			if(cur_pos<v[i].first){
				flag=1;
				break;
			}
			cur_pos=max(cur_pos,v[i].first+v[i].second);
		}
		if(cur_pos<last_pos){
			flag=1;
		}
		if(flag){
			// cout<<"nono";
			cout<<"엄마 나 전역 늦어질 것 같아";
		}else{
			// cout<<"yes";
			cout<<"권병장님, 중대장님이 찾으십니다";
		}
	}
	return 0;
}