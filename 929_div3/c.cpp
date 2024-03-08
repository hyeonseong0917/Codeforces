#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		int a,b,l;
		cin>>a>>b>>l;
		int tmp;
		if(a>b){
			tmp=a;
			a=b;
			b=tmp;
		}
		int m=1;
		int tmp_a=a;
		while(tmp_a<b){
			tmp_a*=a;
			++m;
		}
		int cnt=0;
		int cur_a=1;
		while(l%cur_a==0){
			cur_a*=a;
			++cnt;
		}
		if(tmp_a==b){	
			cout<<cnt<<"\n";
		}else{
			int b_cnt=0;
			int cur_b=1;
			while(l%cur_b==0){
				cur_b*=b;
				++b_cnt;
			}
			map<int,int> m;
			// cout<<cnt<<" "<<b_cnt<<"\n";
			int ans=0;
			for(int i=0;i<cnt;++i){
				for(int j=0;j<b_cnt;++j){
					int cur_sum=pow(a,i)*pow(b,j);
					
					if(cur_sum<=l && l%cur_sum==0 && !m[cur_sum]){
						m[cur_sum]=1;
						// cout<<cur_sum<<"\n";
						++ans;
					}
				}
			}
			cout<<ans<<"\n";
		}

	}
	return 0;
}