#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
#include <stack>
#include <deque>
using namespace std;

#define ll long long

ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		string p,s;
		cin>>p;
		cin>>s;
		// s가 p의 결과가 될 수 있는지?
		ll ps=p.size();
		ll ss=s.size();
		if(ss>ps*2){
			cout<<"NO"<<"\n";
			continue;
		}
		ll p_idx=0, s_idx=0;
		bool flag=0;
		while(1){
			if(p_idx==ps && s_idx==ss){
				break;
			}
			if(p_idx==ps || s_idx==ss){
				flag=1;
				break;
			}
			if(p[p_idx]!=s[s_idx]){
				flag=1;
				break;
			}
			char c=p[p_idx];
			// c의 현재 구간을 구한다
			ll p_cnt=0;
			for(ll i=p_idx;i<ps;++i){
				if(p[i]==c){
					++p_cnt;
				}else{
					break;
				}
			}
			ll s_cnt=0;
			for(ll i=s_idx;i<ss;++i){
				if(s[i]==c){
					++s_cnt;
				}else{
					break;
				}
			}
			if(s_cnt>=p_cnt && p_cnt*2>=s_cnt){
				s_idx+=s_cnt;
				p_idx+=p_cnt;
			}else{
				flag=1;
				break;
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