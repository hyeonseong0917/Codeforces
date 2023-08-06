#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int n,k,L,R;
		cin>>n>>k;
		if(n%2==1){
			L=n/2;
			R=(n/2)+1;
		}else{
			L=n/2;
			R=n/2;
		}
		int cnt=0;
		if(k==3){
			cout<<(n/2)+1<<"\n";
			continue;
		}
		while(1){
			int cur_cnt=k-3;
			
			int curL=L;
			int curR=R;
			while(1){
				
				int diff=curR-curL;
				if(diff<0){
					break;
				}
				int tmp=curL;
				curL=diff;
				curR=tmp;
				if(curL<0 || curL>curR){
					break;
				}
				--cur_cnt;
				if(cur_cnt==0){
					break;
				}
			}
			if(cur_cnt==0){
				++cnt;
			}
			--L;
			++R;
			if(L<R-L){
				break;
			}
			// break;
		}
		cout<<cnt<<"\n";
		// cout<<L<<" "<<R<<" "<<cnt<<endl;
	}
	return 0;
}