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
	int t=0;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		ll k=n+m+1;
		vector<vector<ll>> a;
		vector<ll> tmp(k,0);
		for(ll i=0;i<k;++i){
			cin>>tmp[i];
		}
		a.push_back(tmp);
		tmp=vector<ll>(k,0);
		for(ll i=0;i<k;++i){
			cin>>tmp[i];
		}
		a.push_back(tmp);
		// cout<<a[1][0];
        ll idx=-1;
        ll idx_type=-1;
        vector<ll> cur_cnt(2,0);
        vector<ll> target={n,m};
        ll ans=0;
        vector<ll> cur_type(k,0);
        for(ll i=0;i<k-1;++i){
        	ll tmp_type=0;
        	if(a[0][i]<a[1][i]){
        		tmp_type=1;
        	}
        	if(cur_cnt[tmp_type]==target[tmp_type]){
        		tmp_type=1-tmp_type;
        		if(idx==-1){
        			idx=i;
        			idx_type=1-tmp_type;
        		}
        	}
        	cur_type[i]=tmp_type;
        	++cur_cnt[tmp_type];
        	ans+=a[tmp_type][i];
        	// cout<<ans<<"\n";
        }
        vector<ll> res;
        for(ll i=0;i<k-1;++i){
        	ll val=ans-a[cur_type[i]][i];
        	if(idx!=-1 && idx>i && cur_type[i]==idx_type){
        		val+=a[idx_type][idx]-a[1-idx_type][idx]+a[1-idx_type][k-1];
        	}else{
        		val+=a[cur_type[i]][k-1];
        	}
        	res.push_back(val);
       		// cout<<i<<" "<<val<<endl;
        }
        res.push_back(ans);
        for(ll i=0;i<k;++i){
        	cout<<res[i]<<" ";
        }cout<<"\n";
		

	}
	return 0;
}