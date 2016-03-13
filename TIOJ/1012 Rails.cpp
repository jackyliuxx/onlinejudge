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
using namespace std;

bool trytry(int n,int m,int end[]){
	int np=1,ap=0,i,j,a[1100];
	for(i=0;i<n;i++){
		while(np<=end[i])
			a[ap++]=np++;
		int f=1;
		for(j=1;j<=m+1 && ap-j>=0;j++){
			if(a[ap-j]==end[i]){
				f=0;
				for(int k=ap-j;k<ap-1;k++)
					a[k]=a[k+1];
				ap--;
				break;
			}
		}
		if(f)
			return false;
	}
	return true;
}

int main () {
	int n,m,end[1100];
	while(cin>>n>>m){
		int i;
		for(i=0;i<n;i++)
			cin>>end[i];
		puts( trytry(n,m,end) ? "yes" : "no" );
	}
}
