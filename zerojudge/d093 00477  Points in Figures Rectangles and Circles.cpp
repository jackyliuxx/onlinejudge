#include<iostream>
#include<cstdio>
using namespace std;
int main(){
	int i,k;
	double a[12][5];
	char c;
	for(k=0;cin>>c;k++){
		if(c=='r'){
			a[k][0]=0;
			cin>>a[k][1]>>a[k][2]>>a[k][3]>>a[k][4];
		}
		else if(c=='c'){
			a[k][0]=1;
			cin>>a[k][1]>>a[k][2]>>a[k][3];
		}else if(c=='*')
			break;
	}
	double x,y;
	int yaaa,l=0;
	while(cin>>x>>y,x!=9999.9 && y!=9999.9){
		l++;
		yaaa=0;
		for(i=0;i<k;i++){
			if(a[i][0]==0)
				if(x>a[i][1] && y<a[i][2] && x<a[i][3] && y>a[i][4])
					cout<<"Point "<<l<<" is contained in figure "<<i+1<<endl,yaaa=1;
			if(a[i][0]==1)
				if((x-a[i][1])*(x-a[i][1]) + (y-a[i][2])*(y-a[i][2]) < a[i][3]*a[i][3])
					cout<<"Point "<<l<<" is contained in figure "<<i+1<<endl,yaaa=1;
		}
		if(yaaa==0)
			cout<<"Point "<<l<<" is not contained in any figure"<<endl;
	}
}