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
	
	ll t=1;
	cin>>t;
	while(t--){
		ll n,c,d;
		cin>>n>>c>>d;
		ll ans=0;
		vector<ll> a(n,0);
		map<ll,ll> check;
		vector<ll> v;
		ll sum=0;
		for(ll i=0;i<n;++i){
			cin>>a[i];
			if(check[a[i]]){
				ans+=c;
				sum+=c;
			}else{
				++check[a[i]];
				v.push_back(a[i]);
			}
		}
		sort(v.begin(),v.end());
		ll vs=v.size();
		ans+=c*vs+d; // 현재 ans는 중복제거하고, 다 지우고 1만 추가한 상태
		ll cur_num=0;
		for(ll i=0;i<v.size();++i){
			ll L=c*(v.size()-i);
			if(i==0){
				L+=d;
			}
			if(L<d*(v[i]-cur_num-1)){
				sum+=L;
				break;
			}
			ans=min(ans,sum+L);
			sum+=d*(v[i]-cur_num-1);
			cur_num=v[i];
		}
		ans=min(ans,sum);
		cout<<ans<<"\n";
	}
	return 0;
}