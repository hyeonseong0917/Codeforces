#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define ll long long
#define pb push_back

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		string s;
		cin>>s;
		// 1. n이 1이면 무조건 가능
		if(n==1){
			cout<<0<<"\n";
			continue;
		}
		// 2. 모두 같은지 확인
		bool flag=0;
		for(ll i=1;i<n;++i){
			if(s[i]!=s[0]){
				flag=1;
			}
		}
		if(!flag){
			cout<<0<<"\n";
			continue;
		}
		ll ans=0;
		vector<ll> A,B;
		for(ll i=0;i<n;++i){
			if(s[i]=='a'){
				A.pb(i);
			}else{
				B.pb(i);
			}
		}
		ll as=A.size();
		ll mid=as/2;
		ll L=A[mid]-1;
		ll R=A[mid]+1;
		ll a_cnt=0;
		for(ll i=mid-1;i>=0;--i){
			a_cnt+=L-A[i];
			--L;
		}
		for(ll i=mid+1;i<as;++i){
			a_cnt+=A[i]-R;
			++R;
		}

		ll bs=B.size();
		mid=bs/2;
		L=B[mid]-1;
		R=B[mid]+1;
		ll b_cnt=0;
		for(ll i=mid-1;i>=0;--i){
			b_cnt+=L-B[i];
			--L;
		}
		for(ll i=mid+1;i<bs;++i){
			b_cnt+=B[i]-R;
			++R;
		}
		ans=min(a_cnt,b_cnt);
		cout<<ans<<"\n";
	}
	return 0;
}