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
		ll a,b;
		cin>>a>>b;
		if(a==0 || b==0){
			if(a==0){
				if(b%2==0){
					cout<<"YES"<<"\n";
				}else{
					cout<<"NO"<<"\n";
				}
			}else{
				if(a%2==0){
					cout<<"YES"<<"\n";
				}else{
					cout<<"NO"<<"\n";
				}
			}
		}else{
			if(a%2==0 && b%2==0){
				cout<<"YES"<<"\n";
			}else{
				if(a%2==1 && b%2==0){
					cout<<"NO"<<"\n";
				}else if(a%2==0 && b%2==1){
					cout<<"YES"<<"\n";
				}else{
					cout<<"NO"<<"\n";
				}
			}
		}
	} 	

	return 0;
}