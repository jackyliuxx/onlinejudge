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

vector<int> m[1001000];
int nn,p,k;

int sm(int n,int f,int dp,int &lt) {
	int r=-100,mr=-100,nr=1000000;
	int i;
	for(i=0; i<m[n].size(); i++) {
		if(m[n][i]!=f) {
			r=sm(m[n][i],n,dp,lt);
			if(nr>r)
				nr=r;
			if(mr<r)
				mr=r;
		}
	}
	if(r==-100)
		return dp+1;
	if(nr==0 ? mr+1<=2*dp : mr+nr<=2*dp)
		return nr+1;
	if(mr==2*dp) {
		lt--;
		return 0;
	}
	return mr+1;
}


bool tryans(int dp) {
	int lt=k;
	if(sm(1,0,dp,lt)>dp)
		lt--;
	if(lt>=0)
		return true;
	return false;
}


inline int &in( int &n ) {
	char c = getchar();
	while( ( c > '9' || c < '0' ) && c + 1 ) c = getchar();
	for( n = 0; c >= '0' && c <= '9' ; c = getchar() ) ( n *= 10 ) += c - '0';
	return n;
}

/*
int readint( int &n ) {
	char c;
	int pp=1;
	n=0;
	while((c=getchar())!=EOF)
		if(c=='-' || (c>='0' && c<='9'))
			break;
	if(c=='-')
		pp=-1;
	else
		n=c-'0';
	while((c=getchar())!=EOF && c>='0' && c<='9')
		n=n*10+c-'0';
	return n;
}
*/
/*
int main(){
	scanf("%d",&nn);
	int i;
	int x,y;
	for(i=0;i<=nn;i++)
		m[i].clear();
	for(i=0;i<nn;i++){
		in(x);
		in(y);
		m[x].push_back(y);
		m[y].push_back(x);
	}
	int dp,lt;
	while(scanf("%d",&dp)!=EOF){
		lt=0;
		if(sm(1,0,dp,lt)>dp)
			lt--;
		printf("%d\n",-lt);
	}
}
*/

int main () {
	scanf("%d%d%d",&nn,&p,&k);
	int i;
	for(i=0; i<=nn; i++)
		m[i].clear();
	int x,y;
	for(i=0; i<p; i++) {
		in(x);
		in(y);
		//readint(x);
		//readint(y);
		m[x].push_back(y);
		m[y].push_back(x);
	}
	if(nn==k){
		puts("0");
		return 0;
	}
	int ans,up=nn/(k+1)+2,lw=0;
	while(up-lw>1) {
		ans=(lw+up)/2;
		if(tryans(ans))
			up=ans;
		else
			lw=ans;
	}
	printf("%d\n",up);
}

