#include <iostream>
#include <vector>
using namespace std;
//1017
const int MAX=200000+1;
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	int m[MAX];
	while(t--){
		int maxNum=-1;
		for(int i=0;i<MAX;++i){
			m[i]=0;
		}
		int n=0;
		cin>>n;
		vector<int> a,b;
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
		++m[a[0]];
		++m[b[0]];
		maxNum=max(maxNum,m[a[0]]);
		maxNum=max(maxNum,m[b[0]]);
		for(int i=1;i<n;++i){
			int curA=a[i];
			int curB=b[i];
					
			if(!m[curA] || !m[curB]){
				if(m[curA]){
					++m[curA];
					maxNum=max(m[curA],maxNum);
				}
				if(m[curB]){
					++m[curB];
					maxNum=max(m[curB],maxNum);
				}
				if(!m[curA]){
					m[curA]=1;
					m[a[i-1]]=0;
				}
				if(!m[curB]){
					m[curB]=1;
					m[b[i-1]]=0;
				}
			}else{
				++m[curA];
				++m[curB];
				maxNum=max(m[curA],maxNum);
				maxNum=max(m[curB],maxNum);
			}
			cout<<m[1]<<endl;
		}
		
		
		cout<<maxNum<<"\n";
	}
	return 0;
}