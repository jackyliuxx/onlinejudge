#include<iostream>
#include<stdio.h>
using namespace std;

long long s[66][66][2]={};

int main(){
	int n,x,i,j;
	s[1][0][0]=1;
	s[1][1][1]=1;
	for(i=2;i<=65;i++){
		for(j=0;j<=i;j++){
			s[i][j][0]=s[i-1][j][0]+s[i-1][j][1];
			s[i][j][1]=s[i-1][j][0];
			if(j)
				s[i][j][1]+=s[i-1][j-1][1];
		}
	}
	while(cin>>n>>x,n>=0)
		cout<<s[n][x][0]+s[n][x][1]<<endl;
}

