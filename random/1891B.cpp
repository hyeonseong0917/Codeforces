#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define ll long long

const int MAX=30+1;

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		ll n,q;
		cin>>n>>q;
		vector<ll> a(n,0), x(q,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<q;++i){
			cin>>x[i];
		}
		vector<ll> v[MAX];
		for(ll i=0;i<n;++i){
			ll cur_num=a[i];
			ll cnt=0;
			while(1){
				if(cur_num%2==0){
					cur_num/=2;
					++cnt;
				}else{
					break;
				}
			}
			v[cnt].push_back(i);
		}
		for(ll i=0;i<q;++i){
			ll cur_q=x[i];
			for(ll j=cur_q;j<MAX;++j){
				vector<ll> tmp;
				for(ll k=0;k<v[j].size();++k){
					tmp.push_back(v[j][k]);
					a[v[j][k]]+=(ll)pow(2,cur_q-1);
				}
				v[j].clear();
				for(ll k=0;k<tmp.size();++k){
					v[cur_q-1].push_back(tmp[k]);
				}
			}
		}
		for(ll i=0;i<n;++i){
			cout<<a[i]<<" ";
		}cout<<"\n";
	}
	return 0;
}