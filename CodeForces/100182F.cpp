#include<bits/stdc++.h>
using namespace std;

struct wtf{
	int id,h;
	wtf(){}
	wtf(int _id,int _h):id(_id),h(_h){}
	bool operator<(wtf w2)const{
		return h<w2.h;
	}
};

int main(){
	int n,d,h[1100],p[1100],pr[1100],nx[1100];
	wtf ts2[1100];
	while(cin>>n>>d,n||d){
		int mn=9999999,mnid,mx=-1,mxid;
		for(int i=0;i<n;i++){
			cin>>h[i];
			if(h[i]<mn){
				mn=h[i];
				mnid=i;
			}
			if(h[i]>mx){
				mx=h[i];
				mxid=i;
			}
		}
		if(mnid>mxid)
			reverse(h,h+n);
		for(int i=0;i<n;i++)
			ts2[i]=wtf(i,h[i]);
		sort(ts2,ts2+n);
		for(int i=0;i<n;i++){
			if(i==0)
				pr[ts2[i].id]=ts2[i].id;
			else
				pr[ts2[i].id]=ts2[i-1].id;
			if(i==n-1)
				nx[ts2[i].id]=ts2[i].id;
			else
				nx[ts2[i].id]=ts2[i+1].id;
		}
		for(int i=0;i<n;i++)
			p[i]=i;
		bool hsans=true;
		for(int i=n-1;i>=0 && hsans;i--){
			int tp=min(p[pr[i]],min(p[nx[i]],p[i]));
			if(p[i]-tp>d)
				hsans=false;
		}
		if(!hsans){
			puts("-1");
			continue;
		}
		for(int j=ts2[0].id+1;j<n;j++){
			p[j]=1023456789;
			for(int i=0;i<j;i++)
				if(i==pr[j] || i==nx[j])
					p[j]=min(p[j],p[i]+d);
			for(int i=j-1;i>ts2[0].id;i--){
				if(p[i]>=p[i+1])
					p[i]=p[i+1]-1;
			}
		}
/*
		puts("***");
		for(int i=0;i<n;i++)
			printf("%d ",p[i]);
		puts("***");
*/
		printf("%d\n",p[ts2[n-1].id]-p[ts2[0].id]);
	}
}
