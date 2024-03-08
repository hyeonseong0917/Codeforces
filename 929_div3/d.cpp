#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		int N;
		vector<int> v;
		map<int,int> m;
		cin>>N;
		for(int i=0;i<N;++i){
			int a=0;
			cin>>a;
			if(!m[a]){
				v.push_back(a);
			}
			++m[a];
		}
		sort(v.begin(),v.end());
		int min_num=v[0];
		if(m[min_num]>=2){
			bool flag=0;
			for(int i=1;i<v.size();++i){
				if(v[i]%min_num!=0){
					flag=1;
					break;
				}
			}
			if(flag){
				cout<<"YES"<<"\n";
			}else{
				cout<<"NO"<<"\n";
			}
		}else{
			cout<<"YES"<<"\n";
		}
	}
	return 0;
}