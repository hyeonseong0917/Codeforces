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
		ll a,b;
		cin>>a>>b;
		string s;
		cin>>s;
		ll n=s.size();
		ll L=0, R=n-1;
		// ??010?0
		ll cnt0=0,cnt1=0;
		for(ll i=0;i<n;++i){
			if(s[i]=='1'){
				++cnt1;
			}else if(s[i]=='0'){
				++cnt0;
			}
		}
		a=a-cnt0;
		b=b-cnt1;
		if(a<0 || b<0){
			cout<<-1<<"\n";
			continue;
		}
		// 앞으로 0을 a개 채워야 하고, 1을 b개 채워야함
		bool flag=0;
		while(L<R){
			if(s[L]!='?' && s[R]!='?'){
				if(s[L]!=s[R]){
					flag=1;
					break;
				}
				++L;
				--R;
				continue;
			}else if(s[L]=='?' && s[R]=='?'){
				++L;
				--R;
			}else{
				if(s[L]=='?'){
					s[L]=s[R];
					if(s[L]=='0'){
						--a;
					}else{
						--b;
					}
				}else{
					s[R]=s[L];
					if(s[L]=='0'){
						--a;
					}else{
						--b;
					}
				}
				++L;
				--R;
			}
		}
		if(a<0 || b<0 || flag){
			cout<<-1<<"\n";
			continue;
		}
		// ? ? 쌍이랑 중간에 하나 (있을수도 없을수도) ?
		flag=0;
		if(n%2==1){
			if(s[n/2]=='?'){
				if(a%2==1 && b%2==1){
					flag=1;
				}else if(a%2==0 && b%2==0){
					flag=1;
				}else{
					if(a%2==1){
						--a;
						s[n/2]='0';
					}else{
						--b;
						s[n/2]='1';
					}
				}
			}
		}
		if(flag){
			cout<<-1<<"\n";
			continue;
		}
		// a개의 0과 b개의 1을 채워야함
		L=0, R=n-1;
		while(L<R){
			if(s[L]=='?' && s[R]=='?'){
				if(a>1){
					s[L]='0';
					s[R]='0';
					a-=2;
				}else{
					s[L]='1';
					s[R]='1';
					b-=2;
				}
			}
			++L;
			--R;
		}
		if(a!=0 && b!=0){
			cout<<-1<<"\n";
		}else{
			cout<<s<<"\n";
		}

	} 

	return 0;
}