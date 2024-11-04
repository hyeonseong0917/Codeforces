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
		ll n,k;
		cin>>n>>k;
		if(n==1 && k==1){
			cout<<1<<"\n";
			cout<<1<<"\n";
			continue;
		}
		if(n-k-1<0){
			cout<<-1<<"\n";
		}else{
			ll fst_cnt=k-1;
			ll sed_cnt=n-k;
			if(!fst_cnt || !sed_cnt){
				cout<<-1<<"\n";
				continue;
			}
			if(fst_cnt%2==1 && sed_cnt%2==0){
				cout<<-1<<"\n";
			}else if(fst_cnt%2==0 && sed_cnt%2==1){
				cout<<-1<<"\n";
			}else{
				if(fst_cnt%2==1 && sed_cnt%2==1){
					cout<<3<<"\n";
					cout<<1<<" "<<k<<" "<<k+1<<"\n";
				}else if(fst_cnt%2==0 && sed_cnt%2==0){
					cout<<5<<"\n";
					cout<<1<<" "<<2<<" "<<k<<" "<<k+1<<" "<<k+2<<"\n";
				}
			}
		}
	}
	return 0;
}