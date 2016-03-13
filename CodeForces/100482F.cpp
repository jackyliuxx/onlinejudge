#include<bits/stdc++.h>
using namespace std;

int act[30][4]={};

int play(int r,int ata,int dfa,int atb,int dfb,int hpa,int hpb){
	int rt=0;
	if(act[r][3] && hpb-max(ata-dfb,0)<=0)
		return r+1;
	if(r>12)
		return 0;
	int tp[4]={};
	//	if(hpa<10 && act[r][0]>0)
	tp[0]=play(r+1,atb,dfb,ata,dfa,hpb,min(10,hpa+act[r][0]));
	if(act[r][1]>ata)
		tp[1]=play(r+1,atb,dfb,act[r][1],dfa,hpb,hpa);
	if(act[r][2]>dfa)
		tp[2]=play(r+1,atb,dfb,ata,act[r][2],hpb,hpa);
	if(act[r][3] && ata-dfb>0)
		tp[3]=play(r+1,atb,dfb,ata,dfa,hpb-(ata-dfb),hpa);
	for(int i=0;i<4;i++){
		if(tp[i]<0){
			if(rt>=0)
				rt=tp[i];
			else
				rt=max(rt,tp[i]);
		}
		else if(rt>=0)
			rt=max(rt,tp[i]);
	}
	return -rt;
}



int main(){
	int t,tk=1;
	cin>>t;
	while(t--){
		memset(act,0,sizeof(act));
		char s[10];
		for(int i=0;i<20;i++){
			scanf("%s",s);
			int x,k=((i%10)<5? 0 : (i%10)-4);
			k=k*2+i/10;
			if(!strcmp(s,"Heal")){
				scanf("%d",&x);
				act[k][0]=max(act[k][0],x);
			}
			if(!strcmp(s,"Atk")){
				scanf("%d",&x);
				act[k][1]=max(act[k][1],x);
			}
			if(!strcmp(s,"Def")){
				scanf("%d",&x);
				act[k][2]=max(act[k][2],x);
			}
			if(!strcmp(s,"HIT!"))
				act[k][3]=1;
		}
		for(int i=2;i<20;i++)
			for(int j=0;j<4;j++)
				act[i][j]=max(act[i][j],act[i-2][j]);
/*
		puts("***");
		for(int i=0;i<20;i++){
			for(int j=0;j<4;j++)
				printf("%d ",act[i][j]);
			puts("");
		}
*/
		int ans=play(0,0,0,0,0,10,10);
		printf("Case #%d: %s %d\n",tk++,(ans>0 ? "win" : "lose"),abs(ans));
	}
}
