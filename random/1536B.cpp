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
		// 1052
		// MEX문자열: 포함되지 않는 가장 짧은 연속 문자열
		// 가장 짧은 s에 포함되지 않는 문자열
		ll n;
		cin>>n;
		string s;
		cin>>s;
		// 길이 1,2,3만 보면?
		vector<string> v[3];
		for(ll i=0;i<26;++i){
			char c='a'+i;
			string k="";
			k+=c;
			v[0].push_back(k);
			// cout<<k<<endl;
			for(ll j=0;j<26;++j){
				char d='a'+j;
				string kk="";
				kk+=c;
				kk+=d;
				v[1].push_back(kk);
				for(ll p=0;p<26;++p){
					char e='a'+p;
					string kkk="";
					kkk+=c;
					kkk+=d;
					kkk+=e;
					v[2].push_back(kkk);
				}
			}
		}
		map<string,ll> check;
		string ans="";
		for(ll i=1;i<=3;++i){
			for(ll j=0;j+i<=n;++j){
				string k=s.substr(j,i);
				++check[k];
			}
			for(ll j=0;j<v[i-1].size();++j){
				if(!check[v[i-1][j]]){
					ans=v[i-1][j];
					break;
				}
			}
			if(ans!="") break;
		}
		cout<<ans<<"\n";
	} 

	return 0;
}