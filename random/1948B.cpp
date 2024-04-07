#include <iostream>
#include <vector>
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
		int n;
		cin>>n;
		vector<int> v(n,0),dp(n,0);
		for(int i=0;i<n;++i){
			cin>>v[i];
		}
		if(v[0]/10<1){
			dp[0]=1;
		}else{
			int q=v[0]/10;
			int m=v[0]%10;
			if(q<=m){
				dp[0]=1;
			}else{
				dp[0]=0;
			}
		}
		for(int i=1;i<n;++i){
			if(dp[i-1]==0) break;
			if(v[i]/10<1){
				if(v[i-1]%10<=v[i]){
					dp[i]=1;
				}
			}else{
				int q=v[i]/10;
				int m=v[i]%10;
				if(q<=m){
					if(v[i-1]%10<=q){
						dp[i]=1;
					}
				}
			}
		}
		bool flag=0;
		for(int i=0;i<n-1;++i){
			// i 번째 수를 왜 쪼개야 되는데?
			// i번째 수가 i+1 번째 수보다 크다
			if(v[i]>v[i+1]){
				if(dp[i]==0){
					flag=1;
					break;
				}else{
					if(v[i]%10>v[i+1]){
						flag=1;
						break;
					}
				}
			}
		}
		// for(int i=0;i<n;++i){
		// 	cout<<i<<" "<<dp[i]<<"\n";
		// }
		if(!flag){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}

	}
	
	return 0;
}