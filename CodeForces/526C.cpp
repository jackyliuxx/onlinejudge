#include<bits/stdc++.h>
using namespace std;
int main(){
    long long c,h1,h2,w1,w2;
    cin>>c>>h1>>h2>>w1>>w2;
    if( w1*w1<c && (1.0*h1/w1 > 1.0*h2/w2 || w2*w2>=c))
        swap(h1,h2),swap(w1,w2);
    long long ans = 0;
    for(long long i=0;i*w1<= c && i*i<=c;i++)
        ans = max(ans,i*h1+(c-i*w1)/w2*h2);
    cout<<ans<<endl;
}
