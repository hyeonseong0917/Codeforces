#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>
using namespace std;

int main() {
	// your code goes here
	ios_base :: sync_with_stdio(false); 
	cin.tie(NULL); 
	cout.tie(NULL);
	int t=0;
	cin>>t;
	while(t--){
		int N,M,K;
		cin>>N>>M>>K;
		set<int> a,b;
		map<int,int> m;
		for(int i=0;i<N;++i){
			int c=0;
			cin>>c;
			if(c<=K){
				if(!m[c]){
					++m[c];	
				}
				a.insert(c);	
			}
		}
		for(int i=0;i<M;++i){
			int c=0;
			cin>>c;
			if(c<=K){
				if(!m[c]){
					++m[c];	
				}
				b.insert(c);	
			}
		}
		for(int i=1;i<=K;++i){
			if(a.count(i)==1 && b.count(i)==1){
				++m[i];
			}
		}
		vector<int> tmp;
		int a_cnt=0, b_cnt=0;
		for(int i=1;i<=K;++i){
			if(m[i]==1){
				if(a.count(i)==1){
					++a_cnt;
				}
				if(b.count(i)==1){
					++b_cnt;
				}
			}else if(m[i]>=2){
				tmp.push_back(i);
			}
		}
		// cout<<a_cnt<<" "<<b_cnt<<"\n";
		for(int i=0;i<tmp.size();++i){
			if(a_cnt<b_cnt){
				++a_cnt;
			}else{
				++b_cnt;
			}
		}
		// cout<<a_cnt<<" "<<b_cnt<<"\n";
		if(a_cnt==(K/2) && b_cnt==(K/2)){
			cout<<"YES"<<"\n";
		}else{
			cout<<"NO"<<"\n";
		}

	}
	return 0;
}