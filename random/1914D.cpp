#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define ll long long


bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return a.first>b.first;
}
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
		vector<pair<ll,ll>> a,b,c;
		for(ll i=0;i<n;++i){
			ll k;
			cin>>k;
			a.push_back({k,i});
		}
		for(ll i=0;i<n;++i){
			ll k;
			cin>>k;
			b.push_back({k,i});
		}
		for(ll i=0;i<n;++i){
			ll k;
			cin>>k;
			c.push_back({k,i});
		}
		sort(a.begin(),a.end(),comp);
		sort(b.begin(),b.end(),comp);
		sort(c.begin(),c.end(),comp);
		vector<ll> ss,mm,bb;
		for(ll i=0;i<3;++i){
			ss.push_back(a[i].second);
			mm.push_back(b[i].second);
			bb.push_back(c[i].second);
			// cout<<ss[i]<<" "<<mm[i]<<" "<<bb[i]<<"\n";
		}
		ll ans=0;
		for(ll i=0;i<3;++i){
			for(ll j=0;j<3;++j){
				for(ll k=0;k<3;++k){
					// cout<<i<<" "<<j<<" "<<k<<endl;
					// cout<<ss[i]<<" "<<mm[j]<<" "<<bb[k]<<"\n";
					if(ss[i]!=mm[j] && mm[j]!=bb[k] && ss[i]!=bb[k]){
						ll cur_ans=0;
						for(ll q=0;q<n;++q){
							if(ss[i]==a[q].second){
								cur_ans+=a[q].first;
							}
							if(mm[j]==b[q].second){
								cur_ans+=b[q].first;
							}
							if(bb[k]==c[q].second){
								cur_ans+=c[q].first;
							}
						}
						// cout<<ss[i]<<" "<<bb[j]<<" "<<mm[k]<<" "<<cur_ans<<"\n";
						ans=max(cur_ans,ans);
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}