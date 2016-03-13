#include<iostream>
#include<string>
using namespace std;
int main(){
	string s[10]={"箂","滁","禠","把","竩","ヮ","嘲","琺","","╤"},p[10]={"","珺","ㄕ","","窾","珺","ㄕ","","货","珺"};
	int n[10],i,na,nl;
		while(cin>>n[0]){
			for(i=9; i>=0 ;i--){
				n[i]= n[0]%10;
				if(i!=0)
					n[0]=n[0]/10;
			}
			na=0;
			nl=0;
			for(i=0; i<10 ;i++)
				nl+=n[i];
			for(i=0; i<10 ;i++){
				na+=n[i];
				if(na!=0 && nl!=0){
					if(n[i]==0 &&  n[i+1])
						cout<<"箂";
					else if(n[i])
						cout<<s[n[i]]<<p[9-i];
					else if((n[0]!=0 || n[1]!=0) && i==1)
						cout<<"货";
					else if((n[3]!=0 || n[4]!=0 || n[5]!=0 || n[2]!=0 )&&i==5)
						cout<<"窾";
				}
				else if((n[0]!=0 || n[1]!=0) && i==1)
						cout<<"货";
				else if((n[3]!=0 || n[4]!=0 || n[5]!=0 || n[2]!=0 )&&i==5)
						cout<<"窾";
				nl-=n[i];
			}
			cout<<endl;
		}
}