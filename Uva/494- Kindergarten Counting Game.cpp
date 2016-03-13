#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
#define isw(x) (((x)>='a' && (x)<='z' )|| ((x)>='A' && (x)<='Z'))
int main(){
	string s;
	int i,ans;
	while(getline(cin,s)){
		ans=0;
		if(isw(s[0]))
			ans++;
		for(i=1;i<s.size()-1;i++)
			if(isw(s[i]) && !isw(s[i-1]))
				ans++;
		printf("%d\n",ans);
	}
}