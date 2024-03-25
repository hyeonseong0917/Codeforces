#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
using namespace std;

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	vector<ll> s;
	while(t--){
		ll N,K;
		cin>>N>>K;
		if(K<=(N+1)/2){
			cout<<2*K-1<<"\n";
		}else{
			ll cur_num=(N+1)/2;
			ll ans;
			int carry=1;
			bool flag=0;
			while(!flag){
				ll M=N/(ll)pow(2,carry); //
				if(M%2==0){
					--M;
				}
				if(cur_num+(M-1)/2+1>=K){
					ll diff=cur_num+(M-1)/2+1-K;
					ll cur_idx=(M-1)/2-diff;
					ans=(ll)pow(2,carry)*(cur_idx*2+1);
					flag=1;
					break;
				}else{
					cur_num+=(M-1)/2+1;
				}
				++carry;
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}