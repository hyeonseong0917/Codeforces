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
		
		vector<long long> v;
		for(int i=0;i<n;++i){
			long long a=0;
			cin>>a;
			v.push_back(a);
		}
		if(n==1){
			cout<<"NO"<<endl;
			continue;
		}
		long long cnt=0;
		long long one_cnt=0;
		for(int i=0;i<n;++i){
			if(v[i]>1){
				cnt+=(v[i]-1);
			}else{
				one_cnt+=1;
			}
		}
		if(cnt>=one_cnt){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
		cout<<"\n";
	}
	return 0;
}