#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int o=1;
	cin>>o;
	while(o--){
		ll n;
		cin>>n;
		string s;
		cin>>s;
		bool flag=0;
		ll a_cnt=0;
		ll b_cnt=0;
		for(ll i=0;i<n;++i){
			if(s[i]=='a'){
				++a_cnt;
			}else if(s[i]=='b'){
				++b_cnt;
			}
		}
		a_cnt=(n+1)/2-a_cnt;
		b_cnt=n/2-b_cnt;
		if(n%2==1){
			// s[0]=ababa
			if(s[0]=='b'){
				flag=1;
			}else if(s[0]=='?'){
				if(!a_cnt){
					flag=1;
				}else{
					--a_cnt;
				}
			}
			// a ab ba
			ll x=1;
			while(x*2<n){
				char fst_char=s[x*2-1];
				char sed_char=s[x*2];
				if(fst_char==sed_char && fst_char=='?'){
					if(!a_cnt || !b_cnt){
						flag=1;
						break;
					}
					--a_cnt;
					--b_cnt;
				}else{
					if(fst_char==sed_char){
						flag=1;
						break;
					}
					if(fst_char=='?'){
						if(sed_char=='a'){
							if(b_cnt==0){
								flag=1;
								break;
							}else{
								--b_cnt;
							}
						}else{
							if(a_cnt==0){
								flag=1;
								break;
							}else{
								--a_cnt;
							}
						}
					}
					if(sed_char=='?'){
						if(fst_char=='a'){
							if(b_cnt==0){
								flag=1;
								break;
							}else{
								--b_cnt;
							}
						}else{
							if(a_cnt==0){
								flag=1;
								break;
							}else{
								--a_cnt;
							}
						}
					}
				}

				++x;
			}
		}else{
			// s=ababab
			// ab ba ab
			ll x=0;
			while(x*2+1<n){
				char fst_char=s[x*2];
				char sed_char=s[x*2+1];
				if(fst_char==sed_char && fst_char=='?'){
					if(!a_cnt || !b_cnt){
						flag=1;
						break;
					}
					--a_cnt;
					--b_cnt;
				}else{
					if(fst_char==sed_char){
						flag=1;
						break;
					}
					if(fst_char=='?'){
						if(sed_char=='a'){
							if(b_cnt==0){
								flag=1;
								break;
							}else{
								--b_cnt;
							}
						}else{
							if(a_cnt==0){
								flag=1;
								break;
							}else{
								--a_cnt;
							}
						}
					}
					if(sed_char=='?'){
						if(fst_char=='a'){
							if(b_cnt==0){
								flag=1;
								break;
							}else{
								--b_cnt;
							}
						}else{
							if(a_cnt==0){
								flag=1;
								break;
							}else{
								--a_cnt;
							}
						}
					}
				}

				++x;
			}
		}
		if(flag){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
		}
	} 

	return 0;
}