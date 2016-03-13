#include<iostream>
#include<string>
#include<algorithm>
#include<cmath>
using namespace std;
int main(){
	string s1,s2;
	int a[1001][1001];
	int i,j,k=0;
	while(getline(cin,s1)){
		k++;
		ws(cin);
		getline(cin,s2);
		for(i=0;i<101;i++)
			for(j=0;j<101;j++)
				a[i][j]=0;
		for(i=1;i<s1.size()+1;i++){
			for(j=1;j<s2.size()+1;j++){
				if(s1[i-1]==s2[j-1])
					a[j][i]=a[j-1][i-1]+1;
				else
					a[j][i]=max(a[j-1][i],a[j][i-1]);
			}
		}
		cout<<a[j-1][i-1]<<endl;
	}
}

