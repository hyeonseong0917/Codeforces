#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long
ll mod=998244353;
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		// phon with desktop
        // desktop -> 몇 개의 creen들로
        // 각 스크린은 5*3사이즈로
        // x개의 애플리케이션 1*1
        // y개의 애플리케이션 2*2
        // 최소의 개수로?
        // x개의 애플리케이션과 y개의 애플리케이션을 채우기 위한
        // screen의 최소 개수?
        ll x,y;
        cin>>x>>y;
        if(y==0){
            cout<<(x+14)/15<<"\n";
            continue;
        }
        if(x==0){
            cout<<(y+1)/2<<"\n";
            continue;
        }
        // 한 스크린에 y는 최대 2개, x는 최대 7개 가능
        ll cnt=(y+1)/2;
        ll m=y%2;
        m=2-m;
        x-=((cnt-1)*7+(15-4*m));
        if(x<=0){
            cout<<cnt<<"\n";
        }else{
            cout<<cnt+(x+14)/15<<"\n";
        }
	} 
	return 0;
}