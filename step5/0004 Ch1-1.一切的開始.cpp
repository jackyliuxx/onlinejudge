#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <map>
using namespace std;

int main () {
	int n;
	char x;
	while(cin>>n){
		int t[2]={};
		for(int i=0;i<n;i++){
			cin>>x;
			if(i==0)
				t[(x-'0')==0]=1,x='x';
			if(x=='1'){
				t[0]=min(t[0]+1,t[1]+1);
				t[1]=min(t[0]+1,t[1]);
			}
			if(x=='0'){
				t[0]=min(t[0],t[1]+1);
				t[1]=min(t[0]+1,t[1]+1);
			}
		}
		cout<<t[1]<<endl;
	}
}
