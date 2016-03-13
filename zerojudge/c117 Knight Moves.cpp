#include<iostream>
#include<string>
#include<algorithm>
#include<queue>
using namespace std;
struct asd{
	int x, y,s;
	asd(int x,int y,int s):x(x) ,y(y), s(s){}
}k=asd(0,0,0),e=asd(0,0,0),l=asd(0,0,0);
int main(){
	char bx,by,ex,ey;
	int mx[8]={2,2,1,1,-1,-1,-2,-2},my[8]={-1,1,-2,2,-2,2,-1,1};
	int epx,epy,a,o,p,i,s;
	while(cin>>bx>>by>>ex>>ey){
		queue <asd> q;
		if(bx==ex && by==ey)
			cout<<"To get from "<<bx<<by<<" to "<<ex<<ey<<" takes 0 knight moves.\n";
		else{
			a=0;
			e.x=ex-'a';
			e.y=ey-'1';
			e.s=0;
			k=asd(bx-'a',by-'1',0);
			q.push(k);
			while(e.s==0 && !q.empty()){
				l=q.front();
				q.pop();
				for(i=0;i<8;i++){
					k=l;
					o=k.x+mx[i];
					p=k.y+my[i];
					s=k.s;
					if(o<0 || o>7 || p<0 || p>7)
						continue;
					if(o==e.x && p==e.y){
						e.s=s+1;
						break;
					}
					k=asd(o,p,s+1);
					q.push(k);
				}
			}
			cout<<"To get from "<<bx<<by<<" to "<<ex<<ey<<" takes "<<e.s<<" knight moves.\n"<<endl;
		}
	}
}
