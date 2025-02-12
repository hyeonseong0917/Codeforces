#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		// a[i]가 0이거나 1
		// 1<=L<=R 골라서 [L:R]을 major로 교체
		// c0>=c1: 0
		// c0<c1: 1
		// [1]로 만들 수 있는지?
		ll n;
		cin>>n;
		string s;
		cin>>s;
		// 0의 연속 구간들을 없앴을 때
		// 0개수<1개수면 가능
		string k="";
		k+=s[0];
		for(ll i=1;i<n;++i){
			ll ks=k.size();
			if(s[i]=='1'){
				k+=s[i];
			}else{
				if(k[ks-1]!='0'){
					k+=s[i];
				}
			}
		}
		// cout<<k<<endl;
		ll zero_num=0, one_num=0;
		for(ll i=0;i<k.size();++i){
			if(k[i]=='1'){
				++one_num;
			}else{
				++zero_num;
			}
		}
		if(zero_num<one_num){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
	} 	

	return 0;
}