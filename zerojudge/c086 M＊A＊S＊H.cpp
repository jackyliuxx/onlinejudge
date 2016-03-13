#include<iostream>
using namespace std;
int main(){
	int n,m,a[20],i,j,z=1,p[51],w,n2;
	while(cin>>n>>m){
		for(i=0;i<20;i++)
			cin>>a[i];
		cout<<"Selection #"<<z++<<endl;
		for(i=0;i<=n;i++)
			p[i]=i;
		n2=n;
		for(i=0;i<20;i++){
			w=a[i];
			while(w<=n2){
				for(j=w;j<=n2;j++)
					p[j]=p[j+1];
				n2--;
				w--;
				w+=a[i];
				if(n2==m)
					break;
			}
			if(n2==m)
				break;
		}
		for(i=1;i<=m;i++){
			cout<<p[i]<<' ';
		}
		cout<<"\n\n";
	}
}