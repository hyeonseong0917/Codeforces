#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

ll gcd(ll a, ll b){
	if(b==0){
		return a;
	}
	return gcd(b,a%b);
}

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		ll diff=0;
		bool flag=0;
		for(ll i=0;i<n-1;++i){
			ll a=v[i];
			ll b=v[i+1];
			ll cur_num=gcd(max(a,b),min(a,b));
			if(diff<=cur_num){
				diff=cur_num;
			}else{
				// cout<<i<<endl;
				// i-1이나 i나 i+1번째 지워야함
				vector<ll> fst;
				for(ll j=0;j<n;++j){
					if(j==i-1) continue;
					fst.push_back(v[j]);
				}
				bool fst_flag=0;
				int fst_num=0;
				for(ll j=0;j<n-2;++j){
					// cout<<j<<" "<<gcd(max(fst[j],fst[j+1]),min(fst[j],fst[j+1]))<<endl;
					if(fst_num<=gcd(max(fst[j],fst[j+1]),min(fst[j],fst[j+1]))){
						fst_num=gcd(max(fst[j],fst[j+1]),min(fst[j],fst[j+1]));
					}else{
						fst_flag=1;
						break;
					}
				}
				// cout<<fst_flag<<endl;
				vector<ll> sed;
				for(ll j=0;j<n;++j){
					if(j==i) continue;
					sed.push_back(v[j]);
				}
				bool sed_flag=0;
				int sed_num=0;
				for(ll j=0;j<n-2;++j){
					if(sed_num<=gcd(max(sed[j],sed[j+1]),min(sed[j],sed[j+1]))){
						sed_num=gcd(max(sed[j],sed[j+1]),min(sed[j],sed[j+1]));
					}else{
						sed_flag=1;
						break;
					}
				}
				vector<ll> trd;
				for(ll j=0;j<n;++j){
					if(j==i+1) continue;
					trd.push_back(v[j]);
				}
				bool trd_flag=0;
				int trd_num=0;
				for(ll j=0;j<n-2;++j){
					if(trd_num<=gcd(max(trd[j],trd[j+1]),min(trd[j],trd[j+1]))){
						trd_num=gcd(max(trd[j],trd[j+1]),min(trd[j],trd[j+1]));
					}else{
						trd_flag=1;
						break;
					}
				}
				if(fst_flag && sed_flag && trd_flag){
					flag=1;
				}
				break;
			}
		}
		if(flag){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
		}
	}
	
	return 0;
}