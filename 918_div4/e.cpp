#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	vector<ll> s;
	while(t--){
		ll n,c=0;
		cin>>n>>c;
		s.clear();
		for(ll i=0;i<n;++i){
			ll a=0;
			cin>>a;
			s.push_back(a);
		}
		
		ll L=1;
		ll R=1000000000;
		ll W=1;
		while(L<=R){
			ll mid=(ll)(L+R)/(ll)2;
			ll sum=0;
			// cout<<L<<" "<<R<<endl;
			bool flag=0;
			for(ll i=0;i<s.size();++i){
				ll cur_num=(s[i]+(mid*2))*(s[i]+(mid*2));
				// cout<<cur_num<<"\n";
				if(sum>9223372036854775807-cur_num){
					flag=1;
					break;
				}
				sum+=cur_num;
				
			}
			if(flag==1){
				R=mid-1;
				continue;
			}
			// cout<<sum<<" "<<L<<" "<<R<<"\n";
			if(sum<c){
				L=mid+1;
			}else if(sum>c){
				R=mid-1;
			}else{
				W=mid;
				break;
			}
		}
		cout<<W<<"\n";
		// cout<<"\n";
		
	}
	return 0;
}