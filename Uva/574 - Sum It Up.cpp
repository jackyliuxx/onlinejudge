#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

vector< vector<int> > vsort(vector< vector<int> > x){
	int i,j,k;
	for(i=0;i<x.size()-1;i++){
		for(j=i;j<x.size()-1;j++){
			for(k=0;k<min(x[j].size(),x[j+1].size());k++){
				if(x[j][k]<x[j+1][k])
					x[j].swap(x[j+1]);
				if(x[j][k]!=x[j+1][k])
					break;
			}
		}
	}
	return x;
}

int main () {
	vector<int> newa;
	vector< vector<int> > a[1300];
	int i,j,t,n,num[1010],m,k,l;
	while(cin>>t>>n,n) {
		for(i=0; i<1010; i++)
			num[i]=0;
		for(i=0; i<n; i++) {
			cin>>m;
			num[m]++;
		}
		for(i=0; i<1300; i++)
			a[i].clear();
		newa.clear();
		a[0].push_back(newa);
		for(i=1000; i>=0; i--) {
			if(num[i]>0) {
				for(j=1200-i; j>=0; j--) {
					if( a[j].size() > 0 ) {
						for(k=1; k<=num[i]; k++) {
							for(l=0; l<a[j].size(); l++) {
								a[j+k*i].push_back(a[j][l]);
								for(m=0; m<k; m++)
									a[j+k*i][a[j+k*i].size()-1].push_back(i);
							}
						}
					}
				}
			}
		}
		printf("Sums of %d:\n",t);
		if( a[t].size()==0)
			printf("NONE\n");
		else {
			a[t]=vsort(a[t]);
			for(i=0; i< a[t].size(); i++) {
				for(j=0; j<a[t][i].size(); j++) {
					if(j)
						printf("+");
					printf("%d",a[t][i][j]);
				}
				printf("\n");
			}
		}
	}
}
