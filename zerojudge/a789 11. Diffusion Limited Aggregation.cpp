#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int px[8]={-1,0,1,-1,1,-1,0,1},py[8]={-1,-1,-1,0,0,1,1,1};

void flow(int x,int y,int a[][11],char map[][20]){
	if(map[x][y]=='*')
		return;
	map[x][y]='*';
	int i,mnn=a[x][y],mnp=-1;
	for(i=0;i<8;i++){
		if(x+px[i]<0 || x+px[i]>10 || y+py[i]<0 || y+py[i]>10)
			continue;
		if(a[x+px[i]][y+py[i]]<mnn)
			mnn=a[x+px[i]][y+py[i]],mnp=i;
	}
	if(mnp!=-1)
		flow(x+px[mnp],y+py[mnp],a,map);
}

int main(){
	int a[11][11];
	char map[20][20];
	while(cin>>a[0][0]){
		int i,j;
		for(i=0;i<11;i++)
			for(j=0;j<11;j++)
				if(i+j)
					cin>>a[i][j];
		for(i=0;i<11;i++)
			for(j=0;j<11;j++)
				map[i][j]='.';
		for(i=0;i<11;i++)
			map[i][11]=0;
		int x,y;
		while(cin>>x>>y,x>=0 && y>=0)
			flow(y,x,a,map);
		for(i=0;i<11;i++)
			puts(map[i]);
	}
}