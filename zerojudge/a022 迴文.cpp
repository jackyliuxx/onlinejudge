#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	int n,i;
	while(cin>>s){
		n=0;
		for(i=0;int(s.size()-i-1)>=i;i++)
			if(s[i]!=s[s.size()-i-1])
				n++;
		cout<<(n ?"no":"yes")<<endl;
	}
}