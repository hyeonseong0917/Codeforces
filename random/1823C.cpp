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
	cin>>o;
	while(o--){
		ll n;
		cin>>n;
		vector<pair<ll,ll>> v;
		v.push_back({0,0});
		map<ll,ll> m;
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			// a를 소인수분해. 2일때 특별처리
			while(a%2==0 && a>1){
				// cout<<a<<endl;
				if(!m[2]){
					// cout<<a<<endl;
					ll vs=v.size();
					m[2]=vs;
					v.push_back({2,1});
				}else{
					// cout<<a<<endl;
					++v[m[2]].second;
					// cout<<v[1].second<<"fsd"<<endl;
				}
				a/=2;
			}
			// cout<<a<<endl;
			// a가 소수인지?
			bool flag=0;
			ll tmp=a;
			for(ll i=3;i<=sqrt(tmp);i+=2){
				if(a%i==0){
					flag=1;
					while(a%i==0 && a>1){
						if(!m[i]){
							ll vs=v.size();
							m[i]=vs;
							v.push_back({i,1});
						}else{
							++v[m[i]].second;
						}
						a/=i;		
					}
				}
			}
			if(a>1){
				// a는 소수임
				if(!m[a]){
					ll vs=v.size();
					m[a]=vs;
					v.push_back({a,1});
				}else{
					++v[m[a]].second;
				}
			}
			
		}
		ll ans=0;
		// for(ll i=0;i<v.size();++i){
		// 	cout<<v[i].first<<" "<<v[i].second<<endl;
		// }
		ll one_cnt=0;
		ll total_cnt=0;
		for(ll i=1;i<v.size();++i){
			ans+=v[i].second/2;
			total_cnt+=v[i].second;
			if(v[i].second%2==1){
				++one_cnt;
			}
		}
		cout<<ans+one_cnt/3<<"\n";

	}
	return 0;
}