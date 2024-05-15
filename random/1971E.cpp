#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,k,q;
		cin>>n>>k>>q;
		vector<ll> a(k+1),b(k+1);
		a[0]=0;
		b[0]=0;
		for(ll i=1;i<=k;++i){
			cin>>a[i];
		}
		for(ll i=1;i<=k;++i){
			cin>>b[i];
		}
		vector<ll> ans;
		for(ll i=0;i<q;++i){
			ll d;
			cin>>d;
			ll L=0, R=k-1;
			ll cur_idx=-1;
			while(L<=R){
				ll mid=(L+R)/2;
				if(a[mid]<=d){
					cur_idx=max(cur_idx,mid);
					L=mid+1;
				}else{
					R=mid-1;
				}
			}
			ll cur_num=b[cur_idx]+(d-a[cur_idx])*(b[cur_idx+1]-b[cur_idx])/(a[cur_idx+1]-a[cur_idx]);
			ans.push_back(cur_num);
		}
		for(ll i=0;i<ans.size();++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
	}
	
	return 0;
}