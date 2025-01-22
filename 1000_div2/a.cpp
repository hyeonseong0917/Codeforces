#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll o;
	cin>>o;
	while(o--){
		ll L,R;
		cin>>L>>R;
		if(L==R){
			if(L!=1){
				cout<<0<<"\n";
			}else{
				cout<<1<<"\n";
			}
		}else{
			cout<<R-L<<"\n";
		}
	}
	return 0;
}