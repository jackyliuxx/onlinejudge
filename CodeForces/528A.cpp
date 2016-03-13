#include<bits/stdc++.h>
using namespace std;
int main(){
	int w,h,n;
	scanf("%d%d%d",&w,&h,&n);
	priority_queue<int> hq,hq2,wq,wq2;
	map<int,int> hm,wm;	
	hm[0] = 1,hm[h] = 1;
	wm[0] = 1,wm[w] = 1;
	hq.push(h);
	wq.push(w);
	while(n--){
		char c[10];
		int x;
		scanf("%s%d",c,&x);
		if(c[0]=='H'){
			hm[x]=1;
			auto t = hm.find(x);
			int f=(--t)->first;
			++t;
			++t;
			int f2=t->first;
			hq2.push(f2-f);
			hq.push(x-f);
			hq.push(f2-x);
		}
		if(c[0]=='V'){
			wm[x]=1;
			auto t = wm.find(x);
			int f=(--t)->first;
			++t;
			++t;
			int f2=t->first;
			wq2.push(f2-f);
			wq.push(x-f);
			wq.push(f2-x);
		}
		while(hq2.size() && hq2.top() == hq.top()){
			hq2.pop();
			hq.pop();
		}
		while(wq2.size() && wq2.top() == wq.top()){
			wq2.pop();
			wq.pop();
		}
		printf("%I64d\n",1ll*hq.top()*wq.top());	
	}
}
