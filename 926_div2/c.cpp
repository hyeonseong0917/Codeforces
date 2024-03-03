#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cmath>
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
		ll k,x,a;
		cin>>k>>x>>a;
		ll init_num=a;
		ll ans=0;
		if(x<=k-1){
			if((a-x)*k>a){
				cout<<"YES"<<"\n";
			}else{
				cout<<"NO"<<"\n";
			}
		}else{
			bool flag=0;
			ll idx=k;
			a-=k-1;
			if(a<=0){
				cout<<"NO"<<"\n";
				continue;
			}
			ll cnt=2;
			while(1){
				if(idx==x+1){
					break;
				}
				if(a+cnt*(k-1)<=init_num){
					cnt=(init_num-a)/(k-1);
					++cnt;
					continue;
				}
				if(cnt>a){
					flag=1;
					break;
				}
				a-=cnt;
				++idx;
			}
			if(a*k<=init_num){
				flag=1;
			}
			if(flag){
				cout<<"NO"<<"\n";
			}else{
				cout<<"YES"<<"\n";
			}
		}

	}	
	return 0;
}