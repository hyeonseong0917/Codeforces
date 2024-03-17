#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		string s;
		ll N;
		cin>>N;
		cin>>s;
		string t=s;
		reverse(t.begin(),t.end());
		cout<<min(s,t+s)<<"\n";

	}
	return 0;
}