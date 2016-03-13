#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;

int main () {
    int x,y;
    long long i;
    static unsigned long long b[1001000],w[1001000];
    w[0]=b[0]=0;
    for(i=1;i<=1000000;i++)
        w[i]=w[i-1]+i,b[i]=b[i-1]+i*i;
    while(scanf("%d%d",&x,&y),x!=0 || y!=0){
        if(x>y)
            swap(x,y);
        printf("%lld\n",b[x]+w[x]*(y-x));
    }
}
