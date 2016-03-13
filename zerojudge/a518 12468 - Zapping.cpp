#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int a,b,ans;
	while(scanf("%d%d",&a,&b),a>=0){
		ans=(a-b+100)%100;
		if(100-ans<ans)
			ans=100-ans;
		printf("%d\n",ans);
	}
}