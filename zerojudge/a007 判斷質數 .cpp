#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <time.h>
using namespace std;

#define MAXN 65536
vector<int> prims;
bool np[MAXN+1];
void findprims(){
	memset(np,0,sizeof(np));
	prims.push_back(2);
	for(int i=3;i<=MAXN;i+=2){
		if(!np[i])
			prims.push_back(i);
		for(int j=1;j<prims.size() && i*prims[j]<=MAXN;j++){
			np[i*prims[j]]=true;
			if(i%prims[j]==0)
				break;
		}
	}
}

int main () {
	findprims();
	printf("%d\n",clock());
	int n,i;
	while(~scanf("%d",&n)) {
		for(i=0; prims[i]*prims[i]<=n && i<prims.size()-1 && n%prims[i]; i++);
		puts( n%prims[i] || n==prims[i] ? "質數" : "非質數" );
	}
}
