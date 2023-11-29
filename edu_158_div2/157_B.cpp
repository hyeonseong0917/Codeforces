#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;

vector<int> a;
int main(){
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int n=0;
		cin>>n;
		a.clear();
		for(int i=0;i<n*2;++i){
			int c=0;
			cin>>c;
			a.push_back(c);
		}
		sort(a.begin(),a.end());
		int ans=0;
		int pre_y=a[0];
		int pre_x=a[n*2-1];
		for(int i=1;i<n;++i){
			ans+=(abs(pre_y-a[i])+abs(pre_x-a[n*2-1-i]));
			pre_y=a[i];
			pre_x=a[n*2-1-i];
		}
		cout<<ans<<"\n";
		for(int i=0;i<n;++i){
			cout<<a[i]<<" "<<a[n*2-i-1]<<"\n";
		}
		
	}
	return 0;
}