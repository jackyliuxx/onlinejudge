#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
#include<stdio.h>
using namespace std;
int main(){
	int n1,n2,s1[100],s2[100];
	int a[101][101];
	int i,j,k=0;
	while(cin>>n1>>n2,n1){
		k++;
		for(i=0;i<n1;i++)
			cin>>s1[i];
		for(i=0;i<n2;i++)
			cin>>s2[i];
		for(i=0;i<101;i++)
			for(j=0;j<101;j++)
				a[i][j]=0;
		for(i=1;i<n1+1;i++){
			for(j=1;j<n2+1;j++){
				if(s1[i-1]==s2[j-1])
					a[j][i]=a[j-1][i-1]+1;
				else
					a[j][i]=max(a[j-1][i],a[j][i-1]);
			}
		}
		printf("Twin Towers #%d\nNumber of Tiles : %d\n",k,a[j-1][i-1];
		puts("");
	}
}