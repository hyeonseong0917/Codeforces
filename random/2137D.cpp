#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
#define pb push_back

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
		vector<ll> b(n,0);
		vector<ll> v[n+1];
		vector<ll> check(n+1,0);
		for(ll i=0;i<n;++i){
			cin>>b[i];
			v[b[i]].push_back(i);
		}
		bool flag=0;
		vector<ll> a(n,0);
		ll cnt=1;
		for(ll i=0;i<n;++i){
			if(check[b[i]]) continue;
			++check[b[i]];
			ll vs=v[b[i]].size();
			if(vs%b[i]!=0){
				flag=1;
				break;
			}
			for(ll j=0;j<vs;++j){
				if(j%b[i]==0 && j){
					++cnt;
				}
				a[v[b[i]][j]]=cnt;
			}
			++cnt;
		}
		if(flag){
			cout<<-1<<"\n";
			continue;
		}
		for(ll i=0;i<n;++i){
			cout<<a[i]<<" ";
		}cout<<"\n";
	}
	return 0;
}