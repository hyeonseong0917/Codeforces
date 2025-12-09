#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int o;
	cin>>o;
	while(o--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll min_num=v[0];
		bool flag=0;
		for(ll i=1;i<n;++i){
			if(v[i]<=min_num){
				min_num=v[i];
			}else{
				// v[i]>=min_num
				ll cur_num=v[i]-(min_num-1);
				if(min_num<cur_num){
					flag=1;
					break;
				}
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