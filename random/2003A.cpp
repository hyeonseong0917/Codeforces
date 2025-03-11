#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int o=1;
	cin>>o;
	while(o--){
		// S가 좋은 문자열인지?
		// 적어도 두 개 이상의 부분 ㅜㄴ자열로 분할
		// s=t1+t2+tk
		// 1<=i<j<=k
		ll n;
		cin>>n;
		string s;
		cin>>s;
		if(s[0]==s[s.size()-1]){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
		}
	} 
	return 0;
}