#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int o=1;
	cin>>o;
	while(o--){
		ll n;
		cin>>n;
		if(n==1){
			cout<<0<<"\n";
			continue;
		}
		// n을 1로 만들기
		ll ans=0;
		while(n>1){
			bool flag=0;
			if(n%5==0){
				++ans;
				n=(n/5)*4;
				flag=1;
			}else if(n%3==0){
				++ans;
				n=(n/3)*2;
				flag=1;
			}else if(n%2==0){
				++ans;
				n=n/2;
				flag=1;
			}
			if(!flag){
				break;
			}
		}
		if(n==1){
			cout<<ans<<"\n";
		}else{
			cout<<-1<<"\n";
		}
	} 

	return 0;
}