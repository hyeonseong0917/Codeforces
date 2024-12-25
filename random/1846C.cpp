#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,m,h;
		cin>>n>>m>>h;
		vector<vector<ll>> v;
		for(ll i=0;i<n;++i){
			vector<ll> tmp;
			for(ll j=0;j<m;++j){
				ll a=0;
				cin>>a;
				tmp.push_back(a);
			}
			sort(tmp.begin(),tmp.end());
			v.push_back(tmp);
		}
		
		vector<ll> psum(m,0);
		psum[0]=v[0][0];
		for(ll i=1;i<m;++i){
			psum[i]=psum[i-1]+v[0][i];
		}
		vector<ll> ppsum(m,0);
		ppsum[0]=psum[0];
		ll sum=0;
		ll cnt=0;
		for(ll i=1;i<m;++i){
			ppsum[i]=ppsum[i-1]+psum[i];
		}
		for(ll i=0;i<m;++i){
			if(psum[i]<=h){
				sum=ppsum[i];
				++cnt;
			}
		}
		ll rank=1;
		// sum, cnt, rank
		for(ll i=1;i<n;++i){
			ll cur_sum=0, cur_cnt=0;
			psum[0]=v[i][0];
			for(ll j=1;j<m;++j){
				psum[j]=psum[j-1]+v[i][j];
			}
			ppsum[0]=psum[0];
			for(ll j=1;j<m;++j){
				ppsum[j]=ppsum[j-1]+psum[j];
			}
			for(ll j=0;j<m;++j){
				if(psum[j]<=h){
					cur_sum=ppsum[j];
					++cur_cnt;
				}else{
					break;
				}
			}
			if(cur_cnt>cnt){
				++rank;
			}else if(cur_cnt==cnt){
				if(cur_sum<sum){
					++rank;
				}
			}
		}
		cout<<rank<<"\n";
	} 
	return 0;
}