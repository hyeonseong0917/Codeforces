#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> a(n,0), v(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		if(n==1){
			if(a[0]==0){
				cout<<"YES"<<"\n";
			}else{
				cout<<"NO"<<"\n";
			}
			continue;
		}
		if(a[0]<0 || a[n-1]>0){
			cout<<"NO"<<"\n";
			continue;
		}
		// 2 -1 1 -2 0 0 0
		// 2 0 2 -1 1 1 1

		// 2 -1 0 0 0 0 0
		// 2 0 0 0 0 0 0
		// 2 0 2 -1 0 0 0
		// v[i]를 처리하려고 봤는데? a[i]+1과 같으면 stop해야함
		// [i+1에서 n-1까지] 순수 a[i]가 0이어야함
		if(a[0]==0){
			bool is_all_zero=1;
			for(ll i=0;i<n;++i){
				if(a[i]!=0){
					is_all_zero=0;
				}
			}
			if(is_all_zero){
				cout<<"YES"<<"\n";
			}else{
				cout<<"NO"<<"\n";
			}
			continue;
		}
		v[1]-=max((ll)0,a[0]-v[0]-1);
		v[0]=a[0];
		ll idx=-1;
		bool flag=0;
		for(ll i=1;i<n;++i){
			if(v[i]==a[i]+1){
				idx=i+1;
				break;
			}
			if(v[i]>a[i]){
				flag=1;
				break;
			}
			// v[i]<a[i]+1
			// v[i]를 a[i]+1로 만들고 싶음
			// v[i]<a[i]+1인 상황에서는 i+1에서 빌려와야함
			ll need_num=a[i]+1-v[i]; //need_num만큼 대출필요
			// need_num은 무조건 0이아닌 양수
			if(i==n-1){
				flag=1;
				break;
			}
			v[i]=a[i]+1;
			v[i+1]-=need_num-1;
		}
	
		if(idx!=-1){
			for(ll i=idx;i<n;++i){
				if(a[i]!=0){
					flag=1;
					break;
				}
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