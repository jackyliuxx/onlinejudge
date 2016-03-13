#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

inline bool isiwant(char c){
	if(c>='0' && c<='9')
		return true;
	if(c=='(' || c==')')
		return true;
	if(c=='-')
		return true;
	return false;
}

int readin(char *s){
	int sk=-1,i;
	char c;
	while(sk==-1)
		if((c=getchar())=='(')
			sk=1;
	s[0]=c;
	for(i=1;sk!=0;){
		c=getchar();
		if(isiwant(c)){
			if(c=='(')
				sk++;
			if(c==')')
				sk--;
			s[i++]=c;
		}
	}
	s[i]=0;
	return i;
}

int readint(char *s,int &t){
	int i;
	t=0;
	for(s[0]=='-' ? i=1 : i=0;s[i]>='0' && s[i]<='9';i++)
		t=t*10+s[i]-'0';
	if(s[0]=='-')
		t=-t;
	return i;
}


void tt(char *s,int bg,int ed,int cc,int n,bool &stp){
	int t,i;
	if(ed-bg<=1)
		return;
	bg+=readint(s+bg,t);
	if(ed-bg>4){
		int sk=0;
		for(i=bg;i<ed;i++){
			if(s[i]=='(')
				sk++;
			if(s[i]==')')
				sk--;
			if(sk==0){
				tt(s,bg+1,i,cc+t,n,stp);
				if(!stp)
					tt(s,i+2,ed-1,cc+t,n,stp);
				break;
			}
		}
	}
	else if(cc+t==n){
			stp=true;
			return;
	}
}


int main(){
	int n;
	bool stp;
	static char s[1000000];
	while(scanf("%d",&n)!=EOF){
		stp=false;
		int sl=readin(s);
		tt(s,1,sl-1,0,n,stp);
		if(stp)
			puts("yes");
		else
			puts("no");
	}
}