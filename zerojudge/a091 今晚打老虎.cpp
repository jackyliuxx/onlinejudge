#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

int level(int np) {
	int i=0,v=1;
	while(np>=v)
		v<<=1,i++;
	return i;
}

int kp(int np,int *heap,int p,int bos){
	if((np<<1)+1<p && (bos ? heap[np]<heap[(np<<1)+1] : heap[np]>heap[(np<<1)+1]))
		swap(heap[np],heap[(np<<1)+1]);
	if((np<<1)<p && (bos ? heap[np]<heap[np<<1] : heap[np]>heap[np<<1]))
		swap(heap[np],heap[np<<1]);
	return 0;
}


int insert(int n,int *heap,int &p) {
	int np=p,lnpf;
	heap[p]=n;
	p++;
	lnpf=level(np>>1);
	if( lnpf>0 && ( lnpf%2 ? n<heap[np>>1] : n>heap[np>>1] )) {
		swap(heap[np],heap[np>>1]);
		np>>=1;
		lnpf--;
	}
	lnpf--;
	while( lnpf>0 && ( lnpf%2 ? n<heap[np>>2] : n>heap[np>>2] )) {
		swap(heap[np],heap[np>>2]);
		np>>=2;
		lnpf-=2;
	}
	return 0;
}

int hmax(int *heap,int &p) {
	int np;
	if(p<4)
		np=p-1;
	else
		np=( heap[2]<heap[3] ? 3 : 2 );
	printf("%d\n",heap[np]);
	swap(heap[np],heap[p-1]);
	p--;
	kp(np,heap,p,1);
	while((np<<2)<p) {
		int snp=(np<<2);
		for(int i=1; i<4 && (np<<2)+i < p; i++)
			if(heap[snp]<heap[(np<<2)+i])
				snp=(np<<2)+i;
		if(heap[np]<heap[snp]) {
			swap(heap[np],heap[snp]);
			np=snp;
		}
		else
			break;
		kp(np,heap,p,1);
	}
	return 0;
}

int hmin(int *heap,int &p) {
	int np=1;
	printf("%d\n",heap[np]);
	swap(heap[np],heap[p-1]);
	p--;
	kp(np,heap,p,0);
	while((np<<2)<p) {
		int snp=(np<<2);
		for(int i=1; i<4 && (np<<2)+i < p; i++)
			if(heap[snp]>heap[(np<<2)+i])
				snp=(np<<2)+i;
		if(heap[np]>heap[snp]) {
			swap(heap[np],heap[snp]);
			np=snp;
		}
		else
			break;
		kp(np,heap,p,0);
	}
	return 0;
}

int main () {
	static int heap[1001000];
	int order,n,p=1;
	while(scanf("%d",&order)!=EOF) {
		switch(order) {
		case 1:
			scanf("%d",&n);
			insert(n,heap,p);
			break;
		case 2:
			hmax(heap,p);
			break;
		case 3:
			hmin(heap,p);
			break;
		}
	}
}
