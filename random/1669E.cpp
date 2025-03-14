#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long
// ll trd_dp[100000+1][26][26];
int main() {
	// your code goes here
	int o=1;
	cin>>o;
	while(o--){
		// 1943
		// n개의 문자열들이 있음. 길이는 2, 'a'에서 'k'까지
		// i,j쌍의 개수를 구하라. i<j이고, i번째 문자열과
		// j번째 문자열이 정확히 한 개의 위치에서 다른 개수
		ll n;
		cin>>n;
		vector<string> v;
		for(ll i=0;i<n;++i){
			string s;
			cin>>s;
			v.push_back(s);
		}
		// ab
		// cb
		// db
		// aa
		// cc
		// ef

		// i<j여야한다
		// fst_dp[x][y]: x번째 인덱스 이후 'a'+y의 개수?
		// sed_dp[x][y]
		vector<vector<ll>> fst_dp, sed_dp;
		for(ll i=0;i<n;++i){
			vector<ll> tmp=vector<ll>(26,0);
			fst_dp.push_back(tmp);
			sed_dp.push_back(tmp);
		}
		// 특정 인덱스 이후, 특정 문자열의 개수
		fst_dp[n-1][v[n-1][0]-'a']=1;
		sed_dp[n-1][v[n-1][1]-'a']=1;
		// trd_dp[n-1][v[n-1][0]-'a'][v[n-1][1]-'a']=1;
		
		for(ll i=n-2;i>=0;--i){
			for(ll j=0;j<26;++j){
				fst_dp[i][j]=fst_dp[i+1][j];
				sed_dp[i][j]=sed_dp[i+1][j];
				if(j==v[i][0]-'a'){
					++fst_dp[i][j];
				}
				if(j==v[i][1]-'a'){
					++sed_dp[i][j];
				}
			}
		}
		// 1.0번째 자리 a이고, 1번째 자리 b가 아닌 것
		// 2.0번째 자리 a가 아니고, 1번째 자리 b인 것
		ll ans=0;
		map<string,ll> check;
		++check[v[n-1]];
		for(ll i=0;i<n-1;++i){
			string cur_str=v[i];
			// 1번의 개수를 구하면?
			// 1.0번째 자리 a인거의 개수
			// 2.1번째 자리 b인거의 개수
			// 0번째 자리 a이면서 1번째자리 b인거의 개수
			char a=cur_str[0];
			char b=cur_str[1];
			ans+=fst_dp[i+1][a-'a'];
			ans+=sed_dp[i+1][b-'a'];
			ans-=check[cur_str]*2;
			++check[cur_str];
		}
		cout<<ans<<"\n";
	} 

	return 0;
}