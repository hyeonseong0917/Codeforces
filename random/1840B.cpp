#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
using namespace std;
 
#define ll long long
ll gcd(ll a, ll b){
	if(b==0) return a;
	return gcd(b,a%b);
}
ll lcm(ll a, ll b){
	return (a*b)/gcd(a,b);
}

int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		// k개의 다른 디저트들 제공
		// 디저트들은 0에서 k-1까지 번호가 있음
		// i번째 디저트의 가격은 2의 i제곱(0~k-1)
		// n 이하의 코인을 쓰고 싶음
		// 한 디저트는 최대 1개만
		// 디저트를 사는 다른 경우의 수 몇 개?
		ll n,k;
		cin>>n>>k;


		// n  k
		// 10 2

		// 0  1
		// 최대 몇 번까지 다 살 수 있는지??
		// c번까지 다사는거 가능하다면 2^c개 가능
		// n보다 크면 못삼

		// 161 -> 64까지 다사는건 가능 => 64개
		// 161-128 -> 33
		// 33-> 16까지 다 사는건 가능 => 16개
		// 128 32
		// 179 -> 64까지 다사는거 가능 => 64개
		// 179-128=51
		// 51 -> 16까지 다사는거 가능 => 
		if(k>=32){
			cout<<n+1<<"\n";
		}else{
			cout<<min((ll)pow(2,k),n+1)<<"\n";
		}
		
	} 
	return 0;
}