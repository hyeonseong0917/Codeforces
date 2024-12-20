#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,m,q;
		cin>>n>>m>>q;
		vector<ll> v(m,0), a(q,0);
		for(ll i=0;i<m;++i){
			cin>>v[i];
		}
		for(ll i=0;i<q;++i){
			cin>>a[i];
		}
		sort(v.begin(),v.end());
		for(ll i=0;i<q;++i){
			ll cur_num=a[i]; // 현재 좌표
			if(m==1){
				if(cur_num<v[0]){
					cout<<v[0]-1<<"\n";
				}else{
					cout<<n-v[0]<<"\n";
				}
			}else{
				// m이 2이상
				ll min_num=v[0];
				ll max_num=v[m-1];
				if(cur_num<min_num || max_num<cur_num){
					// 사이에 없는경우
					if(cur_num<min_num){
						cout<<min_num-1<<"\n";
					}else{
						cout<<n-max_num<<"\n";
					}
				}else{
					// 사이에 있는 경우
					// 1. cur_num보다 작지만, 최대의 값을 찾는다
					ll l_num=-1;
					ll L=0, R=m-1;
					while(L<=R){
						ll mid=(L+R)/2;
						if(v[mid]<cur_num){
							l_num=max(l_num,v[mid]);
							L=mid+1;
						}else{
							R=mid-1;
						}
					}
					// 2. cur_num보다 크지만, 최소의 값을 찾는다
					ll r_num=2023101800;
					L=0, R=m-1;
					while(L<=R){
						ll mid=(L+R)/2;
						if(v[mid]>cur_num){
							r_num=min(r_num,v[mid]);
							R=mid-1;
						}else{
							L=mid+1;
						}
					}
					// 3. l_num, r_num, cur_num
					ll mid_num=(l_num+r_num)/2;
					// cout<<l_num<<" "<<r_num<<endl;
					cout<<min(mid_num-l_num,r_num-mid_num)<<"\n";
				}
			}
		}
	}
	return 0;
}