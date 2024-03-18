#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll N=0;
		cin>>N;
		vector<ll> v(N,0);
		vector<ll> d(N,0);
		vector<ll> r(N,0);
		for(ll i=0;i<N;++i){
			cin>>v[i];
		}
		d[1]=(ll)1;
		for(ll i=1;i<N-1;++i){
			if(abs(v[i]-v[i-1])<abs(v[i]-v[i+1])){
				d[i+1]=d[i]+abs(v[i]-v[i+1]);
			}else{
				d[i+1]=d[i]+1;
			}
			
		}
		r[N-2]=(ll)1;
		for(ll i=N-2;i>=1;--i){
			if(abs(v[i]-v[i-1])>abs(v[i]-v[i+1])){
				r[i-1]=r[i]+abs(v[i]-v[i-1]);	
			}else{
				r[i-1]=r[i]+1;
			}	
		}
		
		ll M;
		cin>>M;
		for(ll i=0;i<M;++i){
			ll a,b;
			cin>>a>>b;
			if(a<b){
				cout<<d[b-1]-d[a-1]<<"\n";
			}else{
				cout<<r[b-1]-r[a-1]<<"\n";
			}
		}
		// for(ll i=0;i<N;++i){
		// 	cout<<i<<" "<<d[i]<<"\n";
		// }
	}
	return 0;
}