#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long

ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}

int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		// n개의 도시가 있음 1번부터 n번
		// b,g,r,y
		// i에서 j로 갈 수 있다. 만약 같은 색이라면 둘 다.
		// 이 이동은 |i-j|만큼의 코인 소모됨
		// q개의 독립적인 쿼리에 답하는것. x에서 y까지의 코스트
		ll n,q;
		cin>>n>>q;
		// BG BR BY GR GY RY
		vector<string> v;
		for(ll i=0;i<n;++i){
			string s;
			cin>>s;
			v.push_back(s);
		}
		vector<vector<ll>> dp,ldp,rdp;
		for(ll i=0;i<n;++i){
			vector<ll> tmp(6,0);
			dp.push_back(tmp);
			vector<ll> ltmp(6,-2023101800);
			ldp.push_back(ltmp);
			vector<ll> rtmp(6,2023101800);
			rdp.push_back(rtmp);
		}
		// 0: BG, 1: BR, 2: BY, 3: GR, 4: GY, 5: RY
		vector<string> d;
		d.push_back("BG");
		d.push_back("BR");
		d.push_back("BY");
		d.push_back("GR");
		d.push_back("GY");
		d.push_back("RY");
		// ldp[i][j] i번째인덱스까지 j번째 타입의 최대 인덱스
		// rdp[i][j]: n-1부터 i번째인덱스까지 j번째 타입의 최소 인덱스
		for(ll i=0;i<6;++i){
			if(v[0]==d[i]){
				ldp[0][i]=0;
			}
		}
		for(ll i=0;i<6;++i){
			if(v[n-1]==d[i]){
				rdp[n-1][i]=n-1;
			}
		}
		for(ll i=1;i<n;++i){
			for(ll j=0;j<6;++j){
				if(v[i]==d[j]){
					ldp[i][j]=i;
				}else{
					ldp[i][j]=ldp[i-1][j];
				}
			}
		}
		for(ll i=n-2;i>=0;--i){
			for(ll j=0;j<6;++j){
				if(v[i]==d[j]){
					rdp[i][j]=i;
				}else{
					rdp[i][j]=rdp[i+1][j];
				}
			}
		}
		for(ll i=0;i<q;++i){
			ll a,b;
			cin>>a>>b;
			if(a==b){
				cout<<0<<"\n";
				continue;
			}
			--a;
			--b;
			ll tmp_a=min(a,b);
			ll tmp_b=max(a,b);
			a=tmp_a;
			b=tmp_b;
			ll a_idx=-1, b_idx=-1;
			for(ll j=0;j<6;++j){
				if(v[a]==d[j]){
					a_idx=j;
				}
				if(v[b]==d[j]){
					b_idx=j;
				}
			}
			string s=v[a]+v[b];
			bool flag=0;
			for(ll i=0;i<4;++i){
				for(ll j=i+1;j<4;++j){
					if(s[i]==s[j]){
						flag=1;
						break;
					}
				}
			}
			if(flag){
				cout<<b-a<<"\n";
				continue;
			}
			ll L=-2023101800,R=2023101800;
			// 1.dp[a-1]중 최댓값
			for(ll j=0;j<6;++j){
				if(j==a_idx || j==b_idx) continue;
				L=max(L,ldp[a][j]);
			}
			// // 2.dp[a+1]중 최솟값
			for(ll j=0;j<6;++j){
				if(j==a_idx || j==b_idx) continue;
				R=min(R,rdp[a][j]);
			}
			if(L==-2023101800 && R==2023101800){
				cout<<-1<<"\n";
				continue;
			}
			ll ans=min(a-L+b-L,R-a+abs(R-b));
			cout<<ans<<"\n";
		}
	} 	

	return 0;
}