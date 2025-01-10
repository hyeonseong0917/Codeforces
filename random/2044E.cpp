#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	ll t=1;
	cin>>t;
	while(t--){
		ll k,l1,r1,l2,r2;
		cin>>k>>l1>>r1>>l2>>r2;
		ll min_y_x=(l2+r1-1)/r1;
		ll max_y_x=r2/l1;
		ll fst_n=-1;
		// min_y_x보다 크거나 같은 최소의 fst_n을 찾기
		for(ll i=0;i<=30;++i){
			ll cur_num=(ll)pow(k,i);
			if(cur_num>=min_y_x && cur_num<=max_y_x){
				fst_n=i;
				break;
			}
		}
		// max_y_x보다 작거나 같은 최대의 sed_n을 찾기
		ll sed_n=-1;
		for(ll i=30;i>=0;--i){
			ll cur_num=(ll)pow(k,i);
			if(cur_num>=min_y_x && cur_num<=max_y_x){
				sed_n=i;
				break;
			}
		}
		if(fst_n==-1 || sed_n==-1){
			cout<<0<<"\n";
			continue;
		}
		// cout<<fst_n<<" "<<sed_n<<endl;
		ll ans=0;
		for(ll i=fst_n;i<=sed_n;++i){
			ll cur_num=(ll)pow(k,i);
			ll L=l1, R=r1;
			ll min_x=2023101800;
			// y1 l2보다 크거나 같은 최소의 x값을 찾기
			while(L<=R){
				ll mid=(L+R)/2;
				ll part_num=cur_num*mid;
				if(part_num<l2){
					L=mid+1;
				}else{
					if(part_num<=r2){
						min_x=min(min_x,mid);
					}
					R=mid-1;
				}
			}
			L=l1, R=r1;
			ll max_x=-2023101800;
			// y2=r2보다 작거나 같은 최대의 x값을 찾기
			while(L<=R){
				ll mid=(L+R)/2;
				ll part_num=cur_num*mid;
				if(part_num<=r2){
					if(l2<=part_num){
						max_x=max(max_x,mid);
					}
					L=mid+1;
				}else{
					R=mid-1;
				}
			}

			if(min_x==2023101800 || max_x==-2023101800){
				continue;
			}
			ans+=(max_x-min_x+1);
		}
		cout<<ans<<"\n";
	}
	return 0;
}