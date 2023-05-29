#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX=200001+1;
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	// int ma[MAX],mb[MAX];
	while(t--){
		int n=0;
		cin>>n;
		vector<int> a,b;
		vector<int> ma(2*n+1,0);
		vector<int> mb(2*n+1,0);
		// for(int i=0;i<n*2+2;++i){
		// 	ma[i]=0;
		// 	mb[i]=0;
		// }
		for(int i=0;i<n;++i){
			int c=0;
			cin>>c;
			a.push_back(c);
		}
		for(int i=0;i<n;++i){
			int c=0;
			cin>>c;
			b.push_back(c);
		}
		
		int aIdx=0;
		for(int i=1;i<n;++i){
			if(a[i]!=a[i-1]){
				ma[a[i-1]]=max(ma[a[i-1]],i-aIdx);
				aIdx=i;
			}
		}
		// cout<<a[n-1];
		ma[a[n-1]]=max(ma[a[n-1]],n-aIdx);
		// cout<<1;
		// return 0;
		int bIdx=0;
		for(int i=1;i<n;++i){
			if(b[i]!=b[i-1]){
				mb[b[i-1]]=max(mb[b[i-1]],i-bIdx);
				bIdx=i;
			}
		}
		
		mb[b[n-1]]=max(mb[b[n-1]],n-bIdx);
		
		int maxNum=0;
		for(int i=1;i<=2*n;++i){
			maxNum=max(maxNum,ma[i]+mb[i]);
		}
		
		cout<<maxNum<<"\n";
		
	}
	return 0;
}