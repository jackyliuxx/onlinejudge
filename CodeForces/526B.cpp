#include<bits/stdc++.h>
using namespace std;

int gg(int x,int &ans,int lt[],int nn,int n){
    if(nn==n)
        return lt[x];
    int aa = gg(x*2,ans,lt,nn+1,n);
    int bb = gg(x*2+1,ans,lt,nn+1,n);
    ans+=abs(aa-bb);
    return max(aa,bb)+lt[x];
}

int main(){
    int n;
    cin>>n;
    int lt[4096];
    int p=1;
    for(int i=1;i<=n+1;i++)
        p*=2;
    p--;
    for(int i=2;i<=p;i++)
        cin>>lt[i];
    int ans=0;
    lt[1]=0;
    gg(1,ans,lt,0,n);
    cout<<ans<<endl;
}
