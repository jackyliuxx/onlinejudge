#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
char *lia(char a[],char b[]){
	static char ans[1000];
	int i,tn=0;
	for(i=0;i<strlen(a) || i<strlen(b) || tn;i++){
		ans[i]=tn+(i<strlen(a))*(a[i]-'0')+(i<strlen(b))*(b[i]-'0');
		tn=ans[i]/10;
		ans[i]=ans[i]%10+'0';
	}
	return ans;
}

int main(){
	char a[1010][1000]={"1","1","1","1"};
	int n,i;
	for(i=4;i<1010;i++){
		strcpy(a[i],lia(a[i-3],a[i-2]));
	}
	for(i=0;i<1010;i++)
		reverse(a[i],a[i]+strlen(a[i]));
	while(cin>>n)
		puts(a[n]);
}