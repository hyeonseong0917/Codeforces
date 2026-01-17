#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n+1,0);
		bool one_flag=0;
		bool zero_flag=0;
		for(ll i=1;i<=n;++i){
			cin>>v[i];
			if(v[i]){
				one_flag=1;
			}
			if(!v[i]){
				zero_flag=1;
			}
		}
		if(!zero_flag){
			// 0이 없는경우
			cout<<1<<"\n";
			cout<<1<<" "<<n<<"\n";
			continue;
		}
		if(!one_flag){
			// 모두 0인 경우
			cout<<3<<"\n";
			cout<<3<<" "<<n<<"\n";
			cout<<1<<" "<<2<<"\n";
			cout<<1<<" "<<2<<"\n";
			continue;
		}

		vector<ll> tmp;
		tmp.push_back(0);
		vector<pair<ll,ll>> ans;
		if(!v[1] && !v[n]){
			ll a=1;
			if(v[2]==1){
				++a;
			}
			tmp.push_back(a);
			for(ll i=3;i<n-1;++i){
				tmp.push_back(v[i]);
			}
			a=1;
			if(v[n-1]==1){
				++a;
			}
			tmp.push_back(a);
			ans.push_back({n-1,n});
			ans.push_back({1,2});
		}else{
			if(!v[1] || !v[n]){
				if(!v[1]){
					ll a=1;
					if(v[2]==1){
						++a;
					}
					tmp.push_back(a);
					for(ll i=3;i<=n;++i){
						tmp.push_back(v[i]);
					}		
					ans.push_back({1,2});
				}else{
					for(ll i=1;i<n-1;++i){
						tmp.push_back(v[i]);
					}		
					ll a=1;
					if(v[n-1]==1){
						++a;
					}
					tmp.push_back(a);
					// cout<<n-1<<"fds "<<n<<endl|
					ans.push_back({n-1,n});
				}
			}else{
				tmp.clear();
				tmp=v;
			}
		}
		// tmp의 양쪽 끝은 0이 아닌 상태임
		ll ts=tmp.size()-1;
		ll idx=ts;
		ll cur_len=ts;
		while(idx>=1){
			if(tmp[idx]){
				--idx;
			}else{
				ll c=idx;
				while(c>=0){
					--c;
					if(tmp[c]){
						++c;
						break;
					}
				}
				// [c,idx]가 0인 구간임
				if(c==idx){
					ans.push_back({c,c+1});
					--cur_len;
					--idx;
				}else{
					ans.push_back({c,idx});
					cur_len-=idx-c;
					idx=c-1;
				}
			}
		}
		if(cur_len!=1){
			ans.push_back({1,cur_len});
		}
		ll as=ans.size();
		cout<<as<<"\n";
		for(ll i=0;i<as;++i){
			cout<<ans[i].first<<" "<<ans[i].second<<"\n";
		}

	}
	return 0;
}