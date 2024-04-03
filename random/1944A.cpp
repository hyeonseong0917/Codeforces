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
		int n,k;
		cin>>n>>k;
		if(k>=n-1){
			cout<<1<<"\n";
			continue;
		}else{
			cout<<n<<"\n";
		}
		
	}
	return 0;
}