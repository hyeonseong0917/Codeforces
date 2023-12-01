#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <cmath>
using namespace std;
//1017
#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		// 각 pair의 거리 차이가 1보다 크면서 (x,y)합의 최댓값의 최소를 찾기
		ll L=0, R=1000000000;
		ll ans=R;
		while(L<=R){
			ll mid=(L+R)/2;
			ll cur_num=(mid+1)*(mid+1);
			if(cur_num>=n){
				ans=min(ans,mid);
				R=mid-1;
			}else{
				L=mid+1;
			}
		}
		cout<<ans<<"\n";
		
	}
	return 0;
}