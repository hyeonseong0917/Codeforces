#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		int N;
		vector<int> v;
		cin>>N;
		for(int i=0;i<N;++i){
			int a=0;
			cin>>a;
			v.push_back(a);
		}
		int ans=0;
		int fst_num=1;
		int sed_num=1;
		for(int i=1;i<N;++i){
			if(v[i]==v[i-1]){
				++fst_num;
			}else{
				break;
			}
		}
		for(int i=N-2;i>=0;--i){
			if(v[i]==v[i+1]){
				++sed_num;
			}else{
				break;
			}
		}
		if(v[0]==v[N-1]){
			ans=N-(fst_num+sed_num);
			ans=max(ans,0);
		}else{
			ans=min(N-fst_num, N-sed_num);
		}
		cout<<ans<<"\n";
	}
	return 0;
}