#include<iostream>
#include<string>
using namespace std;
int main(){
	int ans,k,p,b[10000]={};
	char a[10000],m;
	string s,s2;
	while(getline(cin,s)){
		p=0;
		s2="";
		for(k=0;k<s.size();k++){
			if(s[k]>='0' && s[k]<='9'){
				while(k<s.size() && s[k]>='0' && s[k]<='9')
					s2+=s[k++];
				k--;
				s2+=' ';
			}
			if(s[k]=='(')
				a[p++]=s[k];
			else if(s[k]=='+' || s[k]=='-'){
				while(--p>=0){
					if(a[p]!='('){
						s2+=a[p];
						s2+=' ';
					}
					else
						break;
				}
				p++;
				a[p++]=s[k];
			}
			else if(s[k]=='*' || s[k]=='/' || s[k]=='%'){
				while(--p>=0){
					if(a[p]=='*' || a[p]=='/' || a[p]=='%'){
						s2+=a[p];
						s2+=' ';
					}
					else
						break;
				}
				p++;
				a[p++]=s[k];
			}
			else if(s[k]==')'){
				while(--p>=0){
					if(a[p]!='('){
						s2+=a[p];
						s2+=' ';
					}
					else{
						p--;
						break;
					}
				}
				p++;
			}
			k++;
		}
		while(--p>=0)
			s2+=a[p],s2+=' ';
		// Âà«á§Ç¹Bºâ
		p=0;
		for(k=0;k<s2.size();k+=2){
			if(s2[k]>='0' && s[k]<='9'){
				b[p]=0;
				while(k<s2.size() && s2[k]>='0' && s2[k]<='9')
					b[p]=b[p]*10+(s2[k]-'0'),k++;
				p++;
				k--;
			}
			if(s2[k]=='+'){
				b[p-2]=b[p-2]+b[p-1];
				p--;
			}
			if(s2[k]=='-'){
				b[p-2]=b[p-2]-b[p-1];
				p--;
			}
			if(s2[k]=='*'){
				b[p-2]=b[p-2]*b[p-1];
				p--;
			}
			if(s2[k]=='/'){
				b[p-2]=b[p-2]/b[p-1];
				p--;
			}
			if(s2[k]=='%'){
				b[p-2]=b[p-2]%b[p-1];
				p--;
			}
		}
		cout<<b[--p]<<endl;
	}
}