#include <iostream>
using namespace std;

//1227
int gcd(int a, int b){
	if(b==0){
		return a;
	}else{
		return gcd(b,a%b);
	}
}
int lcm(int a, int b){
	return (a*b)/gcd(a,b);
}
int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int n=0;
		cin>>n;
		//n=4 2 8 6 4
		int sum=0;
		for(int i=1;i<=n;++i){
			sum+=i;
		}
		int num=lcm(sum,n);
		// cout<<lcm(10,4);
		int to_mul=num/sum;
		for(int i=1;i<=n;++i){
			cout<<i*to_mul<<" ";
		}
		cout<<endl;
	}
	return 0;
}	