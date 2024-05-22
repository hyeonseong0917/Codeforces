#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define ll long long
map<ll,ll> m;
int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		ll a,b;
		cin>>a>>b;
		if(a==1){
			ll c=pow(2,b);
			++m[c];
		}else{
			if(b==0){
				cout<<"YES"<<"\n";
				continue;
			}
			ll cur_num=b;
			ll c=1;
			ll k=0;
			while(1){
				if(c>cur_num){
					c/=2;
					--k;
					break;
				}
				c*=2;
				++k;
			}
			while(k>=0){
				ll seg_num=pow(2,k);
				if(m[seg_num]){
					// cur_num에 seg_num이 몇 번 들어갈 수 있을지?
					ll L=0, R=m[seg_num];
					ll max_val=-1;
					while(L<=R){
						ll mid=(L+R)/2; // seg_num이 mid번 들어간다면?
						if(cur_num>=seg_num*mid){
							max_val=max(max_val,mid);
							L=mid+1;
						}else{
							R=mid-1;
						}
					}
					if(max_val!=-1){
						cur_num-=seg_num*max_val;
					}
				}
				--k;
			}
			if(cur_num==0){
				cout<<"YES"<<"\n";
			}else{
				cout<<"NO"<<"\n";
			}
		}
	}
	return 0;
}