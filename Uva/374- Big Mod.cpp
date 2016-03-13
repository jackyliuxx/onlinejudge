#include<stdio.h>
int main(){
	int b,p,m,i,ans;
	while(~scanf("%d",&b)){
		scanf("%d%d",&p,&m);
		b%=m;
		ans=1;
		for(i=p;i>0;i/=2){
			if(i%2)
				ans=(ans*b)%m;
			b=(b*b)%m;
		}
		printf("%d\n",ans);
	}
}