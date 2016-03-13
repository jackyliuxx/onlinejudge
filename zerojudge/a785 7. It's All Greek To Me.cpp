#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main(){
	char s[10000];
	char rp[3][7][5]={{"a","a","ai","a","w","w","w"},
	{"y","ei","ei","y","ou","ou","w"},
	{"w","ou","oi","w","ou","ou","w"}};
	char f[3]={'a','e','o'},af[7]={'a','e','i','y','o','o','w'};
	while(gets(s)&&strcmp(s,"END")){
		int i,j,k,l;
		int sl=strlen(s);
		for(i=0;i<sl;i++){
			if(s[i]=='-'){
				for(j=0;j<3;j++)
					if(s[i-1]==f[j])
						break;
				for(k=0;k<7;k++)
					if(s[i+1]==af[k])
						break;
				if(k==4 && s[i+2]=='u')
					k++;
				for(l=0;l<i-1;l++)
					putchar(s[l]);
				printf("%s",rp[j][k]);
				puts( k==5 ? s+i+3 : s+i+2 );
				break;
			}
		}
	}
}
