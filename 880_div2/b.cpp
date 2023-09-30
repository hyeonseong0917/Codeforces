#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,k,g;
		cin>>n>>k>>g;
		ll s=k*g;	
		if(k*g<=(n*((g-1)/2))){
			// cout<<"he";
			cout<<k*g<<"\n";
			continue;
		}
		// n=min(n,(s/(gause_g-1))+1);
		ll sum=0;
		// sum+=(n-1)*((g-1)/2);
		sum+=n*((g-1)/2);
		ll last_num=s-sum;
		sum-=(g-1)/2;
		
		ll r=last_num;
		ll L=((g-1)/2 + r)%g;
		// cout<<sum<<" "<<last_num<<" "<<g<<" "<<L<<endl;
		if(L<((g-1)/2 +1)){
			sum+=L;
		}else{
			sum+=(L-g);
		}
		cout<<sum<<"\n";
	}	
	return 0;
}