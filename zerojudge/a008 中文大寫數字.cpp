#include<iostream>
#include<string>
using namespace std;
int main(){
	string s[10]={"�s","��","�L","��","�v","��","��","�m","��","�h"},p[10]={"","�B","��","�a","�U","�B","��","�a","��","�B"};
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
						cout<<"�s";
					else if(n[i])
						cout<<s[n[i]]<<p[9-i];
					else if((n[0]!=0 || n[1]!=0) && i==1)
						cout<<"��";
					else if((n[3]!=0 || n[4]!=0 || n[5]!=0 || n[2]!=0 )&&i==5)
						cout<<"�U";
				}
				else if((n[0]!=0 || n[1]!=0) && i==1)
						cout<<"��";
				else if((n[3]!=0 || n[4]!=0 || n[5]!=0 || n[2]!=0 )&&i==5)
						cout<<"�U";
				nl-=n[i];
			}
			cout<<endl;
		}
}