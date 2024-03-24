#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <map>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	ll target=(ll)pow(2,31)-1;
	while(t--){
		ll N;
		cin>>N;
		vector<ll> v(N,0);
		for(ll i=0;i<N;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		ll L=0;
		ll R=N-1;
		ll cnt=N;
		while(L<R){
			if(v[L]+v[R]==target){
				--cnt;
				++L;
				--R;
			}else if(v[L]+v[R]>target){
				--R;
			}else{
				++L;
			}
		}
		cout<<cnt<<"\n";
		
	}
	return 0;
}