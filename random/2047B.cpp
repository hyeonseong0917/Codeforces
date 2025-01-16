#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long

bool comp(pair<char,ll> a, pair<char,ll> b){
	return a.second<b.second;
}
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
			cout<<s<<"\n";
			continue;
		}
		// i,j골라서
		// s[i]=s[j]로 했을 때 고유한 순열의 개수를 최소로 하고 싶음
		// xyyx
		// 언제 고유한 순열의 개수가 최소로 될까??
		// x:2 y:2
		//4!/2!*2!
		// 4!/3!
		// 가장 작은 거 개수 하나 빼서 큰 거에 더하기?
		vector<pair<char,int>> v;
		map<char,int> m;
		vector<char> tmp;
		for(ll i=0;i<n;++i){
			if(m[s[i]]){
				++m[s[i]];
				continue;
			}
			++m[s[i]];
			tmp.push_back(s[i]);
		}
		for(ll i=0;i<tmp.size();++i){
			v.push_back({tmp[i],m[tmp[i]]});
		}
		sort(v.begin(),v.end(),comp);
		ll vs=v.size();
		// cout<<vs<<endl;
		char min_char=v[0].first;
		char max_char=v[v.size()-1].first;
		// cout<<min_char<<" "<<max_char<<endl;
		for(ll i=0;i<n;++i){
			if(s[i]==min_char){
				s[i]=max_char;
				break;
			}
		}
		cout<<s<<"\n";
	} 
	return 0;
}