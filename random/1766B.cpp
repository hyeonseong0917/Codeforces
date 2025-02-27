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
		ll n;
		cin>>n;
		string s;
		cin>>s;
		if(n==1){
			cout<<"NO"<<"\n";
			continue;
		}
		// n보다 적은 횟수로 가능?
		// 복사 연산을 한 번이라도 쓸 수 있는지?
		// 길이 2 이상의 substring 복사 가능?
		// 길이 2인 문자열 겹치는 게 있는지?
		bool flag=0;
		vector<string> v;
		map<string,ll> m;
		for(ll i=0;i+1<n;++i){
			v.push_back(s.substr(i,2));
			++m[s.substr(i,2)];
		}
		for(ll i=0;i<v.size()-1;++i){
			if(m[v[i]]>2){
				flag=1;
				break;
			}
			if(m[v[i]]==2){
				if(v[i]!=v[i+1]){
					flag=1;
					break;
				}
			}
			--m[v[i]];
		}
		if(flag){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
		// is st th hi
	} 
	return 0;
}