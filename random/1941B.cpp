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
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		bool flag=0;
		for(ll i=1;i<=n-2;i+=2){
			if(v[i]<0){
				flag=1;
				break;
			}
			if(i==n-2){
				if(v[i]!=v[i-1]*2 || v[i+1]!=v[i-1]){
					flag=1;
				}else{
					v[i-1]=0;
					v[i]=0;
					v[i+1]=0;
				}
				break;
			}
			ll diff=v[i]-v[i-1]*2;
			if(diff<0 || v[i+1]<diff*2){
				flag=1;
				break;
			}
			v[i+2]-=diff;
			v[i+1]-=diff*2;

			v[i+1]-=v[i-1];
			v[i]=0;
			v[i-1]=0;
		}
		for(ll i=0;i<n;++i){
			if(v[i]!=0){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
		}
	}
	return 0;
}