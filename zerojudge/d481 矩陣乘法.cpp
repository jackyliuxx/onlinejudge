#include<iostream>
using namespace std;
int main(){
	long long x[100][100],y[100][100],z[100][100],a,b,c,d,i,j,k;
	while(cin>>a>>b>>c>>d){
		if(b==c){
			for(i=0;i<100;i++)
				for(j=0;j<100;j++)
						x[i][j]=y[i][j]=z[i][j]=0;
			for(i=0;i<a;i++)
				for(j=0;j<b;j++)
					cin>>x[i][j];
			for(i=0;i<c;i++)
				for(j=0;j<d;j++)
					cin>>y[i][j];
			for(i=0;i<a;i++)
				for(j=0;j<d;j++)
					for(k=0;k<b;k++)
						z[i][j]+=x[i][k]*y[k][j];
			for(i=0;i<a;i++){
				for(j=0;j<d;j++)
					cout<<z[i][j]<<' ';
				cout<<endl;
			}
		}
		else
			cout<<"Error\n";
	}
}