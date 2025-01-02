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
		ll n;
		cin>>n;
		string s;
		cin>>s;
		ll s_cnt=0;
		ll p_cnt=0;
		for(ll i=0;i<n;++i){
			if(s[i]=='s'){
				++s_cnt;
			}
			if(s[i]=='p'){
				++p_cnt;
			}
		}
		if(s_cnt==0 || p_cnt==0){
			cout<<"YES"<<"\n";
			continue;
		}
		if(s[0]=='.' && s[n-1]=='.'){
			// 양쪽 다 .이고 s와 p로 이루어짐
			cout<<"NO"<<"\n";
			continue;
		}
		if(s[0]=='.'){
			ll new_p_cnt=0;
			for(ll i=0;i<n-1;++i){
				if(s[i]=='p'){
					++new_p_cnt;
				}
			}
			if(new_p_cnt==0){
				cout<<"YES"<<"\n";
			}else{
				cout<<"NO"<<"\n";
			}
		}else if(s[n-1]=='.'){
			if(s[0]=='s'){
				ll new_p_cnt=0;
				ll new_s_cnt=0;
				for(ll i=1;i<n;++i){
					if(s[i]=='p'){
						++new_p_cnt;
					}
					if(s[i]=='s'){
						++new_s_cnt;
					}
				}
				if(new_p_cnt==0 || new_s_cnt==0){
					cout<<"YES"<<"\n";
				}else{
					cout<<"NO"<<"\n";
				}
			}else{
				cout<<"NO"<<"\n";
			}
		}else{
			if(s[0]=='s' && s[n-1]=='p'){
				ll new_p_cnt=0;
				ll new_s_cnt=0;
				for(ll i=1;i<n-1;++i){
					if(s[i]=='p'){
						++new_p_cnt;
					}
					if(s[i]=='s'){
						++new_s_cnt;
					}
				}
				if(new_p_cnt==0 || new_s_cnt==0){
					cout<<"YES"<<"\n";
				}else{
					cout<<"NO"<<"\n";
				}
			}else{
				cout<<"NO"<<"\n";
			}
		}
	}
	return 0;
}