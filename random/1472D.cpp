#include <iostream>
#include <algorithm>
#include <vector>
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
		// A와 B는 길이 n의 수열 a에 대해 게임을 진행함
		// A가 먼저 ㅜㅁ직임
		// 각 턴에 플레이어는 원소 하나를 골라서 지움
		// 만약 A가 짝수를 선택했다면, 점수에 그 값 더함
		// B가 홀수를 선택했다면, 점수에 그 값 더함
		// 둘 다 최선으로 한다면 누가 우승할지??
		// 0607
		// [5,2,7,3,4,6,8]
		// 홀수: [7,5,3]
		// 짝수: [8,6,4]
		ll n;
		cin>>n;
		vector<ll> odd_vec, even_vec;
		for(ll i=0;i<n;++i){
			ll a;
			cin>>a;
			if(a%2==0){
				even_vec.push_back(a);
			}else{
				odd_vec.push_back(a);
			}
		}
		if(even_vec.empty() || odd_vec.empty()){
			if(even_vec.empty()){
				ll os=odd_vec.size();
				if(os==1){
					cout<<"Tie"<<"\n";
				}else{
					cout<<"Bob"<<"\n";
				}
			}else{
				cout<<"Alice"<<"\n";
			}
		}else{
			ll as=even_vec.size(), bs=odd_vec.size();
			sort(even_vec.rbegin(),even_vec.rend());
			sort(odd_vec.rbegin(),odd_vec.rend());
			ll a_idx=0, b_idx=0;
			ll cnt=0;
			ll a_sum=0, b_sum=0;
			// [5,2,7,3,4,6,8]
			// 홀수: [7,5,3]
			// 짝수: [8,6,4]


			// [2]
			// [7,5,3]
			while(a_idx<as || b_idx<bs){
				if(cnt%2==0){
					// Alice턴
					if(a_idx==as){
						++b_idx;
					}else{
						// a_idx<as,
						// b_idx==bs일수도?
						if(b_idx==bs){
							a_sum+=even_vec[a_idx++];
						}else{
							if(even_vec[a_idx]<=odd_vec[b_idx]){
								++b_idx;
							}else{
								a_sum+=even_vec[a_idx++];
							}
						}
						
					}
				}else{
					// Bob턴
					if(b_idx==bs){
						++a_idx;
					}else{
						// b_idx<bs
						if(a_idx==as){
							b_sum+=odd_vec[b_idx++];
						}else{
							if(odd_vec[b_idx]<=even_vec[a_idx]){
								++a_idx;
							}else{
								b_sum+=odd_vec[b_idx++];
							}
						}
						
					}
				}
				++cnt;
			}
			if(a_sum>b_sum){
				cout<<"Alice"<<"\n";
			}else if(a_sum<b_sum){
				cout<<"Bob"<<"\n";
			}else{
				cout<<"Tie"<<"\n";
			}
		}	

	} 
	return 0;
}