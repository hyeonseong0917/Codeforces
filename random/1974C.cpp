#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long
ll mod=998244353;
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		// a: 길이 n
        // 1<=j<=n-2에 대해 a[j],a[j+1],a[j+2]
        // triples b가 아름답다 언제?
        // 하나만 동일할 때
        ll n;
        cin>>n;
        vector<ll> v(n,0);
        for(ll i=0;i<n;++i){
            cin>>v[i];
        }
        vector<pair<ll,pair<ll,ll>>> p;
        // n-2개의 pair를 만들 수 있음
        // 첫 번째 수만 같은거??
        for(ll i=0;i<n-2;++i){
            p.push_back({v[i],{v[i+1],v[i+2]}});
        }
        ll ans=0;
        // 하나만 다른경우 = 2개가 같은경우
        // [1,2,3]
        // [2,3,2]
        // [3,2,2]
        // [2,2,3]
        // [2,3,4]
        // [3,4,2]
        map<pair<ll,ll>,ll> fst_sed, sed_trd, fst_trd;
        map<pair<ll,pair<ll,ll>>,ll> all_check;
        for(ll i=0;i<n-2;++i){
            ll fst_num=p[i].first;
            ll sed_num=p[i].second.first;
            ll trd_num=p[i].second.second;
            ans+=fst_sed[{fst_num,sed_num}]-all_check[{fst_num,{sed_num,trd_num}}];
            ans+=sed_trd[{sed_num,trd_num}]-all_check[{fst_num,{sed_num,trd_num}}];
            ans+=fst_trd[{fst_num,trd_num}]-all_check[{fst_num,{sed_num,trd_num}}];
            ++fst_sed[{fst_num,sed_num}];
            ++sed_trd[{sed_num,trd_num}];
            ++fst_trd[{fst_num,trd_num}];
            ++all_check[{fst_num,{sed_num,trd_num}}];
        }

        cout<<ans<<"\n";
	} 
	return 0;
}