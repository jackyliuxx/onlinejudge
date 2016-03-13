#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cstdio>
using namespace std;
int main(){
	char s1[101],s2[101];
	int a[101][101];
	int i,j,k=0;
	while(gets(s1),strcmp(s1,"#")){
		k++;
		gets(s2);
		for(i=0;i<101;i++)
			for(j=0;j<101;j++)
				a[i][j]=0;
		for(i=1;i<=strlen(s1);i++){
			for(j=1;j<=strlen(s2);j++){
				if(s1[i-1]==s2[j-1])
					a[j][i]=a[j-1][i-1]+1;
				else
					a[j][i]=max(a[j-1][i],a[j][i-1]);
			}
		}
		printf("Case #%d: you can visit at most %d cities.\n",k,a[j-1][i-1]);
	}
}
