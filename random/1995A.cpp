#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

const int MAX=1000+1;


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o;
	cin>>o;
	while(o--){
		ll n,k;
		cin>>n>>k;
		if(k==0){
			cout<<0<<"\n";
		}else{
			ll cnt=1;
			k-=n;
			for(ll i=n-1;i>=1;--i){
				if(k<=0) break;
				for(ll j=0;j<2;++j){
					if(k<=0) break;
					k-=i;
					++cnt;
				}
			}
			cout<<cnt<<"\n";
		}
	}
	return 0;
}