#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,k;
    int de[5100];
    scanf("%d%d",&n,&k);
    set<int> st;
    for(int i=0;i<n;i++){
        scanf("%d",de+i);
        st.insert(de[i]);
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int x;
        scanf("%d",&x);
        if(x==0){
            puts("0");
            continue;
        }
        int ans = k+1;
        for(int i=0;i<n;i++){
            for(int j=0;j<=k;j++){
                for(int j2=1;j2<=k;j2++){
                    int pp=(x-de[i]*j);
                    if(pp%j2==0 && st.find(pp/j2)!=st.end())
                        ans = min(ans, j+j2);
                }
            }
        }
        printf("%d\n",ans<=k ? ans : -1);
    }
}

