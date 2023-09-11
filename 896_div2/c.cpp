#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int l,r;
		cin>>l>>r;
		if(l==r){
			if(l%2==0){
				int ll=l/2;
				if(ll==1){
					cout<<-1<<endl;
				}else{
					cout<<ll<<" "<<ll<<endl;
				}
			}else{
				int ll=l;
				if(ll/2==0){
					cout<<-1<<endl;
				}else{
					int idx=-1;
					for(int i=3;i<=sqrt(ll);++i){
						if(ll%i==0){
							idx=i;
							break;
						}
					}
					if(idx==-1){
						cout<<-1<<endl;
					}else{
						cout<<ll/idx<<" "<<ll-(ll/idx)<<endl;
					}
				}
			}
		}else{
			int cur_num=r;
			if(r%2==1){
				cur_num-=1;
			}
			int a=cur_num/2;
			if(a==1){
				cout<<-1<<endl;
			}else{
				cout<<a<<" "<<a<<endl;
			}
		}
		cout<<endl;
	}
	return 0;
}