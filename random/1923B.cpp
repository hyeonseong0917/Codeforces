#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
bool comp(pair<ll,ll> a, pair<ll,ll> b){
	if(a.first==b.first){
		return a.second<b.second;
	}
	return a.first<b.first;
}
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		vector<ll> a(n,0); //체력
		vector<ll> x(n,0); //위치
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<n;++i){
			cin>>x[i];
			if(x[i]<0){
				x[i]*=-1;
			}
		}
		vector<pair<ll,ll>> v(n,{(ll)0,(ll)0});
		for(ll i=0;i<n;++i){
			v[i]={x[i],a[i]};
		}
		sort(v.begin(),v.end(),comp);
		ll idx=0;
		bool flag=0;
		ll cnt=0;
		bool is_clear=0;
		while(1){
			ll cur_bullet=k;
			for(ll i=idx;i<n;++i){
				if(v[i].first<=cnt){
					flag=1;
					break;
				}
				if(v[i].second>cur_bullet){
					idx=i;
					v[i].second-=cur_bullet;
					break;
				}else if(v[i].second<=cur_bullet){
					cur_bullet-=v[i].second;
					v[i].second=0;
					if(i==n-1){
						is_clear=1;
					}
				}
			}
			// cout<<cur_bullet<<"\n";
			if(is_clear){
				break;
			}
			if(flag){
				break;
			}
			++cnt;
		}
		if(is_clear){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
	}
	return 0;
}