#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long

const int MAX=1000+1;

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	
	while(t--){
		int ans=0;
		string s;
		string target="1234567890";
		cin>>s;
		char cur_num='1';
		for(int i=0;i<s.size();++i){
			char c=s[i];
			//cur_num에서 c까지 가야함
			int cur_idx=0;
			int target_idx=0;
			for(int j=0;j<target.size();++j){
				if(target[j]==c){
					target_idx=j;
				}
				if(target[j]==cur_num){
					cur_idx=j;
				}
			}
			ans+=(abs(target_idx-cur_idx))+1;
			cur_num=c;
		}
		cout<<ans<<"\n";
		
	}	
	return 0;
}