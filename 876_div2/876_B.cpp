#include <iostream>
using namespace std;
//1017
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int n=0;
		cin>>n;
		int cnt=0, res=0;
		for(int i=0;i<n;++i){
			int a=0;
			cin>>a;
			if(a==0){
				++cnt;
			}else{
				res=max(res,cnt);
				cnt=0;
			}
		}
		res=max(res,cnt);
		cout<<res<<endl;
	}
	return 0;
}