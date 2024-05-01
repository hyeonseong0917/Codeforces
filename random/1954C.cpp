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
		string x,y;
		cin>>x;
		cin>>y;
		bool is_big_x=0;
		for(int i=0;i<x.size();++i){
			if(x[i]>y[i]){
				is_big_x=1;
				break;
			}else if(x[i]==y[i]){
				continue;
			}else{
				break;
			}
		}
		string tmp;
		if(is_big_x){
			tmp=x;
			x=y;
			y=tmp;
		}
		int idx=0;
		for(int i=0;i<x.size();++i){
			idx=i;
			if(x[i]<y[i]){
				break;
			}
		}
		
		for(int i=idx+1;i<x.size();++i){
			if(x[i]<y[i]){
				char tmp_char=x[i];
				x[i]=y[i];
				y[i]=tmp_char;
			}
		}
		cout<<x<<"\n";
		cout<<y<<"\n";

		
	}
	return 0;
}