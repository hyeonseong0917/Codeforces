#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int n=0;
		cin>>n;
		//앞에 있는 로봇의 수
		vector<int> L;
		map<int,int> m;
		for(int i=0;i<n;++i){
			int a=0;
			cin>>a;
			L.push_back(a);
			++m[a];
		}
		// sort(L.rbegin(),L.rend());
		sort(L.begin(),L.end());
		reverse(L.begin(),L.end());
		bool flag=0;
		//L[i]에 대해서..0~L[i]값이 존재해야..
		for(int i=0;i<n;++i){
			int cur_num=L[i];
			if(!m[cur_num]) continue;
			for(int j=cur_num;j>=0;--j){
				if(m[j]){
					--m[j];
				}else{
					flag=1;
					break;
				}
			}
			if(flag==1){
				break;
			}
		}
		if(flag==0){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
	}
	return 0;
}