#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long
int main() {
	// your code goes here 1301
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		ll N;
		cin>>N;
		ll p=(N+1)/2;
		--p;
		vector<ll> v(N,0);
		for(ll i=0;i<N;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		ll cur_num=v[p];
		ll ans=1;
		for(ll i=p+1;i<N;++i){
			if(v[i]<cur_num+1){
				ans+=(cur_num+1-v[i]);	
			}
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}