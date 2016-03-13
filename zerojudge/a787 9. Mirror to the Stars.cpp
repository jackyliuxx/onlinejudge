#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	char name[100];
	int w,h,dw;
	char ins[5];
	char map[30][40];
	while(scanf("%s%d%d%s",name,&w,&h,ins)!=EOF){
		gets(map[0]);
		int i,j;
		for(i=0;i<h;i++)
			gets(map[i]);
		if(strcmp(ins,"R")==0)
			dw=1;
		else if(strcmp(ins,"I")==0)
			dw=2;
		else
			dw=3;
		puts(name);
		for( dw/2 ? i=h-1 : i=0 ; dw/2 ? i>=0 : i<h ; dw/2 ? i-- : i++ ){
			for( dw%2 ? j=w-1 : j=0 ; dw%2 ? j>=0 : j<w ; dw%2 ? j-- : j++ )
				putchar(map[i][j]);
			puts("");
		}
	}
}