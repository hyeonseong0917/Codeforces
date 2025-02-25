#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long
ll mod=998244353;
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,k;
        cin>>n>>k;
        vector<ll> v(n,0);
        bool flag=0;
        for(ll i=0;i<n;++i){
            cin>>v[i];
            if(v[i]==k){
                flag=1;
            }
        }
        if(flag){
            cout<<"YES"<<"\n";
        }else{
            cout<<"NO"<<"\n";
        }

	} 
	return 0;
}