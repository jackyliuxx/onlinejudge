#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    char p[120];
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    for(int i=1;i<n;i++){
        for(int j=0;j+4*i<n;j++){
            if(p[j]!='*')
                continue;
            int ac=1;
            for(int k=1;k<=4;k++){
                if(p[j+k*i]!='*'){
                    ac=0;
                    break;
                }
            }
            if(ac){
                puts("yes");
                return 0;
            }
        }
    }
    puts("no");
}
