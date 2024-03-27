#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,m;
		cin>>n>>m;
		vector<ll> a;
		string s;
		ll cur_sum=1;
		for(ll i=0;i<n;++i){
			ll c=0;
			cin>>c;
			a.push_back(c);
		}
		cin>>s;
		ll L=0, R=n-1;
		for(ll i=0;i<n-1;++i){
			if(s[i]=='L'){
				++L;
			}else{
				--R;
			}
		}
		vector<ll> ans;
		ans.push_back(a[L]%m);
		ll cur_num=a[L]%m;
		for(ll i=n-2;i>=0;--i){
			if(s[i]=='L'){
				--L;
				cur_num*=a[L];
				cur_num%=m;
				ans.push_back(cur_num);
			}else{
				++R;
				cur_num*=a[R];
				cur_num%=m;
				ans.push_back(cur_num);
			}
		}
		// cout<<L<<" "<<R<<endl;
		reverse(ans.begin(),ans.end());
		for(ll i=0;i<n;++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
		
	}
	
	return 0;
}