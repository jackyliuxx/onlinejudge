#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <list>
using namespace std;

int main () {
	int b;
	int n;
	string s;
	cin>>b;
	cin>>n;
	int i;
	int x;
	int ans[2]={0,0};
	for(i=0;i<n;i++){
		cin>>x>>s;
		int k;
		int s10=0;
		int j=s.size()-1;
		for(k=1;j>=0;j--,k*=x){
			if(s[j]>='A')
				s[j]=s[j]-'A'+10;
			else
				s[j]-='0';
			s10+=s[j]*k;
		}
		if(s10>=b)
			continue;
		s10+=b;
		int bn=0;
		while(s10){
			if(s10 % 2)
				bn++;
			s10/=2;
		}
		if(bn>ans[0])
			ans[0]=bn,ans[1]=1;
		else if(bn==ans[0])
			ans[1]++;
	}
	cout<<ans[0]<<' '<<ans[1]<<endl;
}
