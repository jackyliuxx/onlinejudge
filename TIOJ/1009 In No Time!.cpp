#include <cstdio>
using namespace std;

int main () {
	int bh,bm,bs,eh,em,es,ans;
	scanf("%d:%d:%d",&bh,&bm,&bs);
	scanf("%d:%d:%d",&eh,&em,&es);
	ans=(eh*3600+em*60+es)-(bh*3600+bm*60+bs);
	if(ans<0)
		ans+=86400;
	printf("%02d:%02d:%02d\n",ans/3600,(ans/60)%60,ans%60);
}
