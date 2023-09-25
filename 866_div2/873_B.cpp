#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
using namespace std;

//1510
const int MAX=100001+1;
int gcd(int a, int b){
	if(b==0){
		return a;
	}else{
		return gcd(b,a%b);
	}
}
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	// int arr[MAX]={0,};
	// bool check[MAX];
	vector<int> v;
	while(t--){
		int n=0;
		cin>>n;
		v.clear();
		map<int,int> m;
		
		// arr[값]=인덱스
		int k=1;
		// m[k]=1;
		for(int i=1;i<=n;++i){
			int a=0;
			cin>>a;
			int curNum=abs(a-i);
			// if(curNum!=0){
			// 	v.push_back(curNum);
			// }
			if(!m[curNum] && curNum!=0){
				m[curNum]=1;
				v.push_back(curNum);
			}
		}
		
		sort(v.begin(),v.end());
		k=v[0];
		for(int i=1;i<v.size();++i){
			if(v[i]%k!=0){
				k=gcd(v[i],k);
			}
		}
		
		cout<<k<<"\n";
	}
	return 0;
}