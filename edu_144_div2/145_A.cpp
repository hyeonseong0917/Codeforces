#include <iostream>
#include <string>
#include <map>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		string s="";
		cin>>s;
		// operation을 언제 적용할 수 있냐면.. 이전 operation을 현재 operation을 적용하려는 색과 다르게 적용했을 경우
		// 어떤 숫자가 짝수 개면 안되지 않을까?
		// 33133
		// 3113
		map<char,int> m;
		int max_num=-1;
		for(int i=0;i<s.size();++i){
			char c=s[i];
			++m[c];
			max_num=max(max_num,m[c]);
		}
		// 3 3 1 3
		if(max_num==1 || max_num==2){
			cout<<4<<"\n";
		}else if(max_num==3){
			cout<<6<<"\n";
		}else{
			cout<<-1<<"\n";

		}
	}
	return 0;
}