#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,c,d;
		cin>>n>>c>>d;
		vector<ll> v(n*n,0);
		map<ll,ll> m;
		for(ll i=0;i<n*n;++i){
			cin>>v[i];
			++m[v[i]];
		}
		sort(v.begin(),v.end());
		ll cnt=0;
		bool flag=0;
		ll a=v[0];
		while(cnt<n*n && !flag){
			if(m[a]){
				for(ll i=a;i<=a+d*(n-1);i+=d){
					if(m[i]){
						--m[i];
						++cnt;
					}else{
						flag=1;
						break;
					}
				}
			}else{
				flag=1;
				break;
			}
			a+=c;
		}
		if(!flag){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
	} 
	return 0;
}