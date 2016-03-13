#include<iostream>
using namespace std;
int main(){
	int n,m,s1,s2,s3,s4,s5,s6,ma;
	cin>>n;
	while(n--){
		cin>>m;
		ma=0;
		while(m--){
			cin>>s1>>s2>>s3>>s4>>s5>>s6;
			if(s6>ma)
				ma=s6;
		}
		cout<<ma<<endl;
	}
}