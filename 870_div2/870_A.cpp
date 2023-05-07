#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
 
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int N=0;
		cin>>N;
		vector<int> A;
		map<int,int> m; // m[5]=1
		for(int i=0;i<N;++i){
			int a=0;
			cin>>a;
			A.push_back(a);
		}
		int cnt=0;
		sort(A.begin(),A.end());
		// bool flag=0;
		for(int i=0;i<N;++i){
			int curNum=A[i];
			if(curNum>N-i){
				++cnt;
			}else if(curNum==N-i){
				cnt=-1;
				break;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}