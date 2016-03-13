#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int n,k=1,d1,d2,m1,m2,y1,y2,ans;
	char ch;
	scanf("%d",&n);
	while(n--){
		scanf("%d%c%d%c%d",&d1,&ch,&m1,&ch,&y1);
		scanf("%d%c%d%c%d",&d2,&ch,&m2,&ch,&y2);
		ans=y1-y2-1;
		if(m1>m2)
			ans++;
		else if(m1==m2 && d1>=d2)
			ans++;
		if(ans<0)
			printf("Case #%d: Invalid birth date\n",k++);
		else if(ans>130)
			printf("Case #%d: Check birth date\n",k++);
		else
			printf("Case #%d: %d\n",k++,ans);
	}
}