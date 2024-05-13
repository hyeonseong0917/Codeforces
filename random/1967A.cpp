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
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		reverse(v.begin(),v.end());
		ll s=v[n-1];
		ll cnt=1;
		ll idx=n-1;
		for(ll i=n-2;i>=0;--i){
			if(v[i]==s){
				++cnt;
			}else{
				idx=i;
				break;
			}
		}
		// cout<<idx<<" "<<cnt<<endl;
		if(idx==n-1){
			cout<<(s-1)*n+n-cnt+k+1<<"\n";	
			continue;
		}
		while(idx>=0){
			if((v[idx]-s)*cnt>k) break;
			// cout<<s<<endl;
			k-=(v[idx]-s)*cnt;
			s=v[idx];
			int tmp_idx=idx;
			for(ll i=idx;i>=0;--i){
				if(v[i]!=s){
					idx=i;
					break;
				}else{
					++cnt;
				}
			}
			if(tmp_idx==idx){
				break;
			}
		}
		// cout<<s<<endl;
		s+=(k/cnt);
		// cout<<s<<" "<<cnt<<endl;
		k%=cnt;
		cout<<(s-1)*n+n-cnt+k+1<<"\n";
		
	}
	return 0;
}