#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#include <list>
#include <map>
using namespace std;

int walk[4]= {4,-4,1,-1};
bool end;

//#define chr(x,y) (abs(((x)-1)/4-(y)/4)+abs(((x)-1)%4-(y)%4))
int chr(int x,int y){
	int a=(abs(((x)-1)/4-(y)/4)+abs(((x)-1)%4-(y)%4));
	return a;
}
int ch(int a[]) {
	int r=0;
	for(int i=0; i<16; i++)
		if(a[i])
			r+=chr(a[i],i);
	return r;
}

int idas(int zp,int lst,int a[],int dp,int st,int h) {
	if(h==0) {
		end=true;
		return st;
	}
	if(st+h>dp)
		return st+h;
	int r=99999999;
	for(int i=0; !end && i<4; i++) {
		int nzp=zp+walk[i];
		if(nzp!=lst && ((zp%4+1+walk[i]%4)%5)*((zp/4+1+walk[i]/4)%5)>0) {
			swap(a[zp],a[nzp]);
			r=min(r,idas(zp+walk[i],zp,a,dp,st+1,h-chr(a[zp],nzp)+chr(a[zp],zp)));
			swap(a[zp],a[nzp]);
		}
	}
	return r;
}


int sa(int a[]) {
	int zp,i;
	int dp;
	int ans=0;
	int h=ch(a);
	end=false;
	for(i=0; i<16; i++)
		if(a[i]==0)
			zp=i;
	while(!end) {
		dp=ans;
		ans=idas(zp,-1,a,dp,0,h);
	}
	return ans;
}


int main () {
	int i,a[20];
	for(i=0;i<16;i++)
		scanf("%d",a+i);
	int wow=0;
	end=false;
	for(i=0;i<15;i++)
		for(int j=i+1;j<16;j++)
			if(a[i] && a[j] && a[i]>a[j])
				wow++;
	for(i=0;i<16;i++){
		if(a[i]==0){
			wow+=i/4+1;
			break;
		}
	}
	if(wow%2)
		puts("-1");
	else
		printf("%d\n",sa(a));
}
