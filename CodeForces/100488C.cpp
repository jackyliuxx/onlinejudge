#include<bits/stdc++.h>
using namespace std;

int main(){
    long long k;
    while(cin>>k){
        vector<long long> v;
        for(long long i=1;i*i<=k;i++){
            if(k%i==0){
                v.push_back(i);
                if(i*i<k)
                    v.push_back(k/i);
            }
        }
        sort(v.begin(),v.end());
        set<long long> ss;
        vector<pair<long long,long long> > ans;
        for(int i=0;i<(int)v.size();i++){
            for(int j=i;j<(int)v.size();j++){
                if(v[i]*v[j]>k)
                    break;
                if(ss.find(v[i]*v[j])==ss.end())
                    ss.insert(v[i]*v[j]);
                else
                    continue;
                long long a = v[i]*v[j],b=k*k/(v[i]*v[j])+k;
                ans.push_back({a+k,b});
                if(a+k!=b)
                ans.push_back({b,a+k});
            }
        }
        printf("%d\n",(int)ans.size());
        for(auto i:ans)
            printf("%I64d %I64d\n",i.first,i.second);
    }
}
