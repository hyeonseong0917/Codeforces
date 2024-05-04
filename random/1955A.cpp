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
		int n,a,b;
		cin>>n>>a>>b;
		int ans=0;
		if(n==1){
			cout<<a<<"\n";
		}else{
			if(b<a*2){
				ans+=b*(n/2);
				if(n%2==1){
					ans+=a;
				}
			}else{
				ans+=a*n;
			}
			cout<<ans<<"\n";
		}
		

	}
	
	return 0;
}