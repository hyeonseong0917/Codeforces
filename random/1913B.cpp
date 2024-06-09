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
		string s;
		cin>>s;
		string t;
		int n=s.size();
		int one_cnt=0, zero_cnt=0;
		for(int i=0;i<n;++i){
			if(s[i]=='1'){
				++one_cnt;
				t+='0';
			}else{
				++zero_cnt;
				t+='1';
			}
		}
		int ans=0;
		for(int i=0;i<n;++i){
			if(t[i]=='1'){
				if(one_cnt==0){
					ans=n-i;
					break;
				}else{
					--one_cnt;
				}
			}else{
				if(zero_cnt==0){
					ans=n-i;
					break;
				}else{
					--zero_cnt;
				}
			}
		}
		cout<<ans<<"\n";


	} 
	return 0;
}