#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	vector<ll> v;
	map<ll,ll> m;
	while(t--){
		ll n;
		cin>>n;
		v.clear();
		m.clear();	
		ll N=0;
		for(ll i=0;i<n;++i){
			ll a=0;
			cin>>a;
			if(!m[a]){
				m[a]=1;
				++N;
				v.push_back(a);
			}
		}
		sort(v.begin(),v.end());
		ll ans=1;
		ll L,R=0;
		for(ll i=0;i<N;++i){
			L=i;
			while(R<N){
				if(v[R]<v[L]+n){
					++R;
				}else{
					break;
				}
			}
			ans=max(ans,R-L);
		}
		cout<<ans<<"\n";
	}	
	return 0;
}