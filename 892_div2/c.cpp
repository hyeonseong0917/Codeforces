#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	bool visited[250+5];
	while(t--){
		int n=0;
		cin>>n;
		for(int i=0;i<250+5;++i){
			visited[i]=0;
		}
		long long ans=-1;
		for(int i=n;i>=1;--i){
			long long sum=0;
			for(int j=1;j<=n;++j){
				visited[j]=0;
			}
			//n번째 원소로 i를 가질 경우의 최대 합
			int cur_max=n*i;
			visited[i]=1;
			//n-1번째 원소부터 !visited[k]이면서 cur_max보다 작거나 같은 값을 찾는다
			for(int j=n-1;j>=1;--j){
				//j번째 원소를 어떤 수로?
				int cur_num=0;
				for(int k=n;k>=1;--k){
					if(!visited[k] && j*k<=cur_max){
					visited[k]=1;
						cur_num=k;
						break;
					}
				}
				sum+=(j*cur_num);
			}
			// cout<<sum<<"\n";
			ans=max(ans,sum);
		}
		cout<<ans<<"\n";
		cout<<"\n";
	}
	return 0;
}