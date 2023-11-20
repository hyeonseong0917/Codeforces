#include <iostream>
#include <vector>
using namespace std;

//1555
#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int n=0;
		cin>>n;
		bool flag=0;
		ll cur_s=0;
		ll cur_e=0;
		for(int i=0;i<n;++i){
			ll a,b;
			cin>>a>>b;
			if(i==0){
				cur_s=a;
				cur_e=b;
			}else{
				if(cur_s<=a && cur_e<=b){
					flag=1;
				}
			}
		}
		if(flag){
			cout<<-1<<"\n";
		}else{
			cout<<cur_s<<"\n";
		}
		
	}
	return 0;
}