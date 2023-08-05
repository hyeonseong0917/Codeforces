#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int n=0;
		cin>>n;
		int cnt=0;
		vector<int> v;
		for(int i=0;i<n;++i){
			int a=0;
			cin>>a;
			v.push_back(a);
		}
		for(int i=0;i<n;++i){
			if(v[i]==i+1){
				++cnt;
			}
		}
		if(cnt%2==0){
			cout<<cnt/2<<"\n";
		}else{
			cout<<(cnt/2)+1<<"\n";

		}
		cout<<"\n";
	}
	return 0;
}