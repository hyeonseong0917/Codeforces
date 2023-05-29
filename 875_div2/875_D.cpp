#include <iostream>
#include <map>
using namespace std;
//1330
//1350
int n,m=0;
bool flag=0;
map<int,int> MAP;
void dfs(int num){
	
	if(num==m){
		flag=1;
		return;
	}
	if(num%3!=0){
		return;
	}
	
	if(MAP[num]==0){
		++MAP[num];
		dfs((num*2)/3);
		dfs(num/3);
	}
	
}
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		flag=0;
		cin>>n>>m;
		MAP.clear();
		if(n==m){
			cout<<"YES"<<endl;
			continue;
		}
		if(n%3!=0 || n<m){
			cout<<"NO"<<endl;
			continue;
		}
		dfs(n);
		if(flag==1){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}