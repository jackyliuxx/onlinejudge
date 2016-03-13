#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main(){
	string s;
	char c;
	int mx,my,x,y,w,a[10000],b[10000],c2[10000],ap=0,i,j,p;
	scanf("%d%d",&mx,&my);
	while(~scanf("%d%d %c",&x,&y,&c)){
		cin>>s;
		w=(c>='E')+(c>='S')+(c>='W')-(c=='N');
		for(i=0;i<s.size();i++){
			p=0;
			if(s[i]=='L'){
				w--;
				if(w<0)
					w+=4;
			}
			else if(s[i]=='R'){
				w++;
				w%=4;
			}
			else{
				if(w%2){
					if((x+1-2*(w/2))>mx || (x+1-2*(w/2))<0){
						if(ap){
							for(j=0;j<ap;j++){
								if(a[j]==x&&b[j]==y){
									p=1;
									break;
								}
							}
							if(p)
								continue;
						}
						a[ap]=x,b[ap]=y,c2[ap]=w,ap++;
						break;
					}
					else
						x=x+1-2*(w/2);
				}
				else{
					if((y+1-2*(w/2))>my || (y+1-2*(w/2))<0){
						if(ap){
							for(j=0;j<ap;j++){
								if(a[j]==x && b[j]==y){
									p=1;
									break;
								}
							}
							if(p)
								continue;
						}
						a[ap]=x,b[ap]=y,c2[ap]=w,ap++;
						break;
					}
					else
						y=y+1-2*(w/2);
				}
			}
		}
		if(w==0)
			c='N';
		else if(w==1)
			c='E';
		else if(w==2)
			c='S';
		else 
			c='W';
		if(i!=s.size())
			printf("%d %d %c LOST\n",x,y,c);
		else
			printf("%d %d %c\n",x,y,c);
	}
}