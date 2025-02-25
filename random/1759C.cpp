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
		// 최소 x이상으로 온도를 변경해야함
		// L<=R 사이에서, |a-b|>=x && l<=b<=r

		// 온도 a에서온도 b를 얻기 위해 필요한 최소의 오퍼레이션
		// 불가능하면 불가능하다고
		ll l,r,x;
		cin>>l>>r>>x;
		// 최소 x만큼을 움직일 수 있음. x보다 더 크게도 가능

		// l<=r
		ll a,b;
		cin>>a>>b;
		if(a==b){
			cout<<0<<"\n";
			continue;
		}
		if(abs(a-b)>=x){
			cout<<1<<"\n";
		}else{
			// abs(a-b)<x
			// 1. a를 L로 보내기
			ll fst_cnt=2023101800, sed_cnt=2023101800;
			if(abs(a-l)>=x){
				// l로 보내면 되잖아
				if(abs(l-b)>=x){
					fst_cnt=2;
				}
			}else{
				if(a+x<=r){
					if(abs(l-b)>=x){
						fst_cnt=3;
					}
				}
			}
			if(abs(a-r)>=x){
				if(abs(r-b)>=x){
					sed_cnt=2;
				}
			}else{
				if(a-x>=l){
					if(abs(r-b)>=x){
						sed_cnt=3;
					}
				}
			}
			if(fst_cnt==2023101800 && sed_cnt==2023101800){
				cout<<-1<<"\n";
			}else{
				cout<<min(fst_cnt,sed_cnt)<<"\n";
			}
		}
	} 
	return 0;
}