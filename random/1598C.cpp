#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int o=1;
	cin>>o;
	while(o--){
		// 1544
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		ll sum=0;
		for(ll i=0;i<n;++i){
			cin>>v[i];
			sum+=v[i];
		}
		// k를 수학적 평균. 정수 아닐 수도?
		// a에서 저확히 2개를 제거하여 여전히 n-2개의 평균이 k이도록
		// i,j를 지웠을 때도
		// 정수여야 될 듯? 평균이
		// 정수가 아니어도 될 경우가 있나?

		// 20.5
		// 1  2  3  4  5  6 
		// 20 20 21 21 20 21
		// 20.5*6=123
		// 평균이 유지되려면 현재 평균인 수를 지워야됨
		ll m=sum/n; // 평균

		// 0 1 2 3 4 5
		// 8 5 7 8 5 7
		// n=6
		// 40/6=6
		if(m*n!=sum && m*n+n/2!=sum){
			cout<<0<<"\n";
		}else{
			sort(v.begin(),v.end());
			map<ll,ll> check;
			++check[v[n-1]];
			ll ans=0;
			if(m*n!=sum){
				if(n%2==1){
					cout<<0<<"\n";
					continue;
				}
				for(ll i=n-2;i>=0;--i){
					// v[i]를 지우는 경우
					// i+1이후에 v[j]=2*m-v[i]인 j의 개수?
					ans+=check[2*m+1-v[i]];
					++check[v[i]];
				}
			}else{
				for(ll i=n-2;i>=0;--i){
					// v[i]를 지우는 경우
					// i+1이후에 v[j]=2*m-v[i]인 j의 개수?
					ans+=check[2*m-v[i]];
					++check[v[i]];
				}
			}
			
			// 2개 지워서 평균이 여전히 m이 되도록
			
			
			cout<<ans<<"\n";
		}

	} 

	return 0;
}