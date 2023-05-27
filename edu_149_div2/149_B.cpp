#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	// your code goes here
	int t=0;
	cin>>t;
	while(t--){
		int N=0;
		cin>>N;
		string s;
		cin>>s;
		int a=0;
		vector<int> v;
		map<int,int> m;
		m[a]=1;
		int cnt=1;
		int maxNum;
		int minNum;
		if(s[0]=='>'){
			maxNum=0;
			minNum=-1;
		}else{
			maxNum=1;
			minNum=0;
		}
		
		for(int i=0;i<s.size();++i){
			if(s[i]=='<'){
				if(i!=s.size()-1 && s[i+1]=='>'){
					// a=max(maxNum,a+1);
					if(a+1>maxNum){
						++a;
						maxNum=a;
							
					}else{
						a=maxNum;
					}
				}else{
					++a;
					maxNum=max(maxNum,a);
					
				}
				
			}else{
				if(i!=s.size()-1 && s[i+1]=='<'){
					// a=min(minNum,a-1);
					if(a-1<minNum){
						--a;
						minNum=a;
						
					}else{
						a=minNum;
					}
				}else{
					--a;
					maxNum=max(maxNum,a);
					
				}
				
			}
			if(!m[a]){
				m[a]=1;
				++cnt;
			}
			// cout<<a<<endl;
		}
		cout<<cnt<<endl;
	}
	return 0;
}