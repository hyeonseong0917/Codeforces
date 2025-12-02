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
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		ll fin_pos=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			fin_pos=max(fin_pos,v[i]);
		}
		
		ll cur_pos=v[k-1];
		if(fin_pos==cur_pos){
			cout<<"YES"<<"\n";
			continue;
		}
		ll cur_water=1;
		vector<ll> p;
		map<ll,ll> m;
		for(ll i=0;i<n;++i){
			if(v[i]>cur_pos && !m[v[i]]){
				++m[v[i]];
				p.push_back(v[i]);
			}
		}
		sort(p.begin(),p.end());
		// cout<<cur_pos<<" "<<p[0]<<endl;
		bool flag=0;
		for(ll i=0;i<p.size();++i){
			ll diff=p[i]-cur_pos;
			ll death_count_down=cur_pos-cur_water+1;
			// cout<<i<<" "<<p[i]<<" "<<diff<<" "<<death_count_down<<endl;
			if(diff<=death_count_down){
				cur_pos=p[i];
				cur_water+=diff;
			}else{
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

	return 0;
}