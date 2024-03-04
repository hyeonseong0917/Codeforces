#include <iostream>
#include <cmath>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll N;
		cin>>N;
		ll a=1;
		ll cnt=0;
		while(1){
			a=(ll)pow(2,cnt);
			if(a>=N){
				if(a!=N){
					--cnt;
				}
				break;
			}else{
				++cnt;
			}
		}
		cout<<(ll)pow(2,cnt)<<"\n";
	}
	return 0;
}