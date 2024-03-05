#include <iostream>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	int dp[30+1];
	for(int i=0;i<30+1;++i){
		dp[i]=200;
	}
	dp[0]=0;
	dp[1]=1;
	dp[3]=1;
	dp[6]=1;
	dp[10]=1;
	dp[15]=1;
	for(int i=2;i<30;++i){
		dp[i]=min(dp[i-1]+1,dp[i]);
		if(i>=3){
			dp[i]=min(dp[i-3]+1,dp[i]);
		}
		if(i>=6){
			dp[i]=min(dp[i-6]+1,dp[i]);
		}
		if(i>=10){
			dp[i]=min(dp[i-10]+1,dp[i]);
		}
		if(i>=15){
			dp[i]=min(dp[i-15]+1,dp[i]);
		}
		// cout<<i<<" "<<dp[i]<<"\n";
	}
	while(t--){
		int N=0;
		cin>>N;
		if(N<30){
			cout<<dp[N]<<"\n";
			continue;
		}
		int fst_num=0;
		fst_num=N/15+dp[N%15];
		int sed_num=0;
		sed_num=N/15-1+dp[15+N%15];
		cout<<min(fst_num,sed_num)<<"\n";
	}
	return 0;
}