#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

#define ll long long
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		ll m,k,a1,ak;
		cin>>m>>k>>a1>>ak;
		if(ak*k>=m){
			m%=k;
			m-=a1;
			m=max((ll)0,m);
			cout<<m<<"\n";
		}else{
			// ak*k<m
			m-=ak*k; // 현재 ak다썼음
			ll ans=0;
			if(m>=k){
				// ak fancy coin을 써야함
				// m%ak==0을 만들어야함 a1과 a1fancy 사용해서
				// ak fancy coin을 최대한 많이 사용해야함
				if(a1>=m){
					cout<<0<<"\n";
					continue;
				}
				// 1. a1코인은 얼마나 어떻게 써야할까?
				// (m-(a1+fa1))이 k의 제일 큰 배수여야함
				
				// a1만으로 k의 제일 큰 배수를 만들 수 있는 경우
				if(m/k==(m-a1)/k){
					m-=a1;
					ans+=m%k;
					m-=m%k;
					ans+=m/k;
					
				}else{
					if((m-a1)%k==0){
						ans=(m-a1)/k;
					}else{
						// (m-a1)%k!=0
						ll q=(m-a1)/k+1;
						// ans+=k*q-(m-a1);
						ans+=q;
					}

				}
				cout<<ans<<"\n";
			}else{
				// m<ak
				// 다 a1혹은 a1fancy로만 만들어야함
				m-=a1;
				m=max(m,(ll)0);
				cout<<m<<"\n";
			}
		}
	} 
	return 0;
}