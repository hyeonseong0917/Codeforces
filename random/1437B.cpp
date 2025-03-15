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
		// 1320
		string s;
		ll n;
		cin>>n;
		// s를 alternate로 만들기 위한 최소 횟수
		// operation: s의 아무 서브스트링을 리버스 할 수 있음
		cin>>s;
		// n은 짝수이고 s는 절반의 0과 절반의 1 가지고 있음
		// 11101000
		// 00의 개수
		string fst_str="1"+s+"0";
		string sed_str="0"+s+"1";
		ll fst_cnt=0, sed_cnt=0;
		for(ll i=0;i<n+1;++i){
			if(fst_str[i]==fst_str[i+1]){
				++fst_cnt;
			}
		}
		for(ll i=0;i<n+1;++i){
			if(sed_str[i]==sed_str[i+1]){
				++sed_cnt;
			}
		}
		cout<<min(fst_cnt/2,sed_cnt/2)<<"\n";
	} 

	return 0;
}