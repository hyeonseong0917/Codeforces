#include <iostream>
#include <vector>
using namespace std;

//1555
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	vector<int> v;
	while(t--){
		int x,k=0;
		cin>>x>>k;
		int cnt=0;
		int m=x;
		v.clear();
		int sum=0;
		while(1){
			if(sum==x){
				break;
			}
			if(m%k==0){
				// ++cnt;
				--m;
			}else{
				sum+=m;
				v.push_back(m);
				m=x-m;
				
				// cout<<m<<"\n";
			}
		}
		cout<<v.size()<<endl;
		for(int i=0;i<v.size();++i){
			cout<<v[i]<<" ";
		}cout<<endl;
	}
	return 0;
}