#include <iostream>
#include <map>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int N;
		string s;
		cin>>N;
		cin>>s;
		int cnt=1;
		map<char,int> m;
		m[s[0]]=1;
		for(int i=1;i<N;++i){
			//0에서 i까지 다른 문자들의 개수
			++m[s[i]];
			cnt+=m.size();
		}
		cout<<cnt<<"\n";
	}
	return 0;
}