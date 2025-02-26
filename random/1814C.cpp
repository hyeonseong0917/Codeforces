#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
bool comp(pair<ll,ll> a, pair<ll,ll> b){
	return a.second>b.second;
}
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		// 1을 r1번 요청
		// 2를 r2번 요청
		// 3을 r3번 요청..
		// a와 b를 구성하여 전체 시간이 가능한 한 최소로 되도록
		ll n,s1,s2;
		cin>>n>>s1>>s2;
		vector<pair<ll,ll>> v;
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			v.push_back({i+1,a}); //{idx,val}
		}
		// 1 2 3 4 5 6 7
		// 8 6 4 4 4 1 7

		// s1=3, s2=1
		// a: [5,6]
		// b: [1,7,2,4,3]
		
		// {1,8},{7,7},{2,6},{3,4},{4,4},{5,4},{6,1}
		// a: [3,6]
		// b: [1,7,2,4,5]

		// a: [5,6]
		// b: [1,7,2,4,3]

		// a: [4,5]
		// b: [1,7,2,3,6]
		vector<ll> a;
		vector<ll> b;
		sort(v.begin(),v.end(),comp);
		for(ll i=0;i<n;++i){
			ll cur_num=v[i].first;
			ll cur_val=v[i].second;
			// a b어디에 넣어야 이득인지?
			if(a.empty() && b.empty()){
				if(s1<s2){
					a.push_back(cur_num);
				}else{
					b.push_back(cur_num);
				}
				continue;
			}
			if(a.empty() || b.empty()){
				if(a.empty()){
					ll bs=b.size();
					// 만약 b에 넣는다면 bs*cur_val*s2
					// 만약 a에 넣는다면 s1*cur_val
					if((bs+1)*cur_val*s2<=s1*cur_val){
						b.push_back(cur_num);
					}else{
						a.push_back(cur_num);
					}
				}else{
					ll as=a.size();
					if((as+1)*cur_val*s1<=s2*cur_val){
						a.push_back(cur_num);
					}else{
						b.push_back(cur_num);
					}
				}
				continue;
			}
			// a b 둘다 원소가 있다면?
			ll as=a.size();
			ll bs=b.size();
			if((as+1)*cur_val*s1<=(bs+1)*cur_val*s2){
				a.push_back(cur_num);
			}else{
				b.push_back(cur_num);
			}
		}
		ll as=a.size();
		ll bs=b.size();
		cout<<as<<" ";
		for(ll i=0;i<as;++i){
			cout<<a[i]<<" ";
		}cout<<"\n";
		cout<<bs<<" ";
		for(ll i=0;i<bs;++i){
			cout<<b[i]<<" ";
		}cout<<"\n";
	} 
	return 0;
}