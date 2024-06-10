#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
bool comp(pair<ll,ll> a, pair<ll,ll> b){
	if(a.first==b.first){
		a.second<b.second;
	}
	return a.first>b.first;
}
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			v.push_back({a,i});
		}
		sort(v.begin(),v.end(),comp);
		ll L=1;
		ll R=1000000000;
		vector<ll> ans(n,0);
		ll a;
		while(L<=R){
			bool flag=0;
			ll mid=(L+R)/2;
			ll sum=mid;
			ll fst_num=(sum+v[0].first-1)/v[0].first;
			ll sed_num=(sum+v[n-1].first-1)/v[n-1].first;
			ll cur_num=sum-(fst_num+sed_num);
			for(ll i=1;i<n-1;++i){
				cur_num-=(cur_num+v[i].first-1)/v[i].first;
				if(cur_num<0){
					flag=1;
					break;
				}
			}
			if(flag){
				L=mid+1;
			}else{
				cur_num=sum-(fst_num+sed_num);
				cout<<cur_num<<endl;
				ans[v[0].second]=fst_num;
				ans[v[n-1].second]=sed_num;
				for(ll i=1;i<n-1;++i){
					ans[v[i].second]=(cur_num+v[i].first-1)/v[i].first;
					cur_num-=(cur_num+v[i].first-1)/v[i].first;
				}
				break;
			}
		}
		if(ans.empty()){
			cout<<-1<<"\n";
		}else{
			for(ll i=0;i<n;++i){
				cout<<ans[i]<<" ";
			}cout<<"\n";	
		}
		
	} 
	return 0;
}