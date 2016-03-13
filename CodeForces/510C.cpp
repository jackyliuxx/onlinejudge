#include<bits/stdc++.h>
using namespace std;

int mp[30][30]={},rq[30]={};

void gd(char s[][200],int f,int t,int x){
	if(t-f<=1)
		return;
	int bg=0;
	for(int i=f;i<t;i++){
		if(s[i][x]==0 && bg==0){
			f=i+1;
			continue;
		}
		else if(s[i][x]==0 && bg){
			rq[0]+=99;
			return;
		}
		else if(s[i][x]!=0)
			bg=1;
	}
	if(t-f<=1)
		return;
	int i=f,ii=f;
	while(ii<t){
		for(i=ii;i<t && s[i][x]==s[ii][x];i++);
		int tp=i;
		for(;i<t;i++){
			mp[s[ii][x]-'a'][s[i][x]-'a']=1;
		}
		ii=tp;
	}
	int ff=f;
	for(i=f;i<t;i++){
		if(s[i][x]!=s[ff][x]){
			gd(s,ff,i,x+1);
			ff=i;
		}
	}
	gd(s,ff,t,x+1);
}


int main(){
	int n;
	char s[200][200]={};
	cin>>n;
	for(int i=0;i<n;i++)
		scanf("%s",s[i]);
	gd(s,0,n,0);
	for(int i=0;i<26;i++)
		for(int j=0;j<26;j++)
			if(mp[i][j])
				rq[j]++;
	queue<int> q;
	vector<int> ans;
	for(int i=0;i<26;i++)
		if(rq[i]==0)
			q.push(i);
	while(!q.empty()){
		int x=q.front();
		ans.push_back(x);
		q.pop();
		for(int i=0;i<26;i++){
			if(mp[x][i]){
				rq[i]--;
				if(rq[i]==0)
					q.push(i);
			}
		}
	}
	for(int i=0;i<26;i++){
		if(rq[i]){
			puts("Impossible");
			return 0;
		}
	}
	for(int i=0;i<ans.size();i++)
		putchar(ans[i]+'a');
	puts("");
}
