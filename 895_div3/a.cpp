#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		int aa=max(a,b);
		int bb=min(a,b);
		int diff=aa-bb;
		double d=(double)diff/2.0;
		int ans=(d/c);
		double e=ans*c;
		if(ans*c!=d){
			++ans;
		}
		cout<<ans<<endl;
	}
	return 0;
}