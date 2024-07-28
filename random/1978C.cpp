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
<<<<<<< HEAD
=======
		// cout<<max_sum<<endl;
>>>>>>> 2d4be4502d01d283900b30c1270d44b8dd311e96
		if(k>max_sum){
			cout<<"NO"<<"\n";
			continue;
		}
<<<<<<< HEAD
		vector<ll> ans(n,0);
		if(n>=k){
			for(ll i=0;i<=n-k-1;++i){
				ans[i]=v[i];
			}
			for(ll i=n-k;i<n-1;i+=2){
				ans[i]=v[i+1];
				ans[i+1]=v[i];
			}
		}else{
			ll cs=n;
			ll idx=-1;
			for(ll i=0;i<=(n-1)/2;++i){
				ll diff=n-i-v[i];
				if(k==0) break;
				if(cs>=k){
					idx=i;
					break;
				}
				if(2*(n-i-v[i])>k){
					ans[i]=v[i];
					ans[n-i-1]=v[n-i-1];
					cs-=2;
				}else{
					cs-=2;
					k-=diff*2;
					ans[i]=n+1-v[i];
					ans[n-i-1]=n+1-v[n-i-1];
				}
			}
			if(idx==-1){
				if(n%2==1){
					ans[n/2]=v[n/2];
				}
				for(ll i=0;i<n;++i){
					if(!ans[i]){
						ans[i]=v[i];
					}
				}
			}else{
				for(ll i=idx;i<=idx+cs-k-1;++i){
					ans[i]=v[i];
				}
				for(ll i=idx+cs-k;i<idx+cs-1;i+=2){
					ans[i]=v[i+1];
					ans[i+=1]=v[i];
				}
=======
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
>>>>>>> 2d4be4502d01d283900b30c1270d44b8dd311e96
			}
		}
		cout<<"YES"<<"\n";
		for(ll i=0;i<n;++i){
			cout<<ans[i]<<" ";
		}
		cout<<"\n";
<<<<<<< HEAD
=======
		
		
>>>>>>> 2d4be4502d01d283900b30c1270d44b8dd311e96
	}
	return 0;
}