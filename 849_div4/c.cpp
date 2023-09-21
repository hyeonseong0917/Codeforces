#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	map<char,int> m;
	while(t--){
		m.clear();
		int n;
		cin>>n;
		string str="";
		string bin_str="";
		cin>>str;
		//처음은 0으로 시작
		bin_str+='0';
		m[str[0]]=2;
		for(int i=1;i<n;++i){
			if(!m[str[i]]){
				if(bin_str[i-1]=='0'){
					bin_str+='1';
					m[str[i]]=1;
				}else{
					bin_str+='0';
					m[str[i]]=2;
				}

			}else{
				bin_str+=(m[str[i]]%2+'0');
			}
		}
		// cout<<bin_str<<endl;
		bool flag=0;
		for(int i=0;i<bin_str.size();++i){
			if(i-1>=0 && bin_str[i-1]==bin_str[i]){
				flag=1;
				break;
			}
			if(i+1<bin_str.size() && bin_str[i]==bin_str[i+1]){
				flag=1;
				break;
			}
		}
		if(flag==0){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}
		
	}
	return 0;
}