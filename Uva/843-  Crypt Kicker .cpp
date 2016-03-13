#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int main(){
	int n,i,b[27]={},a[27]={},j,k=1,c[27]={},p,q,i2;
	char w[1010][20],s[100],w2[1010][20],a2[27]={},d[27],f[27],j2;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%s",w[i]);
		for(j=0;j<strlen(w[i]);j++)
			if(a[w[i][j]-'a']==0){
				a[w[i][j]-'a']=k;
				a2[k]=w[i][j];
				k++;
			}
			strcpy(w2[i],w[i]);
			for(j=0;j<strlen(w2[i]);j++)
				w2[i][j]=a[w2[i][j]-'a'];
	}
	gets(s);
	while(gets(s)){
		for(i=0;i<strlen(s);i++){
			if(s[i]==' ' || s[i]=='\n')
				printf("%c",s[i]);
			else{
				char s2[16]={};
				int l=0;
				while(i<strlen(s) && s[i]!=' ')
					s2[l++]=s[i++];
				for(j=0;j<strlen(s2);j++)
					if(b[s2[j]-'a']!=0)
						s2[j]=b[s2[j]-'a'];
				for(j=0;j<n;j++){
					char ccc,cccc;
					q=0;
					if(strlen(s2)==strlen(w2[j])){
						strcpy(d,s2);
						strcpy(f,w[j]);
						for(i2=0,ccc='A';i2<strlen(d);i2++,ccc++){
							if(d[i2]>'Z' || d[i2]<'A'){
								cccc=d[i2];
								for(j2=i2;j2<strlen(d);j2++)
									if(d[j2]==cccc)
										d[j2]=ccc;
							}
						}
						for(i2=0,ccc='A';i2<strlen(f);i2++,ccc++){
							if(f[i2]>'Z' || f[i2]<'A'){
								cccc=f[i2];
								for(j2=i2;j2<strlen(f);j2++)
									if(f[j2]==cccc)
										f[j2]=ccc;
							}
						}
						if(strcmp(d,f)==0){
							p=1;
							for(k=0;p==1 && k<strlen(s2);k++){
								if((s2[k]>26 && c[w2[j][k]]==1) || (s2[k]<=26 && s2[k]!=w2[j][k])){
									p=0;
									break;
								}
							}
							if(p){
								for(k=0;k<strlen(s2);k++){
									if(s2[k]>26){
										b[s2[k]-'a']=w2[j][k];
										c[w2[j][k]]=1;
										s2[k]=w2[j][k];
									}
								}
								q=1;
								break;
							}
						}
					}
				}
				if(q)
					for(j=0;j<strlen(s2);j++)
						printf("%c",a2[s2[j]]);
				else
					for(j=0;j<strlen(s2);j++)
						printf("%c",'*');
				i--;
			}
		}
		printf("\n");
	}
}