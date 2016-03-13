#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

char s[1010][110];

int cssort(int n){
	int i,j,v;
	char a[110];
	for(i=0;i<n-1;i++){
		for(j=0;j<n-i-1;j++){
			v=0;
			if(s[j][0]=='-' && s[j+1][0]=='-'){
				if(strlen(s[j])<strlen(s[j+1]) || (strlen(s[j])==strlen(s[j+1]) && strcmp(s[j],s[j+1])<0))
					v=1;
			}
			else if(s[j][0]=='-' || s[j+1][0]=='-'){
				if(s[j+1][0]=='-')
					v=1;
			}
			else{
				if(strlen(s[j])>strlen(s[j+1]) || (strlen(s[j])==strlen(s[j+1]) && strcmp(s[j],s[j+1])>0))
					v=1;
			}
			if(v){
				strcpy(a,s[j]);
				strcpy(s[j],s[j+1]);
				strcpy(s[j+1],a);
			}
		}
	}
	return 0;
}

int main(){
	int n,i;
	while(cin>>n){
		for(i=0;i<n;i++)
			scanf("%s",s[i]);
		cssort(n);
		for(i=0;i<n;i++)
			printf("%s\n",s[i]);
	}
}