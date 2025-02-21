#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long

ll n;
vector<ll> v;
vector<ll> p;
bool visited[200000+1];
ll cnt=0;
string s;
void dfs(ll start_num, ll cur_num, bool flag){
	if(flag && start_num==cur_num){
		return;
	}
	ll next_num=v[cur_num];
	visited[cur_num]=1;
	if(s[cur_num]=='0'){
		++cnt;
	}
	p.push_back(cur_num);
	dfs(start_num,next_num,1);
}

int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		cin>>n;
		
		v.clear();
		p.clear();
		vector<ll> dp(n+1,0);
		for(ll i=0;i<n+1;++i){
			visited[i]=0;
		}
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			v.push_back(a-1);
		}
		cin>>s;
		for(ll i=0;i<n;++i){
			if(!visited[i]){
				p.clear();
				cnt=0;
				dfs(i,i,0);
				for(ll j=0;j<p.size();++j){
					dp[p[j]]=cnt;
				}
				// cout<<i<<" "<<cnt<<"\n";
			}
		}
		for(ll i=0;i<n;++i){
			cout<<dp[i]<<" ";
		}cout<<"\n";
	} 	

	return 0;
}