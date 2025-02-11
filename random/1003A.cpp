#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <cmath>
#include <stack>
#include <queue>
using namespace std;

#define ll long long


int main() {
	// your code goes here
	int t=1;
	cin>>t;
	while(t--){
		string w;
		cin>>w;
		ll ws=w.size();
		w=w.substr(0,ws-2);
		w+='i';
		cout<<w<<"\n";
	} 	

	return 0;
}