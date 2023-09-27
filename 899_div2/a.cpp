#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		//bi는양수, ai와 같으면 안됨 오름차순정렬
		//최소의 b값을 찾기
		int n=0;
		cin>>n;
		vector<int> v;
		for(int i=0;i<n;++i){
			int a=0;
			cin>>a;
			v.push_back(a);
		}
		vector<int> b;
		for(int i=0;i<v.size();++i){
			//b의 이전 값보다는 크고, v와는 달라야 함
			if(i==0){
				if(v[i]==1){
					b.push_back(2);
				}else{
					b.push_back(1);
				}
			}else{
				if(v[i]==b[b.size()-1]+1){
					b.push_back(v[i]+1);
				}else{
					b.push_back(b[b.size()-1]+1);
				}
			}
		}
		// for(int i=0;i<b.size();++i){
		// 	cout<<b[i]<<" ";
		// }cout<<endl;
		cout<<b[b.size()-1]<<"\n";
	}
	return 0;
}