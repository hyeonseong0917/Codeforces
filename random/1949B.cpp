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
		int n;
		cin>>n;
		vector<int> a(n,0), b(n,0);
		for(int i=0;i<n;++i){
			cin>>a[i];
		}
		for(int i=0;i<n;++i){
			cin>>b[i];
		}
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());
		int max_diff=-1222232421;
		for(int t=0;t<n;++t){
			int min_diff=1222232421;
			for(int i=0;i<=t;++i){
				min_diff=min(min_diff,abs(a[i]-b[i+n-t-1]));
			}
			for(int i=t+1;i<n;++i){
				min_diff=min(min_diff,abs(a[i]-b[i-t-1]));	
			}
			max_diff=max(max_diff,min_diff);
		}
		cout<<max_diff<<"\n";
	}
	return 0;
}