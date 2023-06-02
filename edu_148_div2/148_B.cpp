#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
//1017
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	vector<long long> a;
	vector<long long> psum(200000+1,0);
	while(t--){
		int n,k,ok=0;
		cin>>n>>k;
		a.clear();
		psum.clear();
		
		for(int i=0;i<n;++i){
			long long c=0;
			cin>>c;
			a.push_back(c);
		}
		
		sort(a.begin(),a.end());
		psum[0]=a[0];
		for(int i=1;i<n;++i){
			psum[i]=psum[i-1]+a[i];
		}
		long long maxNum=0;
		//앞에서 m*2개, 뒤에서 k-m개 삭제
		// 1 2 5 6 10
		for(int m=0;m<=k;++m){
			// cout<<m<<"\n";
			if(m==0){
				maxNum=psum[n-1-k];
				// cout<<maxNum;
			}else{
				// cout<<m*2<<endl;
				long long first_sum=psum[(m*2)-1];
				long long second_sum=psum[n-1-(k-m)];
				maxNum=max(maxNum,second_sum-first_sum);
			}	
		}
		cout<<maxNum<<"\n";
	}
	return 0;
}