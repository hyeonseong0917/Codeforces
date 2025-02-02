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
	int t=0;
	cin>>t;
	while(t--){
		// 2k<=n
		// k번의 operation
		// a[i]와 a[j]를 삭제하고 a[i]/a[j]만큼의 점수를 얻음
		// k번의 operation 후에 남은 수들은 그냥 다 더함
		// 1 1 1 1 1 2 3
		// k=3
		ll n,k;
		cin>>n>>k;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		// [0,n-2k-1]
		ll ans=0;
		// n-2k개 더함 앞에서
		for(ll i=0;i<n-2*k;++i){
			ans+=v[i];
		}
		// [0,2k-1]
		ll L=n-2*k, R=n-1;
		// 다 0으로 만들기
		// 1 3 3 7
		map<ll,ll> check;
		vector<ll> tmp;
		for(ll i=L;i<n;++i){
			if(!check[v[i]]){
				++check[v[i]];
				tmp.push_back(v[i]);
			}else{
				++check[v[i]];
			}
		}
		priority_queue<ll> pq;
		for(ll i=0;i<tmp.size();++i){
			pq.push(check[tmp[i]]);
		}
		while(!pq.empty()){
			ll ps=pq.size();
			if(ps==1){
				ans+=pq.top()/2;
				break;
			}
			ll fst_num=pq.top();
			pq.pop();
			ll sed_num=pq.top();
			pq.pop();
			--fst_num;
			--sed_num;
			if(fst_num!=0){
				pq.push(fst_num);
			}
			if(sed_num!=0){
				pq.push(sed_num);
			}
		}
		cout<<ans<<"\n";

	} 
	return 0;
}