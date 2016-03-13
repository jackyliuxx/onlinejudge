#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;


bool ring(char s[]){
	int i,p=0,k[100],pk=0,num=0;
	for(i=0;i<strlen(s);i++){
		if(s[i]<='9' && s[i]>='0')
			num=10*num+s[i]-'0';
		else if(s[i]==',' && s[i-1]>='0' && s[i-1]<='9' ){
			k[pk++]=num;
			num=0;
		}
		else if(s[i]==')'){
			if(s[i-1]>='0' && s[i-1]<='9'){
				k[pk++]=num;
				num=0;
			}
			if(k[pk-1]!=k[pk-2])
				return false;
			else{
				k[pk-2]+=k[pk-1];
				pk--;
			}
		}
	}
	return true;
}


int main(){
	bool ans;
	char s[110];
	int n;
	scanf("%d",&n);
	while(n--){
		ans=true;
		scanf("%s",s);
		ans=ring(s);
		puts( ans ? "Yes" : "No" );
	}
}