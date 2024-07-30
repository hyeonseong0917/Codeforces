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
		ll x,y,k;
		cin>>x>>y>>k;
		// x에 1을 k번 더한다
		// x가 y로 나누어 떨어지면 x/=y
		// 1. y의 배수 중 x보다 큰 최초의 수 찾기
		// 2. y*((x/y)+1)
		bool flag=0;
		// 1 3 7
		// x k
		// 2 6
		// 1 5
		// 2 4
		// 1 3
		// 2 2
		// 1 1
		// 2 0
		// 1 3 2
		// 2 1
		// 1 0
		while(k){
			// cout<<x<<" "<<y<<" "<<k<<endl;
			
			if(x<y){
				if(y>k){
					flag=1;
					x=(x+k)/y+(x+k)%y;
					
					break;

				}
				x=(x+k%(y-1))/y+(x+k%(y-1))%y;
				if(x==0) x=1;
				flag=1;
				break;
			}
			// cout<<x<<" "<<y<<endl;
			ll next_x=y*((x/y)+1);
			// cout<<x<<" "<<y<<" "<<next_x<<" "<<k<<endl;
			// cout<<x<<" "<<next_x<<" "<<k<<endl;
			if(k>=next_x-x){
				k-=(next_x-x);
				x=next_x;
				while(x%y==0){
					x/=y;
				}
				// cout<<"ok"<<endl;
			}else{
				// cout<<next_x<<endl;
				break;
			}
		}
		if(!flag){
			x+=k;
			while(x%y==0){
				x/=y;
			}
		}
		
		cout<<x<<"\n";
	}
	return 0;
}