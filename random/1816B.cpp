#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<vector<ll>> v;
		for(ll i=0;i<2;++i){
			vector<ll> tmp;
			for(ll j=0;j<n;++j){
				tmp.push_back(0);
			}
			v.push_back(tmp);
		}
		v[0][0]=2*n;
		v[1][n-1]=2*n-1;
		ll min_num=1;
		ll max_num=2*n-2;
		for(ll i=0;i<n-1;++i){
			if(i%2==0){
				v[1][i]=min_num++;
				v[0][i+1]=min_num++;
			}else{
				v[0][i+1]=max_num--;
				v[1][i]=max_num--;
				
			}
		}
		for(ll i=0;i<2;++i){
			for(ll j=0;j<n;++j){
				cout<<v[i][j]<<" ";
			}cout<<"\n";
		}
	} 	

	return 0;
}