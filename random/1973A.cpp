#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		// 이기면 2포인트, 지면 0포인트, 비기면 1포인트
		ll a,b,c;
		cin>>a>>b>>c;
		// 3 3 3
		if((c-(b-a))%2==1){
			cout<<-1<<"\n";
		}else{
			// 3 4 5
			// 0 4 2
			// 0 2 2
			ll cur_num=0;
			if(a+b-c>=0){
				cur_num=(a+b-c)/2+c;
			}

			cout<<max(min(a+b,c),cur_num)<<"\n";
		}
	}
	return 0;
}