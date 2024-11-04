#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll a;
		cin>>a;
		ll b=a/4;
		ll c=a%4;
		c/=2;
		cout<<b+c<<"\n";
		cout<<"\n";
	} 
	return 0;
}