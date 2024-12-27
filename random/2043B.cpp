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
	int o=1;
	cin>>o;
	while(o--){
		ll n,d;
		cin>>n>>d;
		// d를 n!만큼 나열한 수가 1,3,5,7,9 중 어떤걸로 나누어지는지?
		// ddddddddddddddddddddddd...120개 n==5
		vector<ll> ans;
		ans.push_back(1);
		// 3 가능?
		// 합이 3의 배수인지?
		// n!*d
		if(d==3 || d==6 || d==9){
			ans.push_back(3);
		}else{
			// d는 3이아님
			if(n>=3){
				ans.push_back(3);
			}
		}
		
		// 5 가능?
		if(d==5 || d==0){
			ans.push_back(5);
		}

		// 7 가능?
		// 7 14 21 28 35 42 49 63 70 77
		if(d==7){
			ans.push_back(7);
		}else{
			if(n>=3){
				ans.push_back(7);
			}
		}
		// 9 가능?
		// 9 18 27 36 45 54 63 72 81 90 
		if(d==9){
			ans.push_back(9);
		}else{
			if(d==3 || d==6){
				if(n>=3){
					ans.push_back(9);
				}
			}else{
				if(n>=6){
					ans.push_back(9);
				}
			}
		}
		for(int i=0;i<ans.size();++i){
			cout<<ans[i]<<" ";
		}cout<<"\n";
	}
	return 0;
}