#include <iostream>
#include <algorithm>
#include <vector>
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
		vector<pair<pair<ll,ll>,pair<ll,ll>>> v;
		for(ll i=0;i<n;++i){
			ll a,b,c,d;
			cin>>a>>b>>c>>d;
			v.push_back({{a,b},{c,d}});
		}
		// 1. 0먼저 다 옮기기
		ll ans=0;
		for(ll i=0;i<n;++i){
			if(v[i].first.first<=v[i].second.first){
				// 다른 인덱스로부터 받아와야함 0을
				ans+=v[i].second.first-v[i].first.first;
			}
		}
		// cout<<ans<<"\n";
		// 1. 1옮기기
		for(ll i=0;i<n;++i){
			ll a=v[i].first.first;
			ll b=v[i].first.second;
			ll c=v[i].second.first;
			ll d=v[i].second.second;
			if(b<=d){
				// 다른 인덱스로부터 받아와야함 1을
				ans+=d-b;
			}else{
				// 주는 입장일 경우 1을 넘기려면 위의 0을 모두 청산해야하는데?
				ans+=min(a,c);
			}
		}
		cout<<ans<<"\n";

	}
	return 0;
}