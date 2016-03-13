#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main(){
	int n;
	char words[11][16]={"####.##.##.####","..#..#..#..#..#","###..#####..###","###..####..####",
		"#.##.####..#..#","####..###..####","####..####.####","####.##.#..#..#",
		"####.#####.####","####.####..####","....#.###.#...."};
	scanf("%d",&n);
	while(n--){
		char s[5][510];
		int i,j,x,ans=0,now=0;
		for(i=0;i<5;i++)
			scanf("%s",s[i]);
		for(i=0;i<strlen(s[0]);i+=4){
			char s_now[16]={};
			for(j=0;j<5;j++)
				strncat(s_now,s[j]+i,3);
			for(j=0;j<11;j++)
				if(strcmp(s_now,words[j])==0)
					break;
			if(j<10)
				now=10*now+j;
			else{
				ans+=now;
				now=0;
			}
		}
		ans+=now;
		printf("%d\n",ans);
	}
}