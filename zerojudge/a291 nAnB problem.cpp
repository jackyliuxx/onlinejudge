#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int a[4],b[4],n,i,j,ansa,ansb;
	while(scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3])!=EOF){
		scanf("%d",&n);
		while(n--){
			int ua[4]={};
			for(i=0;i<4;i++)
				scanf("%d",&b[i]);
			ansa=ansb=0;
			for(i=0;i<4;i++)
				if(a[i]==b[i])
					ua[i]=b[i]=10,ansa++;
			for(i=0;i<4;i++)
				for(j=0;ua[i]<10 && j<4;j++)
					if(a[i]==b[j])
						ua[i]=b[j]=10,ansb++;
			printf("%dA%dB\n",ansa,ansb);
		}
	}
}