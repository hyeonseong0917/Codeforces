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
		ll n,m;
		cin>>n>>m;
		ll k=n+m+1;
		vector<ll> a(k,0), b(k,0),a_dp(k+1,0),b_dp(k+1,0),bs(k+1,0);
		vector<ll> a_sum(k,0), b_sum(k,0);
		for(ll i=0;i<k;++i){
			cin>>a[i];
		}
		for(ll i=0;i<k;++i){
			cin>>b[i];
		}
		a_sum[0]=a[0];
		b_sum[0]=b[0];
		for(ll i=1;i<k;++i){
			a_sum[i]=a_sum[i-1]+a[i];
			b_sum[i]=b_sum[i-1]+b[i];
		}
		ll fst_num=0;
		ll sed_num=0;
		for(ll i=0;i<k;++i){
			if(a[i]>b[i]){
				++fst_num;
			}else{
				++sed_num;
			}
			a_dp[i]=fst_num;
			b_dp[i]=sed_num;
		}
		if(a[0]>b[0]){
			bs[0]=a[0];
		}else{
			bs[0]=b[0];
		}
		for(ll i=1;i<k;++i){
			ll cur_num=max(a[i],b[i]);
			bs[i]=bs[i-1]+cur_num;
		}
		vector<ll> ans;
		for(ll i=0;i<k;++i){
			// i번째 제외
			ll tmp_n=n;
			ll tmp_m=m;
			bool flag=0;
			ll cur_num=0;
			if(i==0){
				// 0번째 제외
				if(a_dp[k-1]-a_dp[0]==n && b_dp[k-1]-b_dp[0]==m){
					ans.push_back(bs[k-1]-max(a[0],b[0]));
				}else{
					if(a_dp[k-1]-a_dp[0]>n){
						for(ll j=k-1;j>=0;--j){
							if(a_dp[j]-a_dp[0]==n){
								ans.push_back(bs[j]-max(a[0],b[0])+b_sum[k-1]-b_sum[j]);
								break;
							}
						}
					}else{
						for(ll j=k-1;j>=0;--j){
							if(b_dp[j]-b_dp[0]==m){
								ans.push_back(bs[j]-max(a[0],b[0])+a_sum[k-1]-a_sum[j]);
								break;
							}
						}
					}
				}
				continue;
			}
			// 0~i-1
			if(i!=0){
				if(tmp_n>a_dp[i-1] && tmp_m>b_dp[i-1]){
					// cout<<i<<" "<<a_dp[i-1]<<" "<<b_dp[i-1]<<endl;
					tmp_n-=a_dp[i-1];
					tmp_m-=b_dp[i-1];
				}else{
					flag=1;
					if(a_dp[i-1]>=tmp_n){
						// cout<<i<<endl;
						ll idx=1222232421;
						ll L=0, R=i-1;
						while(L<=R){
							ll mid=(L+R)/2;
							if(a_dp[mid]>=tmp_n){
								idx=min(idx,mid);
								R=mid-1;
							}else{
								L=mid+1;
							}
						}
						// cout<<i<<endl;
						ans.push_back(bs[idx]+b_sum[k-1]-b_sum[idx]-b[i]);
						// cout<<i<<" "<<bs[idx]+b_sum[k-1]-b_sum[idx]<<endl;
					}else if(b_dp[i-1]>=tmp_m){
						ll idx=1222232421;
						ll L=0, R=i-1;
						// cout<<i<<endl;
						while(L<=R){
							ll mid=(L+R)/2;
							if(b_dp[mid]>=tmp_m){
								if(b_dp[mid]==tmp_m){
									idx=min(idx,mid);	
								}
								
								R=mid-1;
							}else{
								L=mid+1;
							}
						}
						ans.push_back(bs[idx]+a_sum[k-1]-a_sum[idx]-a[i]);	
						// if(idx==1222232421){
						// 	// ans.push_back()
						// 	// ans.push_back(bs[idx]+a_sum[k-1]-a_sum[idx]-a[i]);	
						// }else{
							
						// }
						cout<<i<<" "<<idx<<endl;
						
						// cout<<i<<" "<<idx<<" "<<bs[idx]+a_sum[k-1]-a_sum[idx]-a[i]<<endl;
					}
				}
			}
			// i+1~k-1
			if(!flag){
				// cout<<i<<" "<<a_dp[k-1]<<" "<<a_dp[i]<<" "<<b_dp[k-1]<<" "<<b_dp[i]<<endl;
				if(tmp_n==a_dp[k-1]-a_dp[i] && tmp_m==b_dp[k-1]-b_dp[i]){
					// cout<<i<<endl;
					ans.push_back(bs[k-1]-max(a[i],b[i]));
				}else{
					if(a_dp[k-1]-a_dp[i]>=tmp_n){
						// cout<<i<<endl;
						ll idx=1222232421;
						ll L=i+1, R=k-1;
						while(L<=R){
							ll mid=(L+R)/2;
							if(a_dp[mid]>=tmp_n){
								idx=min(idx,mid);
								R=mid-1;
							}else{
								L=mid+1;
							}
						}
						// cout<<i<<endl;
						ans.push_back(bs[idx]+b_sum[k-1]-b_sum[idx]-max(a[i],b[i]));
						// cout<<i<<" "<<bs[idx]+b_sum[k-1]-b_sum[idx]<<endl;
					}else if(b_dp[i-1]-b_dp[i]>=tmp_m){
						// cout<<i<<endl;
						ll idx=1222232421;
						ll L=i+1, R=k-1;
						while(L<=R){
							ll mid=(L+R)/2;
							if(b_dp[mid]>=tmp_m){
								idx=min(idx,mid);
								R=mid-1;
							}else{
								L=mid+1;
							}
						}
						// cout<<i<<" "<<idx<<endl;
						ans.push_back(bs[idx]+a_sum[k-1]-a_sum[idx]-max(a[i],b[i]));
						// cout<<i<<" "<<idx<<" "<<bs[idx]+a_sum[k-1]-a_sum[idx]-a[i]<<endl;
					}	
				}	
			}
			// cout<<i<<" "<<ans.size()<<endl;
		}	

		for(ll i=0;i<ans.size();++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";

	}
	return 0;
}