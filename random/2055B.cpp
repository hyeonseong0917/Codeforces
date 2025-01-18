#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

bool comp(pair<ll,ll> a, pair<ll,ll> b){
	if(a.second<b.second){
		return a.first<b.first;
	}
	return a.second<b.second;
}
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		bool flag=0;
		vector<ll> a(n,0), b(n,0);
		ll max_num=2023101800;
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		ll idx=-1;
		ll sum=0;
		for(ll i=0;i<n;++i){
			cin>>b[i];
			if(a[i]<b[i]){
				if(idx!=-1){
					flag=1;
				}
				idx=i;
				sum=b[i]-a[i];
			}else{
				max_num=min(max_num,a[i]-b[i]);
			}
		}
		if(flag){
			cout<<"NO"<<"\n";
		}else{
			if(max_num>=sum){
				cout<<"YES"<<"\n";
			}else{
				cout<<"NO"<<"\n";
			}
		}
		
		// 0 1 6 7 7
		// 3 0 4 4 4
	} 
	return 0;
}