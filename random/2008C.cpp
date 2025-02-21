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
		ll L,R;
		cin>>L>>R;
		ll ans=0;
		if(L==R){
			cout<<1<<"\n";
			continue;
		}
		ll lx=1, rx=100000;
		ll max_idx=-1;
		while(lx<=rx){2
			ll mid=(lx+rx)/2;
			if(L+mid*(mid+1)/2<=R){
				max_idx=max(max_idx,mid);
				lx=mid+1;
			}else{
				rx=mid-1;
			}
		}
		cout<<max_idx+1<<"\n";
	} 	

	return 0;
}