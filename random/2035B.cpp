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
		ll n;
		cin>>n;
		if(n<=4){
			if(n==1){
				cout<<-1<<"\n";
			}else if(n==2){
				cout<<66<<"\n";
			}else if(n==3){
				cout<<-1<<"\n";
			}else{
				cout<<3366<<"\n";
			}
		}else{
			if(n%2==0){
				for(ll i=0;i<n-2;++i){
					cout<<3;
				}
				cout<<66<<"\n";
			}else{
				for(ll i=0;i<n-4;++i){
					cout<<3;
				}
				cout<<6;
				cout<<366<<"\n";
			}
		}
	}
	return 0;
}