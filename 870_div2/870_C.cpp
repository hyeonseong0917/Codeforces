#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int a,b=0;
		cin>>a>>b;
		int N=a*b;
		long long sum=0;
		vector<int> v;
		for(int i=0;i<N;++i){
			int c=0;
			cin>>c;
			v.push_back(c);
		}
		sort(v.begin(),v.end());
		int firstMin=v[0];
		int secondMax=v[N-2];
		int firstMax=v[N-1];
		int secondMin=v[1];
		int firstAns=0, secondAns=0;
		if(a<b){
			firstAns=abs((firstMin-secondMax)*(a-1))+abs((firstMin-firstMax)*(b-1)*a);
			secondAns=abs((firstMax-secondMin)*(a-1))+abs((firstMax-firstMin)*(b-1)*a);
		}else{
			firstAns=abs((firstMin-secondMax)*(b-1))+abs((firstMin-firstMax)*(a-1)*b);
			secondAns=abs((firstMax-secondMin)*(b-1))+abs((firstMax-firstMin)*(a-1)*b);
		}
		
		sum=max(firstAns,secondAns);
		cout<<sum<<endl;
	}
	return 0;
}