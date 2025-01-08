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
	ll t=1;
	cin>>t;
	while(t--){
		ll n,m,q;
		cin>>n>>m>>q;
		vector<ll> a(n,0), b(m,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<m;++i){
			cin>>b[i];
		}
		map<ll,ll> check;
		ll a_idx=0, b_idx=0;
		if(a[0]==b[0]){
			++check[a[0]];
			++a_idx;
			++b_idx;
		}else{
			cout<<"TIDAK"<<"\n";
			continue;
		}
		bool flag=0;
		while(b_idx<m){
			// b_idx에 있는 것을 check에서 처리할 수 있는지?
			if(check[b[b_idx]]){
				++b_idx;
			}else{
				// check에서 처리 못함
				// a_idx의 값으로 처리할 수 있는지?
				if(a_idx<n){
					if(a[a_idx]==b[b_idx]){
						++check[a[a_idx]];
						++a_idx;
						++b_idx;
					}else{
						flag=1;
						break;
					}
				}else{
					// (그럴일은 없겠지만) a다써도 처리 못함
					flag=1;
					break;
				}
			}
		}
		if(flag){
			cout<<"TIDAK"<<"\n";
		}else{
			cout<<"YA"<<"\n";
		}
	}
	return 0;
}