#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	vector<int> a;
	vector<int> v;
	while(t--){
		int n,k;
		cin>>n>>k;
		a.clear();
		v.clear();
		for(int i=0;i<n;++i){
			int x=0;
			cin>>x;
			a.push_back(x);
		}
		sort(a.begin(),a.end());
		if(n==1){
			cout<<0<<"\n";
			// cout<<endl;
			continue;
		}
		int sum=0;
		int preIdx=0;
		for(int i=0;i<n-1;++i){
			v.push_back(a[i+1]-a[i]);
		}
		int max_conseq=0;
		int cnt=0;
		for(int i=0;i<v.size();++i){
			if(v[i]<=k){
				++cnt;
			}else{
				max_conseq=max(max_conseq,cnt);
				cnt=0;
			}
		}
		max_conseq=max(max_conseq,cnt);
		cout<<a.size()-(max_conseq+1)<<"\n";
		// cout<<endl;		
	}
	return 0;
}