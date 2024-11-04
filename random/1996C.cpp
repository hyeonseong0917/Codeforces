#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		// a,b 길이 n, q개의 질문
		// 각 쿼리마다 l과 r을 받고, l<=i<=r에 대해 a[i]를 x로 변환 가능
		// 최소 시행 횟수: a[l:r]을 정렬한 것과 b[l:r]을 정렬한 것이 동일해지는
		// 정렬한 것이 같다=각 문자의 개수가 같다
		ll n,q;
		cin>>n>>q;
		string a,b;
		cin>>a;
		cin>>b;
		ll a_dp[n+1][26+1],b_dp[n+1][26+1]; // dp[a][b]: b에 해당하는 알파벳이 인덱스 a(포함)까지 dp[a][b]개 있음
		for(ll i=0;i<n;++i){
			ll cur_num=a[i]-'a';
			if(i==0){
				for(ll j=0;j<26;++j){
					a_dp[0][j]=0;
				}
				a_dp[0][cur_num]=1;
				
			}else{
				for(ll j=0;j<26;++j){
					a_dp[i][j]=a_dp[i-1][j];
				}
				++a_dp[i][cur_num];
			}
		}

		for(ll i=0;i<n;++i){
			ll cur_num=b[i]-'a';
			if(i==0){
				for(ll j=0;j<26;++j){
					b_dp[0][j]=0;
				}
				b_dp[0][cur_num]=1;
				
			}else{
				for(ll j=0;j<26;++j){
					b_dp[i][j]=b_dp[i-1][j];
				}
				++b_dp[i][cur_num];
			}
		}
		
		for(ll i=0;i<q;++i){
			ll c,d;
			cin>>c>>d;
			--c;
			--d;
			//[c,d]에서 조건 만족시키려면 시행 몇 번?
			vector<ll> a_cnt(26,0), b_cnt(26,0);
			for(ll i=0;i<26;++i){
				a_cnt[i]=a_dp[d][i]-a_dp[c][i];
				b_cnt[i]=b_dp[d][i]-b_dp[c][i];
			}
			++a_cnt[a[c]-'a'];
			++b_cnt[b[c]-'a'];
			ll ans=0;
			for(ll i=0;i<26;++i){
				ans+=abs(a_cnt[i]-b_cnt[i]);
			}
			ans/=2;
			cout<<ans<<"\n";
		}	
	
	} 
	return 0;
}