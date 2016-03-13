#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct asd{int q,s;} e,f;
int main(){
	int n,u,v,s,d,t,r,g[100],h[100][100],i,j,h1,h2,k,step1,step2,st,ans;
	cin>>t;
	while(t--){
		for(i=0;i<100;i++)
			g[i]=0;
		for(i=0;i<100;i++)
			for(j=0;j<100;j++)
				h[i][j]=0;
		cin>>n>>r;
		while(r--){
			cin>>h1>>h2;
			h[h1][h2]++;
			h[h2][h1]++;
		}
		cin>>s>>d;
		for(k=0;k<n;k++){
			e.q=s;
			e.s=0;
			st=1;
			step1=step2=0;
			queue<asd> q1,q2;
			q1.push(e);
			while(st){
					f=q1.front();
					q1.pop();
				for(i=0;i<n;i++){
					if(h[f.q][i] && i==k){
						st=0;
						step1=f.s+1;
						break;
					}
					if(h[f.q][i]==0)
						continue;
					f.q=i;
					f.s=f.s+1;
					q1.push(f);
				}
			}
			e.q=k;
			e.s=0;
			st=1;
			while(st){
					f=q2.front();
					q2.pop();
				for(i=0;i<n;i++){
					if(h[f.q][i] && i==d){
						st=0;
						step2=f.s+1;
						break;
					}
					if(h[f.q][i]==0)
						continue;
					f.q=i;
					f.s=f.s+1;
					q1.push(f);
				}
			}
			g[k]=step1+step2;
		}
		ans=0;
		for(i=0;i<n;i++)
			ans=max(ans,g[i]);
		cout<<ans<<endl;
	}
}