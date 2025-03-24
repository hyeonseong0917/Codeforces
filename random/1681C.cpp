#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
 
#define ll long long
ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
ll lcm(ll a, ll b){
	return (a*b)/gcd(a,b);
}

int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		// 1136
		ll n;
		cin>>n;
		vector<ll> a(n,0), sa(n,0), b(n,0), sb(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
			sa[i]=a[i];
		}
		sort(sa.begin(),sa.end());
		for(ll i=0;i<n;++i){
			cin>>b[i];
			sb[i]=b[i];
		}
		sort(sb.begin(),sb.end());
		vector<pair<ll,ll>> ans;
		bool flag=0;
		for(ll i=0;i<n;++i){
			if(a[i]==sa[i] && b[i]==sb[i]) continue;
			ll a_num=sa[i];
			vector<ll> a_idx;
			for(ll j=i+1;j<n;++j){
				if(a[j]==a_num){
					a_idx.push_back(j);
				}
			}
			ll b_num=sb[i];
			vector<ll> b_idx;
			for(ll j=i+1;j<n;++j){
				if(b[j]==b_num){
					b_idx.push_back(j);
				}
			}
			ll idx=-1;
			for(ll j=0;j<a_idx.size();++j){
				for(ll k=0;k<b_idx.size();++k){
					if(a_idx[j]==b_idx[k]){
						idx=a_idx[j];
						break;
					}
				}
				if(idx!=-1){
					break;
				}
			}
			if(idx==-1){
				flag=1;
				break;
			}
			ll tmp=a[i];
			a[i]=a[idx];
			a[idx]=tmp;
			tmp=b[i];
			b[i]=b[idx];
			b[idx]=tmp;
			ans.push_back({i+1,idx+1});
		}
		if(flag){
			cout<<-1<<"\n";
			continue;
		}
		ll as=ans.size();
		cout<<as<<"\n";
		for(ll i=0;i<as;++i){
			cout<<ans[i].first<<" "<<ans[i].second<<"\n";
		}

		// 최대 1만번의 move 가능
		// a[i]와 a[j]를 바꾸고, b[i]와 b[j]를 바꿈
		// 비내림차순으로 만들 수 있는지?
		// n<=100
		// 0 1 2 3
		// 2 3 1 2
		// 2 3 2 3
		// 언제 불가능한지?
		// a와 b모두 i번째 와야 하는 위치의 수는 정해져 있음
		// 각각의 와야 하는 위치의 수에 해당하는 인덱스가 같아야함
		// 
	} 
	return 0;
}