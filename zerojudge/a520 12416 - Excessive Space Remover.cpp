#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main(){
	string s;
	int i,n,m,ans;
	while(getline(cin,s)){
		m=n=0;
		for(i=0;i<s.size();i++){
			if(s[i]==' '){
				m++;
				if(m>n)
					n=m;
			}
			else
				m=0;
			ans=0;
		}
		while(n>1){
			n=n/2+n%2;
			ans++;
		}
		printf("%d\n",ans);
	}
}
