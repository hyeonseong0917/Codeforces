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
		// 1년차에 1개의 잎
		// i번째 해에는 i*i개의 새로운 잎이 자람
		// i년에 자란 잎은 i+k-1년까지 지속됨
		// 년도 n에 나뭇잎의 개수가 짝수인지?
		ll n,k;
		cin>>n>>k;
		if(n==1){
			cout<<"NO"<<"\n";
			continue;
		}
		if(k==1){
			if(n%2==1){
				cout<<"NO"<<"\n";
			}else{
				cout<<"YES"<<"\n";
			}
			continue;
		}
		if(k==2){
			cout<<"NO"<<"\n";
			continue;
		}
		// n=3, k=2	
		// 1년차: 1
		// 2년차: 4개 자람. 1개 지속되는중=5
		// 3년차: 27개 자람. 4개 지속되는중=31
		// 4년차: 4의 4개 자람. 27개 지속되는중
		ll L=n-k+1;
		if(L%2==0){
			++L;
		}
		ll R=n;
		if(R%2==0){
			--R;
		}
		ll cnt=(R-L)/2+1;
		if(cnt%2==0){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}

	} 
	return 0;
}