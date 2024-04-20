#include <iostream>
#include <vector>
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
		int n,m,k;
		cin>>n>>m>>k;
		if(n%m==0){
			if((n/m)*(m-1)<=k){
				cout<<"NO"<<"\n";
			}else{
				cout<<"YES"<<"\n";
			}
		}else{
			if((n/m)*(m-1)+(n%m-1)<=k){
				cout<<"NO"<<"\n";	
			}else{
				cout<<"YES"<<"\n";	
			}
			
		}

	}
	
	return 0;
}