#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int> a(n,0), dp(n,0);
		for(int i=0;i<n;++i){
			cin>>a[i];
		}
		dp[0]=a[0];
		for(int i=1;i<n;++i){
			int cur_num=abs(a[i]);
			int pre_num=abs(a[i-1]);
			if(cur_num%2==0){
				if(pre_num%2==1){
					dp[i]=max(dp[i-1],0)+a[i];
				}else{
					dp[i]=a[i];
				}
			}else{
				if(pre_num%2==0){
					dp[i]=max(dp[i-1],0)+a[i];
				}else{
					dp[i]=a[i];
				}
			}
		}
		int ans=-1222232421;
		for(int i=0;i<n;++i){
			ans=max(ans,dp[i]);
		}
		cout<<ans<<"\n";
	}
	
	return 0;
}