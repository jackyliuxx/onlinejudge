#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
	int n,i;
	char s[10];
	while(~scanf("%d",&n)){
		for(i=n;i>0;i--)
			s[n-i]=i+'0';
		s[n]=0;
		printf("%s\n",s);
		while(prev_permutation(s,s+n))
			printf("%s\n",s);
	}
}