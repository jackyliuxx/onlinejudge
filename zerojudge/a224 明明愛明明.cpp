#include<iostream>
#include<string>
using namespace std;
int main(){
	string s,d;
	int i,a[26],j;
	while(cin>>s){
		j=0;
		for(i=0;i<26;i++)
			a[i]=0;
		d="";
		for(i=0;i<s.size();i++){
			if(s[i]>='a' && s[i]<='z')
				d+=s[i]-'a';
			if(s[i]>='A' && s[i]<='Z')
				d+=s[i]-'A';
		}
		for(i=0;i<d.size();i++)
			a[d[i]-1]++;
		for(i=0;i<26;i++)
			j+=a[i]%2;
		if(d.size()%2 && j==1)
			cout<<"yes !\n";
		else if(j==0)
			cout<<"yes !\n";
		else
			cout<<"no...\n";
	}
}