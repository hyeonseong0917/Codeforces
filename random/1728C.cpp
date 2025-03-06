#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		// f(x): 양의 정수 x에 대해 십진수 자리? 리딩 제로 없는
		// 수열 a와 b가 주어짐. n개의 양수를 가짐
		// 하나의 오퍼레이션
		// 1에서 n까지의 i를 고름
		// a[i]에 f(a[i]) 할당하거나, b[i]에 f(b[i])를 할당함
		// rearrange해서 a[i]=b[i]가 되면
		// 최소 수의 operation은? a와 b를 같게 만들기위한
		// 1845
		ll n;
		cin>>n;
		vector<ll> a(n,0),b(n,0);
		map<ll,ll> a_check, b_check;
		for(ll i=0;i<n;++i){
			cin>>a[i];
			++a_check[a[i]];
		}
		for(ll i=0;i<n;++i){
			cin>>b[i];
			++b_check[b[i]];
		}
		vector<ll> new_a, new_b;
		for(ll i=0;i<n;++i){
			if(!b_check[a[i]]){
				new_a.push_back(a[i]);
			}else{
				--b_check[a[i]];
			}
			if(!a_check[b[i]]){
				new_b.push_back(b[i]);
			}else{
				--a_check[b[i]];
			}
		}
		a.clear();
		b.clear();
		a=new_a;
		b=new_b;
		ll as=a.size();
		ll bs=b.size();
		// cout<<as<<" "<<bs<<"\n";
		ll ans=0;
		for(ll i=0;i<as;++i){
			if(a[i]>=10){
				ll cnt=0;
				while(a[i]){
					a[i]/=10;
					++cnt;
				}
				a[i]=cnt;
				++ans;
			}
			if(b[i]>=10){
				ll cnt=0;
				while(b[i]){
					b[i]/=10;
					++cnt;
				}
				b[i]=cnt;
				++ans;
			}
		}
		// 1. 기존에 같은 수는 다 제거

		// 2. 다 제거한 다음에는 1의 자릿수 아닌거 다 변환
		a_check.clear();
		b_check.clear();
		for(ll i=0;i<as;++i){
			++a_check[a[i]];
			++b_check[b[i]];
		}
		new_a.clear();
		new_b.clear();
		for(ll i=0;i<as;++i){
			if(!b_check[a[i]]){
				new_a.push_back(a[i]);
			}else{
				--b_check[a[i]];
			}
			if(!a_check[b[i]]){
				new_b.push_back(b[i]);
			}else{
				--a_check[b[i]];
			}
		}
		a.clear();
		b.clear();
		a=new_a;
		b=new_b;
		for(ll i=0;i<a.size();++i){
			if(a[i]!=1){
				++ans;
			}
			if(b[i]!=1){
				++ans;
			}
		}
		cout<<ans<<"\n";
		// 3. 같은거 다 제거
		// 4. 남은 수 중 1이 아닌 수의 개수
		
	} 
	return 0;
}