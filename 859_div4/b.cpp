#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// i번째 가방: ai개의 사탕
// 1번째가방부터 n번째 가방까지
// 짝수 -> Mihai, 홀수 -> Bianca
// player의 total 개수에 더해짐
// 

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	int n=0;
	while(t--){
		
		int even_sum=0;
		int odd_sum=0;
		cin>>n;
		for(int i=0;i<n;++i){
			int a=0;
			cin>>a;
			if(a%2==0){
				even_sum+=a;
			}else{
				odd_sum+=a;
			}
		}
		if(even_sum<=odd_sum){
			cout<<"NO"<<"\n";
		}else{
			cout<<"YES"<<"\n";
		}
		
		
		
	}
	return 0;
}