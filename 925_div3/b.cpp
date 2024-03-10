#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int N;
		vector<int> v;
		cin>>N;
		int sum=0;
		for(int i=0;i<N;++i){
			int a=0;
			cin>>a;
			sum+=a;
			v.push_back(a);
		}
		sum/=N;
		bool flag=0;
		for(int i=0;i<N;++i){
			if(i==N-1){
				if(v[i]!=sum){
					flag=1;
				}
				break;
			}
			if(v[i]>sum){
				v[i+1]+=v[i]-sum;
				v[i]-=sum;
			}else if(v[i]<sum){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
		}

	}
	return 0;
}