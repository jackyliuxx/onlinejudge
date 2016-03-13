#include<bits/stdc++.h>
using namespace std;

struct pp{
    int w,h;
    bool operator<(pp b)const{
        if( h-w == b.h-b.w)
            return h > b.h;
        else
            return w-h > b.w-b.h;
    }
};

int main(){
    int n;
    pp p[1100];
    scanf("%d",&n);
    int nww=0;
    int hh[2200];
    for(int i=0;i<n;i++){
        scanf("%d%d",&p[i].w,&p[i].h);
        nww+=p[i].w;
        hh[i*2]=p[i].w;
        hh[i*2+1]=p[i].h;
    }
    sort(p,p+n);
    int ans = 2147483647;
    for(int i=0;i<2*n;i++){
        int nh = hh[i],nw=nww;
        int nr = 0;
        bool hr[1100]={};
        for(int j=0;j<n;j++){
            if(p[j].h > nh && p[j].w > nh){
                nr=n;
                break;
            }
            if(p[j].h > nh){
                hr[j]=true;
                nw+=p[j].h-p[j].w;
                nr++;
            }
        }
        if(nr>n/2)
            continue;
        for(int j=0;j<n && nr<n/2;j++){
            if(hr[j])
                continue;
            if(p[j].w > p[j].h && nh >= p[j].w){
                nr++;
                nw+=p[j].h-p[j].w;
            }
        }
        ans = min(ans,nh*nw);
    }
    printf("%d\n",ans);
}
