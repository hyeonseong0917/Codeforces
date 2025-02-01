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
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		map<ll,ll> k_check;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			++k_check[v[i]];
		}
		sort(v.begin(),v.end());
		vector<ll> p;
		for(ll i=0;i<n;++i){
			if(k_check[v[i]]>=k){
				p.push_back(v[i]);
			}
		}
		ll L=0,R=0;
		ll ans_L=0, ans_R=0;
		ll ans=0;
		map<ll,ll> check;
		if(p.empty()){
			cout<<-1<<"\n";
			continue;
		}
		ll ps=p.size();

		R=1;
		while(R<ps){
			if(p[R]==p[R-1]+1 || p[R]==p[R-1]){
				if(ans<p[R]-p[L]+1){
					ans=p[R]-p[L]+1;
					ans_L=L;
					ans_R=R;
				}
				++R;
			}else{
				if(ans<p[R-1]-p[L]+1){
					ans=p[R-1]-p[L]+1;
					ans_L=L;
					ans_R=R-1;
				}
				L=R;
				++R;
			}
		}
		cout<<p[ans_L]<<" "<<p[ans_R]<<"\n";
	} 
	return 0;
}