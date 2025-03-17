#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <queue>
using namespace std;

#define ll long long

int main() {
	// your code goes here
	int o=1;
	cin>>o;
	while(o--){
		// 
		ll n;
		cin>>n;
		if(n<=100){
			cout<<"NO"<<"\n";
			continue;
		}
		string k=to_string(n).substr(0,2);
		if(k=="10"){
			if(to_string(n)[2]=='0'){
				cout<<"NO"<<"\n";
			}else{
				ll cur_num=stoi(to_string(n).substr(2));
				if(cur_num<=1){
					cout<<"NO"<<"\n";
				}else{
					cout<<"YES"<<"\n";
				}
			}
		}else{
			cout<<"NO"<<"\n";
		}
	} 

	return 0;
}