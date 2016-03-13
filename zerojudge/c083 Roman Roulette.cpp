#include<iostream>
using namespace std;
int main(){
	int p[101];
	int n,k,i,w,n2,ans,r;
	while(cin>>n>>k,n+k){
		for(i=0;i<n;i++)
			p[i]=i+1;
		n2=n;
		w=-1;
		while(n2>1){
			if(w>n2-1)
				w=-1;
			w+=k;
			w%=n2;
			for(i=w;i<n2-1;i++)
				p[i]=p[i+1];
			r=p[(w-1+k)%(n2-1)];
			for(i=(w-1+k)%(n2-1);i<n2-1;i++)
				p[i]=p[i+1];
			if((w-1+k)%(n2-1)<w)
				w--;
			for(i=n2-1;i>w;i--)
				p[i]=p[i-1];
			p[w]=r;
			n2--;
		}
		ans=n+1-(p[0]-1);
		if(ans>n)
			ans-=n;
		cout<<ans<<endl;
	}
}