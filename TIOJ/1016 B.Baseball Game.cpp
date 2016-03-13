#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
#define allclear asc=bsc=bg=out=b[0]=b[1]=b[2]=b[3]=0
#define pclear out=b[0]=b[1]=b[2]=b[3]=0
#define bclear b[0]=b[1]=b[2]=0
using namespace std;

int main () {
	char c;
	int asc,bsc,bg,out,b[4],i;
	allclear;
	while((c=getchar())!=EOF){
		switch(c){
		case '\n' :
			printf("%d %d\n",asc,bsc);
			allclear;
			break;
		case 'K' :
		case 'O' :
			out++;
			break;
		case 'W' :
			b[0]++;
			for(i=0;i<3 && b[i]>1;i++)
				b[i+1]++,b[i]--;
			break;
		case 'S' :
			b[3]+=b[2];
			b[2]=b[1];
			b[1]=b[0];
			b[0]=1;
			break;
		case 'D' :
			b[3]+=b[2]+b[1];
			b[2]=b[0];
			b[1]=1;
			b[0]=0;
			break;
		case 'T' :
			b[3]+=b[2]+b[1]+b[0];
			b[2]=1;
			b[1]=b[0]=0;
			break;
		case 'H' :
			b[3]+=b[2]+b[1]+b[0]+1;
			bclear;
			break;
		}
		if(out==3){
			(bg ? bsc : asc)+=b[3];
			pclear;
			bg^=1;
		}
	}
}
