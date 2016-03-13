//by jackyliuxx
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
#include "interactive/118.h"
using namespace std;

int tmp[120],n;
int ans[120],hmt=0;
/*
int Init(){
	int i;
	for(i=1;i<=n;i++)
		ans[i]=i;
	return 100;
}

int Answer(int a[]){
	int i,crr=0;
	hmt++;
	for(i=1;i<=n;i++)
		if(ans[i]==a[i])
			crr++;
	return crr;
}
*/
int tkp(int x,int fr,int to){
	int i;
	for(i=1;i<=n;i++){
		if(i>=fr && i<=(fr+to)/2)
			tmp[i]=x;
		else
			tmp[i]=0;
	}
	if(Answer(tmp)){
		if(to-fr<2)
			return fr;
		else
			return tkp(x,fr,(fr+to)/2);
	}
	else{
		if(to-fr<2)
			return to;
		else
			return tkp(x,(fr+to)/2+1,to);
	}
}


int main () {
	int a[120]={};
	n=Init();
	int i;
	for(i=1;i<n;i++){
		a[tkp(i,1,n)]=i;
	}
	for(i=1;i<=n;i++)
		if(a[i]==0)
			a[i]=n;
	Answer(a);
//	printf("%d",hmt);
}
