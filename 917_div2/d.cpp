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
		ll N,X,Y;
		cin>>N>>X>>Y;
		vector<ll> v;
		map<pair<ll,ll>,ll> m;
		for(ll i=0;i<N;++i){
			ll a=0;
			cin>>a;
			v.push_back(a);
			++m[{a%X,a%Y}];
		}
		ll cnt=0;
		for(ll i=0;i<N;++i){
			ll cur_num=v[i];
			if(cur_num%X==(X-cur_num%X)%X){
				if(m[{cur_num%X,cur_num%Y}]){
					cnt+=m[{cur_num%X,cur_num%Y}]-1;
					--m[{cur_num%X,cur_num%Y}];
				}
			}else{
				if(m[{cur_num%X, cur_num%Y}] && m[{(X-cur_num%X)%X,cur_num%Y}]){
					cnt+=m[{cur_num%X, cur_num%Y}]*m[{(X-cur_num%X)%X,cur_num%Y}];
					m[{(X-cur_num%X)%X,cur_num%Y}]=0;
					m[{cur_num%X, cur_num%Y}]=0;
				}	
			}
			// cout<<i<<" "<<cnt<<"\n";	
			
		}
		
		cout<<cnt<<"\n";
	}
	return 0;
}