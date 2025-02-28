#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		ll idx=s.size()-1;
		ll last_idx=-1;
		while(idx>=0){
			if((s[idx]-'0')>=5){
				if(idx==0){
					last_idx=idx;
					break;
				}else{
					// s[idx]에서 반올림 실행, idx>0임
					while(idx>0){
						if((s[idx-1]-'0')==9){
							--idx;
							if(idx==0){
								last_idx=idx;
								break;
							}
						}else{
							s[idx-1]=((s[idx-1]-'0')+1)+'0';
							last_idx=idx;
							--idx;
							// cout<<s[idx]<<endl;
							break;
						}
					}
				}
			}else{
				--idx;
			}
		}
		// cout<<last_idx<<"\n";
		if(last_idx==-1){
			cout<<s<<"\n";
			continue;
		}
		if(last_idx==0){
			s="1"+s;
			for(ll i=1;i<s.size();++i){
				s[i]='0';
			}
		}else{
			for(ll i=last_idx;i<s.size();++i){
				s[i]='0';
			}
		}
		cout<<s<<"\n";
	} 
	return 0;
}