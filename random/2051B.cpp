#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll n,a,b,c;
		cin>>n>>a>>b>>c;
		// n킬로미터를 가는데
		// 1일차에는 a킬로
		// 2일차에는 b킬로
		// 3일차에는 c킬로
		// 4일차에는 a
		// 5일차에는 b
		// 6일차에는 c
		// 며칠에 최소 nkm이상에 도달하게 되는지?

		// 1. cycle을 몇 번 돌아야 하는지?
		ll cycle=n/(a+b+c);
		ll d=cycle*3;
		ll cur_dist=cycle*(a+b+c);
		if(cur_dist>=n){
			cout<<d<<"\n";
			continue;
		}
		// 1일 추가
		cur_dist+=a;
		if(cur_dist>=n){
			cout<<d+1<<"\n";
			continue;
		}

		// 2일추가
		cur_dist+=b;
		if(cur_dist>=n){
			cout<<d+2<<"\n";
			continue;
		}
		cout<<d+3<<"\n";
	} 
	return 0;
}