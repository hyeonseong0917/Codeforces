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
		if(k%2==1){
			cout<<"NO"<<"\n";
			continue;
		}
		vector<ll> v(n,0);
		ll max_sum=0;
		for(ll i=0;i<n;++i){
			v[i]=i+1;
			max_sum+=abs(n-i-v[i]);
		}
		// cout<<max_sum<<endl;
		if(k>max_sum){
			cout<<"NO"<<"\n";
			continue;
		}
		bool flag=0;
		vector<ll> ans(n,0);
		if(n>=k){
			ans[0]=v[k/2];
			ans[k/2]=v[0];
		}else{
			for(ll i=0;i<n;++i){
				if(k==0) break;
				ll diff=(n-i-v[i])*2;
				if(k<diff){		
					ans[i]=v[i+k/2];
					ans[i+k/2]=v[i];
                    break;
                }else{
					// k>=diff
					k-=diff;
                    ans[i]=v[n-i-1];
                    ans[n-i-1]=v[i];
                }
			}
		}
		for(ll i=0;i<n;++i){
			if(!ans[i]){
				ans[i]=v[i];
			}
		}
		cout<<"YES"<<"\n";
		for(ll i=0;i<n;++i){
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
		
		
	}
	return 0;
}