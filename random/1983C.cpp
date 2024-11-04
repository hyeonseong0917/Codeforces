#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		vector<ll> a(n,0), b(n,0), c(n,0);
		vector<ll> pa(n,0), pb(n,0), pc(n,0);
		for(ll i=0;i<n;++i){
			cin>>a[i];
		}
		for(ll i=0;i<n;++i){
			cin>>b[i];
		}
		for(ll i=0;i<n;++i){
			cin>>c[i];
		}
		pa[0]=a[0];
		pb[0]=b[0];
		pc[0]=c[0];
		for(ll i=1;i<n;++i){
			pa[i]=pa[i-1]+a[i];
			pb[i]=pb[i-1]+b[i];
			pc[i]=pc[i-1]+c[i];
		}
		vector<ll> ans(6,0);
		ll tot=pa[n-1];
		if(tot%3!=0){
			tot/=3;
			++tot;
		}else{
			tot/=3;
		}
		ll L=0, R=0;
		// cout<<tot<<endl;
		while(L<=R && L<n && R<n){
			// if(L==1 && R==2){
			// 	cout<<pb[R]-pb[L]+b[L]<<"FSD"<<endl;
			// 	cout<<pb[R]<<" "<<pb[L]<<" "<<b[L]<<endl;
			// }
			if(pa[R]-pa[L]+a[L]>=tot || pb[R]-pb[L]+b[L]>=tot || pc[R]-pc[L]+c[L]>=tot){
				// cout<<L<<" "<<R<<endl;
				ll fst_sum=pa[R]-pa[L]+a[L];
				ll sed_sum=pb[R]-pb[L]+b[L];
				ll trd_sum=pc[R]-pc[L]+c[L];
				// 가장 큰 sum을 찾기
				// 가장 큰 sum의 ans에 해당한는 값이 이미 차있는 경우는?
				if(fst_sum>=sed_sum && fst_sum>=trd_sum){
					if(ans[0]){
						for(ll i=0;i<6;++i){
							if(ans[i])
						}
					}else{
						ans[0]=L+1;
						ans[1]=R+1;
					}
					
				}else if(sed_sum>=trd_sum && sed_sum>=fst_sum){
					ans[2]=L+1;
					ans[3]=R+1;
				}else{
					ans[4]=L+1;
					ans[5]=R+1;
				}
				L=R+1;
				++R;
			}else{
				++R;
			}
		}
		for(ll i=0;i<6;++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
		bool flag=0;
		for(ll i=0;i<6;++i){
			if(!ans[i]){
				flag=1;
				break;
			}
		}
		if(flag){
			cout<<-1<<"\n";
		}else{
			for(ll i=0;i<6;++i){
				cout<<ans[i]<<" ";
			}cout<<"\n";
		}
	}
	return 0;
}