#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main(){
	int r[4],m[8],i,n,a,b,c;
	string s;
	for(i=0;i<8;i++)
		scanf("%d",&m[i]);
	scanf("%d",&n);
	while(n--){
		cin>>s;
		if(s=="LOAD"){
			scanf("%d%d",&a,&b);
			r[a]=m[b];
		}
		else if(s=="STORE"){
			scanf("%d%d",&a,&b);
			m[a]=r[b];
		}
		else if(s=="ADD"){
			scanf("%d%d%d",&a,&b,&c);
			r[a]=r[b]+r[c];
		}
		else if(s=="MOVE"){
			scanf("%d%d",&a,&b);
			r[a]=r[b];
		}
	}
	printf("%d\n%d",r[0],m[0]);
}