#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		if(a==b){
			cout<<c<<"\n";
		}else if(a==c){
			cout<<b<<"\n";
		}else{
			cout<<a<<"\n";
		}

		
	}	
	return 0;
}