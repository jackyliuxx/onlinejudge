#include<iostream>
#include<string>
using namespace std;
int a[5001][5001]={};
int main(){
	int n,i,j;
	string s1,s2;
	cin>>n;
	while(n--){
		cin>>s1;
		s2="";
		for(i=s1.size()-1;i>=0;i--)
			s2+=s1[i];
		for(i=0;i<5001;i++)
			a[0][i]=a[i][0]=0;
		for(i=0;i<s1.size();i++){
			for(j=0;j<s2.size();j++){
				if(s1[i]==s2[j])
					a[i+1][j+1]=a[i][j]+1;
				else
					a[i+1][j+1]=max(a[i][j+1],a[i+1][j]);
			}
		}
		cout<<a[i][j]<<endl;
	}
}