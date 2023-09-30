#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<vector<ll>> vec; //전체 집합
		vector<ll> cnt(51,0); //해당 숫자가 몇 개 있는지?
		ll ans=0; //집합의 총 크기
		vector<ll> v; 
		vector<ll> val[51]; //val[x]: x값이 몇 번째 집합에 있는지?
		
		for(ll i=0;i<n;++i){
			ll k;
			cin>>k;
			v.clear();
			
			for(ll j=0;j<k;++j){
				ll x;
				cin>>x;
				v.push_back(x);
				if(!cnt[x]){
					++ans;
				}
				++cnt[x];
				//x값이 몇 번째 집합에 있는지?
				val[x].push_back(i);
				
			}
			vec.push_back(v);
		}
		ll an=0;
		vector<ll> cn(51,0);
		ll max_num=0;
		for(ll i=1;i<=50;++i){
			//i값이 있는 집합들에 대해 해당 집합들만 가지고 있는 수의 개수를 전체 집합의 수의 개수에서 제외하면서 그 중 최댓값을 찾는다.
			if(val[i].size()==0) continue; //i값에 대해 해당하는 집합이 없으면 패스

			//i값이 있는 집합들의 원소 수 집합 cn[x]: i값이 있는 집합의 원소 x 개수
			cn.assign(51,0);
			
			//i값에 대해..
			//val[i]: i값이 있는 집합 모음
			for(ll j=0;j<val[i].size();++j){
				ll cur_num=val[i][j]; //i값이 있는 집합의 번호
				vector<ll> cur_vector=vec[cur_num]; //i값이 있는 집합
				for(ll t=0;t<cur_vector.size();++t){
					//i값이 있는 집합의 원소들에 대해 해당 원소가 몇 개 있는지를 cn에 기록
					++cn[cur_vector[t]];
				}
			}
			//temp에 기존 집합의 크기를 선언
			ll temp=ans;
			for(ll j=1;j<=50;++j){
				//cnt[j](전체 집합에 존재하는 j값 개수)와 cn[j](i값이 있는 집합들 중에서 j의 개수)값이 같고 j값이 집합에 존재하는 값이면
				if(cnt[j]-cn[j]==0 && cnt[j]>0){
					//전체 집합에 존재하는 j값 개수와 i값이 있는 집합들 중 j값의 개수가 같다는 것은
					//j값은 i값이 있는 집합들에서만 존재한다는 뜻, 우리가 지금 i값이 있는 집합에 대해서만 고려하므로
					//i값이 있는 집합에만 존재하는 j값들을 하나씩 제외시켜가며 최댓값을 비교한다.
					//i가 있는 집합에만 존재하는 원소들에 대해서도 빼준다.

					//temp를 1만큼 뺀다 왜 뺴는가? j값을 제외시켰을 때 전체 집합의 개수에서 해당 조건을 만족하는 값을 빼줄 것이기 때문이다.
					--temp;
				}
			}
			if(temp!=ans){
				max_num=max(max_num,temp);
			}
		}
		cout<<max_num<<"\n";3
		
	}	
	return 0;
}