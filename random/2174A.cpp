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
		string a,b;
		cin>>a;
		cin>>b;
		ll m=a.size();
		// v[i]: a의 i번째 원소 앞에 오는 str
		string k="";
		vector<string> v(m,k);
		ll n=b.size();
		sort(b.begin(),b.end());
		vector<ll> check(26,0);
		// b에서 이미 a에 있는거 제외해야함
		for(ll i=0;i<n;++i){
			++check[b[i]-'a'];
		}
		for(ll i=0;i<m;++i){
			--check[a[i]-'a'];
		}
		bool flag=0;
		for(ll i=0;i<26;++i){
			if(check[i]<0){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<"Impossible"<<"\n";
		}else{
			string res="";
			for(ll i=0;i<26;++i){
				if(check[i]){
					for(ll j=0;j<check[i];++j){
						res+=('a'+i);
					}
				}
			}
			ll idx=0;
			ll rs=res.size();
			for(ll i=0;i<m;++i){
				string tmp="";
				// a[i]보다 사전 순 앞서거나 같으면 무조건 더하기
				while(idx<rs){
					if(a[i]>res[idx]){
						tmp+=res[idx];
						++idx;
					}else{
						break;
					}
				}
				v[i]=tmp;
			}
			string ans="";
			for(ll i=0;i<m;++i){
				ans+=v[i];
				ans+=a[i];
			}
			if(idx<rs){
				ans+=res.substr(idx,rs-idx);
			}
			cout<<ans<<"\n";
		}
	} 	

	return 0;
}