#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int n=0;
		vector<int> v;
		cin>>n;
		for(int i=0;i<n;++i){
			int a=0;
			cin>>a;
			v.push_back(a);
		}
		sort(v.begin(),v.end());
		bool isAllOdd=1;
		bool isAllEven=1;
		vector<int> b,c;
		b.clear();
		c.clear();
		for(int i=0;i<v.size();i++){
			if(v[i]%2==0){
				isAllOdd=0;
				break;
			}
		}
		for(int i=0;i<v.size();i++){
			if(v[i]%2==1){
				isAllEven=0;
				break;
			}
		}
		if(isAllEven || isAllOdd){
			// cout<<v.size();
			int minNum=v[0];
			b.push_back(minNum);
			for(int i=1; i<v.size(); ++i){
				if(v[i]==minNum){
					b.push_back(v[i]);
				}else{
					c.push_back(v[i]);
				}
				// cout<<i<<endl;
			}
			// cout<<c.empty();
			if(c.size()==0){
				cout<<-1<<"\n";
			}else{
				cout<<b.size()<<" "<<c.size()<<"\n";
				for(int i=0;i<b.size();++i){
					cout<<b[i]<<" ";
				}cout<<"\n";
				for(int i=0;i<c.size();++i){
					cout<<c[i]<<" ";
				}cout<<"\n";
			}
		}else{
			for(int i=0;i<v.size();++i){
				if(v[i]%2==0){
					c.push_back(v[i]);
				}else{
					b.push_back(v[i]);
				}
			}
			cout<<b.size()<<" "<<c.size()<<"\n";
			for(int i=0;i<b.size();++i){
				cout<<b[i]<<" ";
			}cout<<"\n";
			for(int i=0;i<c.size();++i){
				cout<<c[i]<<" ";
			}cout<<"\n";
		}
		cout<<"\n";
	}
	return 0;
}