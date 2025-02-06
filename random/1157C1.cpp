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
	// cin>>t;
	while(t--){
		// a: n개의 정수로 이루어짐 1에서 n까지 고유한 수
		// 왼쪽끝 오른쪽 끝 중 하나 골라서
		// 쓰고 삭제한다???
		// 무조건 증가하도록하고 그러한 시퀀스들 사이에서 가장 긴 길이
		// [2,1,5,4,3]

		// 매 operation마다 왼쪽 끝이나 오른쪽 끝 가져와서
		// 새로운 배열에 push_back하는데 오름차순 최대 길이 구하기
		// 무조건 둘중에 작은거 아님?
		// 둘 중에 작은거 선택했을 때 최적의 경우가 아닌 경우 있나?
		// [4,5,6,7,8,9,3]
		ll n;
		cin>>n;
		vector<ll> v(n,0);
		for(ll i=0;i<n;++i){
			cin>>v[i];
		}
		if(n==1){
			cout<<1<<"\n";
			cout<<"L"<<"\n";
			continue;
		}
		ll last_num=0;
		ll L=0,R=n-1;
		string ans="";
		while(L<=R){
			if(v[L]<v[R]){
				// L이 더 작음. L을 가져감
				// 근데 last_num보다 v[L]이 더 커야함
				if(v[L]>last_num){
					last_num=v[L];
					ans+='L';
					++L;
				}else{
					// v[L]<last_num
					if(v[R]>last_num){
						last_num=v[R];
						ans+='R';
						--R;
					}else{
						break;
					}
				}
			}else{
				// R을 가져감
				// v[R]<v[L]
				if(v[R]>last_num){
					last_num=v[R];
					ans+='R';
					--R;
				}else{
					if(v[L]>last_num){
						last_num=v[L];
						ans+='L';
						++L;
					}else{
						break;
					}
				}
			}
		}
		ll as=ans.size();
		cout<<as<<"\n";
		cout<<ans<<"\n";

	} 

	return 0;
}