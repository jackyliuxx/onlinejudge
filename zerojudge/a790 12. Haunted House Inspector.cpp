#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;

int px[4]={-1,0,1,0},py[4]={0,1,0,-1};
queue<int> qx,qy,qst; 

void gos(int x,int y,char map[][70],int nl,int sl,int w,int l){
	map[x][y]='.';
	if(nl==sl)
		return;
	int i;
	for(i=0;i<4;i++){
		if(x+px[i]<0 || x+px[i]>=w || y+py[i]<0 || y+py[i]>=l)
			continue;
		if(map[x+px[i]][y+py[i]]!='#' && map[x+px[i]][y+py[i]]!='.'){
			qx.push(x+px[i]);
			qy.push(y+py[i]);
			qst.push(nl+1);
		}
	}
}

int main(){
	int l,w,sl;
	char map[15][70];
	while(scanf("%d%d%d",&l,&w,&sl)!=EOF){
		gets(map[0]);
		int i,j;
		for(i=0;i<w;i++)
			gets(map[i]);
		bool brk=false;
		for(i=0;i<w;i++){
			for(j=0;j<l;j++){
				if(map[i][j]=='S'){
					brk=true;
					break;
				}
			}
			if(brk)
				break;
		}
		while(qx.empty()==false)
			qx.pop();
		while(qy.empty()==false)
			qy.pop();
		while(qst.empty()==false)
			qst.pop();
		qx.push(i),qy.push(j),qst.push(1);
		while(qx.empty()==false){
			gos(qx.front(),qy.front(),map,qst.front(),sl,w,l);
			qx.pop();
			qy.pop();
			qst.pop();
		}
		int sf=0;
		for(i=0;i<w;i++)
			for(j=0;j<l;j++)
				if(map[i][j]=='F')
					sf=1;
		for(i=0;i<w;i++)
			puts(map[i]);
		if(sf==0)
			printf("\nAll Fires Extinguished!\n");
	}
}