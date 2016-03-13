#include<cstdio>
using namespace std;
int main(){
	int n;
	int i,j;
	while(scanf("%d",&n),n){
		int n8=n*8;
		for(i=0;i<n8;i++){
			for(j=0;j<n8;j++){
				if((i/n+j/n)%2)
					putchar('.');
				else
					putchar('#');
			}
			puts("");
		}
	}
}