#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX=200000+5;

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	pair<long long,long long> arr[MAX];
	while(t--){
		int n,k,a,b;
		for(int i=1;i<=n;++i){
			arr[i]={0,0};
		}
		cin>>n>>k>>a>>b;
		for(int i=1;i<=n;++i){
			long long x,y=0;
			cin>>x>>y;
			arr[i]=make_pair(x,y);
		}
		long long ans=abs(arr[a].first-arr[b].first)+abs(arr[a].second-arr[b].second);
		
		if(a<=k && b<=k){
			//a,b 둘 다 메이저인 경우
			cout<<0<<"\n";
		}else if(a<=k && b>k){
			//a는 메이저, b는 비메이저
			//메이저 도시 중 b와 가장 인접한 도시를 찾아야함
			for(int i=1;i<=k;++i){
				long long cur_fee=abs(arr[i].first-arr[b].first)+abs(arr[i].second-arr[b].second);
				ans=min(ans,cur_fee);
			}
			cout<<ans<<"\n";
		}else if(a>k && b<=k){
			//a는 비메이저, b는 메이저
			//메이저 도시 중 a와 가장 인접한 도시를 찾아야함
			for(int i=1;i<=k;++i){
				long long cur_fee=abs(arr[i].first-arr[a].first)+abs(arr[i].second-arr[a].second);
				ans=min(ans,cur_fee);
			}
			cout<<ans<<"\n";
		}else if(a>k && b>k){
			//a는 비메이저, b도 비메이저
			//a에서 a와 가장 가까운 메이저+b에서 b와 가장 가까운 메이저의 최솟값
			long long min_a=4000000000+5;
			long long min_b=4000000000+5;
			for(int i=1;i<=k;++i){
				long long cur_fee=abs(arr[i].first-arr[a].first)+abs(arr[i].second-arr[a].second);
				min_a=min(min_a,cur_fee);
			}
			for(int i=1;i<=k;++i){
				long long cur_fee=abs(arr[i].first-arr[b].first)+abs(arr[i].second-arr[b].second);
				min_b=min(min_b,cur_fee);
			}
			long long cur_min_fee=min_a+min_b;
			ans=min(ans,cur_min_fee);
			cout<<ans<<"\n";
		}
		
		
	}
	return 0;
}