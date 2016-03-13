#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b,c;
    scanf("%d%d%d",&a,&b,&c);
    if(a>b)
        swap(a,b);
    int change = 0;
    if(c>=a && c<=b)
        change = 1;
    if(change)
        puts("Take another envelope");
    else
        puts("Stay with this envelope");
}
