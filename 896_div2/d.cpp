#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

long long gcd(long long a, long long b)
{
	long long c;
	while (b != 0)
	{
		c = a % b;
		a = b;
		b = c;
	}
	return a;
}
long long lcm(long long a, long long b)
{
    return a * b / gcd(a, b);
}

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		long long n,x,y;
		cin>>n>>x>>y;
		long long k=lcm(x,y);
		long long p=n/k;
		long long x_num=n/x;
		long long y_num=n/y;	
		long long ans=0;
		
		long long x_sum=0;
		if((x_num-p)%2==0){
			x_sum=(n+n+x_num-p-1)*(x_num-p)/2;
		}else{
			x_sum=(n+n+x_num-p-1)*(((x_num-p)/2)-1);
			x_sum+=(n+n+x_num-p-1)/2;
		}
		long long y_sum=0;
		if((y_num-p)%2==0){
			y_sum=(y_num-p)*(y_num-p+1)/2;
		}else{
			y_sum=(y_num-p)*(((y_num-p)/2));
			y_sum+=(y_num-p+1)/2;
		}
		cout<<x_sum<<" "<<y_sum<<endl;
		cout<<x_sum-y_sum<<endl;
		cout<<endl;
	}
	return 0;
}